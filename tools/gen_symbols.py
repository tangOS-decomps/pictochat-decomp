"""Emit config/arm9/symbols.txt + config/arm7/symbols.txt from the local Ghidra
export, so the whole progress pipeline (tools/chaos_db_ci.py, the update-chaos-data
workflow, the tangos.dev card) can run ROM-free in CI.

This is the ONE step that needs a local extracted/pictochat_funcs.json - it distills
that Ghidra dump down to a function-boundary table (name, module, addr, size) and
drops the function BYTES, which are the only ROM-derived part. The result is the same
data class sm64ds-decomp commits as config/**/symbols.txt and the same class the repo
already publishes as unmatched-function context: boundaries and addresses, not content.

    python tools/gen_symbols.py            # write config/{arm9,arm7}/symbols.txt
    python tools/gen_symbols.py --check    # verify committed symbols match the export

Run it (or --check) whenever the Ghidra export changes, then commit the two files.
"""
import argparse
import pathlib
import sys

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"

sys.path.insert(0, str(REPO / "tools"))
import funcs as F  # noqa: E402

# ARM9 hosts four modules (main/itcm/unk_autoload_0/unk_autoload_2), ARM7 one; src/ is
# split by CPU, so the symbols files are too - one per CPU, module named per line.
CPUS = ("arm9", "arm7")


def render(cpu: str) -> str:
    """The committed symbols table for one CPU: one function per line, sorted by
    address, module carried per line since a CPU spans several modules."""
    rows = sorted(
        (f for f in F.load_funcs() if f["cpu"] == cpu and f.get("module")),
        key=lambda f: f["addr"],
    )
    lines = [
        "# name / module / addr / size for every Ghidra-known function on this CPU.",
        "# Boundaries only (no bytes); regenerate with tools/gen_symbols.py.",
    ]
    for f in rows:
        lines.append(
            f"name={f['name']} module={f['module']} "
            f"addr=0x{f['addr']:08x} size=0x{f['size']:x}"
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true",
                    help="exit non-zero if committed symbols differ from the export")
    args = ap.parse_args()

    if not F.FUNCS_CACHE.is_file():
        print(f"error: {F.FUNCS_CACHE} not found - run tools/extract_pictochat.py + the "
              f"Ghidra export first (see notes/ghidra-setup.md). This is the only step that "
              f"needs your local dump; everything downstream reads the committed symbols.txt.",
              file=sys.stderr)
        return 2

    rc = 0
    for cpu in CPUS:
        out = CONFIG / cpu / "symbols.txt"
        text = render(cpu)
        if args.check:
            have = out.read_text(encoding="utf-8") if out.is_file() else ""
            if have != text:
                print(f"STALE: {out.relative_to(REPO)} differs from the export "
                      f"(run tools/gen_symbols.py and commit)")
                rc = 1
            else:
                print(f"ok: {out.relative_to(REPO)}")
        else:
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_text(text, encoding="utf-8")
            n = sum(1 for line in text.splitlines() if line.startswith("name="))
            print(f"wrote {out.relative_to(REPO)} ({n} functions)")
    return rc


if __name__ == "__main__":
    raise SystemExit(main())
