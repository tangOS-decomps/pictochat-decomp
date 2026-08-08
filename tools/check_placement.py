"""Enforce the src/ layout that the build and the counters actually read.

Everything under src/ lives in exactly two places: src/arm9/ and src/arm7/.
configure.py walks only those two dirs, progress.py globs only those two, and
ledger.py banks only into those two (src_path: module "arm7" -> arm7, every
other module including the autoloads -> arm9). A file anywhere else under src/
is never compiled, never linked, and never counted -- but pr_linkcheck resolves
its target from the `// decomp:` header rather than the path, so it still
byte-verifies and the PR check goes green. Six driver PRs landed flat src/*.c
files that way on 2026-08-07 (#83 #91 #94 #99 #104 and a sibling of #82) before
a human caught the paths. This gate makes CI catch them instead.

Checks, in order:

  1. STRUCTURE -- no files directly under src/, no subdirs other than arm7 and
     arm9, no nesting below them. Anything else is invisible to the build.
  2. MARKER    -- every .c/.cpp carries at least one `// decomp: module=...
     addr=... name=...` line (ledger.py stamps one per banked function;
     consolidated class files carry several, and the marker can sit behind a
     //cpp directive or an extern "C" block, so the whole file is searched,
     same as ledger.MARKER_RE). Every marker's module must agree with the dir
     the file sits in: module=arm7 belongs in src/arm7/, everything else
     belongs in src/arm9/ (mirrors ledger.src_path). A file in the wrong dir
     compiles with the wrong -proc and can still byte-match by luck on
     Thumb-common encodings; placement is not cosmetic.
  3. COLLISION -- a .c and a .cpp sharing a stem in the same dir both map to
     build/<cpu>/<stem>.o, which breaks ninja outright (seen on #90).

Exit 0 with no output on a clean tree; exit 1 listing every violation. Run from
the repo root (CI) or anywhere inside the repo (it walks up to find src/).
"""
import pathlib
import re
import sys

MARKER_RE = re.compile(
    r"^// decomp: module=(\S+) addr=0x[0-9a-fA-F]+ name=\S+\s*$", re.M)
ALLOWED_DIRS = {"arm7", "arm9"}


def find_src(start):
    for d in [start] + list(start.parents):
        if (d / "src").is_dir() and (d / "configure.py").is_file():
            return d / "src"
    sys.exit("check_placement: no repo root (src/ + configure.py) above " + str(start))


def marker_modules(path):
    """Every module= named by a decomp marker in the file (a consolidated
    class file legitimately carries one marker per function), searched over
    the whole text exactly like ledger.MARKER_RE / sync_ledger do."""
    try:
        text = path.read_text(encoding="utf-8")
    except (OSError, UnicodeDecodeError) as e:
        return None, f"unreadable: {e}"
    modules = MARKER_RE.findall(text)
    if not modules:
        return None, "no `// decomp: module=...` marker anywhere in the file"
    return sorted(set(modules)), None


def check(src):
    problems = []

    for p in sorted(src.iterdir()):
        if p.is_file():
            problems.append(f"{p.relative_to(src.parent)}: flat file directly under src/ "
                            "-- never compiled or counted; move it into src/arm9/ or "
                            "src/arm7/ per its module= header")
        elif p.is_dir() and p.name not in ALLOWED_DIRS:
            problems.append(f"{p.relative_to(src.parent)}/: unknown dir under src/ "
                            "-- only arm7/ and arm9/ are built")

    for sub in sorted(ALLOWED_DIRS):
        d = src / sub
        if not d.is_dir():
            continue
        stems = {}
        for p in sorted(d.iterdir()):
            rel = p.relative_to(src.parent)
            if p.is_dir():
                problems.append(f"{rel}/: nested dir -- configure.py does not recurse")
                continue
            if p.suffix not in (".c", ".cpp"):
                continue
            stems.setdefault(p.stem, []).append(p.name)
            modules, err = marker_modules(p)
            if err:
                problems.append(f"{rel}: {err}")
                continue
            for module in modules:
                want = "arm7" if module == "arm7" else "arm9"
                if want != sub:
                    problems.append(f"{rel}: marker says module={module}, which banks to "
                                    f"src/{want}/ (ledger.src_path) -- wrong dir, wrong -proc")
        for stem, names in sorted(stems.items()):
            if len(names) > 1:
                problems.append(f"src/{sub}/{{{', '.join(sorted(names))}}}: same stem maps "
                                f"both to build/{sub}/{stem}.o -- ninja cannot build this")

    return problems


def main():
    src = find_src(pathlib.Path.cwd().resolve())
    problems = check(src)
    for p in problems:
        print(p)
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
