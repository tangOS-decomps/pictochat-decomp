"""Local decomp.me-style viewer: C editor + real ROM disassembly + compiled
candidate disassembly, side by side, with a diff and a compiler/flags picker.

Why: iterating on a hard function today means editing a .c file, re-running
match.py/fdiff.py in a terminal, and reading a text diff by eye. This serves
the same underlying compile-and-diff loop (reuses tools/match.py directly - no
separate codepath to drift out of sync) as a local web page so the candidate,
the real bytes, and the diff are all visible at once, and picking a different
compiler version/flags/opt level is a dropdown instead of retyping a command.

Usage:
    python tools/webviewer.py            # serves on http://127.0.0.1:8765
    python tools/webviewer.py --port 9000

Nothing here is a build step or a persistent service - it's a local dev tool.
Ctrl+C to stop. Saving a candidate (the "Save" button) writes straight back to
its file on disk under scratch/ only (never src/ - promoting a draft to a real
match still goes through the normal banking process, not this tool).
"""
import argparse
import difflib
import http.server
import json
import pathlib
import re
import socketserver
import sys
import tempfile
import urllib.parse

REPO = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))
import match as M       # noqa: E402
import funcs as F        # noqa: E402

DECOMP_RE = re.compile(r"^//\s*decomp:\s*module=(\S+)\s+addr=(0x[0-9a-fA-F]+)\s+name=(\S+)", re.M)
NONMATCHING_RE = re.compile(r"NONMATCHING", re.I)


def _funcs_by_addr():
    """(module, addr) -> ghidra func record, built once per process."""
    if not hasattr(_funcs_by_addr, "_cache"):
        idx = {}
        for f in F.load_funcs():
            if f["module"]:
                idx[(f["module"], f["addr"])] = f
        _funcs_by_addr._cache = idx
    return _funcs_by_addr._cache


def list_candidates():
    """Every source file (scratch/*.c(pp), plus parked NONMATCHING files under
    src/) that carries a `// decomp:` marker, grouped by (module, addr, name).
    Each group lists every file found for it, newest mtime first, so a
    function iterated on across several scratch drafts shows all of them."""
    groups = {}
    search_dirs = [REPO / "scratch"] + list((REPO / "src").glob("*"))
    for d in search_dirs:
        if not d.is_dir():
            continue
        for ext in ("*.c", "*.cpp"):
            for p in d.rglob(ext):
                try:
                    text = p.read_text(encoding="utf-8", errors="ignore")
                except OSError:
                    continue
                m = DECOMP_RE.search(text)
                if not m:
                    continue
                module, addr_s, name = m.group(1), m.group(2), m.group(3)
                if module not in M.MODULES:
                    continue
                addr = int(addr_s, 0)
                key = (module, addr, name)
                is_nonmatching = bool(NONMATCHING_RE.search(text))
                is_scratch = d == (REPO / "scratch") or (REPO / "scratch") in p.parents
                rel = str(p.relative_to(REPO)).replace("\\", "/")
                entry = groups.setdefault(key, {
                    "module": module, "addr": addr, "addr_hex": hex(addr), "name": name,
                    "files": [],
                })
                entry["files"].append({
                    "path": rel,
                    "mtime": p.stat().st_mtime,
                    "editable": is_scratch,
                    "nonmatching": is_nonmatching,
                })
    ghidra = _funcs_by_addr()
    out = []
    for (module, addr, name), entry in groups.items():
        entry["files"].sort(key=lambda f: -f["mtime"])
        g = ghidra.get((module, addr))
        entry["ghidra_size"] = g["size"] if g else None
        out.append(entry)
    out.sort(key=lambda e: (e["module"], e["addr"]))
    return out


PCREL = re.compile(r"\[pc,\s*#-?(?:0x[0-9a-fA-F]+|[0-9]+)\]")
REG = re.compile(r"\b(?:r(?:1[0-2]|[0-9])|fp|ip|sb|sl|lr)\b")


def _shape(mnemonic, op_str):
    if mnemonic.startswith("b"):
        return mnemonic
    op = PCREL.sub("[pc]", op_str.replace(" ", ""))
    op = REG.sub("r", op)
    return mnemonic + " " + op


def decode_stream(data: bytes):
    """[(offset, raw, text, shape, is_data), ...]. Falls back to 4-byte-word
    ".word" pseudo-instructions once capstone can't decode any more (a
    literal pool / relocation slot), instead of silently truncating, so pool
    words are visible in the viewer instead of just vanishing."""
    out = []
    off = 0
    n = len(data)
    while off < n:
        chunk = data[off:off + 4]
        insn = next(M.md.disasm(chunk, 0), None) if len(chunk) == 4 else None
        if insn is not None and insn.size == len(chunk):
            text = f"{insn.mnemonic} {insn.op_str}".strip()
            out.append((off, chunk, text, _shape(insn.mnemonic, insn.op_str), False))
            off += insn.size
        else:
            out.append((off, chunk, f".word 0x{chunk[::-1].hex()}", f"<data:{len(out)}>", True))
            off += len(chunk)
    return out


def build_rows(target: bytes, cand: bytes, relocs: set):
    t = decode_stream(target)
    c = decode_stream(cand)
    t_shapes = [x[3] for x in t]
    c_shapes = [x[3] for x in c]
    sm = difflib.SequenceMatcher(a=t_shapes, b=c_shapes, autojunk=False)
    rows = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            ti = i1 + k if i1 + k < i2 else None
            ci = j1 + k if j1 + k < j2 else None
            trow = crow = None
            status = "diff"
            if ti is not None:
                toff, traw, ttext, _, tdata = t[ti]
                trow = {"offset": toff, "hex": traw.hex(), "text": ttext, "data": tdata}
            if ci is not None:
                coff, craw, ctext, _, cdata = c[ci]
                crow = {"offset": coff, "hex": craw.hex(), "text": ctext, "data": cdata}
            if tag == "equal" and ti is not None and ci is not None:
                is_reloc = crow["offset"] in relocs
                if is_reloc:
                    status = "reloc"
                elif trow["hex"] == crow["hex"]:
                    status = "match"
                else:
                    status = "color"  # same shape, different bytes (regalloc/coloring)
            rows.append({"target": trow, "candidate": crow, "status": status})
    return rows


def extract_func_fuzzy(obj: bytes, func: str):
    """M.extract_func() requires an exact symbol name, which breaks the moment
    a draft declares the target as a C++ member function (or anything else
    that gets mangled) - the compiled symbol is `_ZN...12FUN_xxxxxxxxEj...`,
    not the plain name, even though it's still obviously the right function.
    Fall back to scanning every STT_FUNC symbol for one whose mangled name
    CONTAINS `func` as a substring - Itanium mangling always embeds the
    original spelled-out identifier length-prefixed, so this is reliable
    without needing a real demangler. Returns (code, relocs, reloc_info,
    resolved_name) or (None, None, None, None); also returns the list of
    candidate names tried, for a useful error message when it's ambiguous.
    """
    code, relocs, reloc_info = M.extract_func(obj, func)
    if code is not None:
        return code, relocs, reloc_info, func, []
    import io
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(io.BytesIO(obj))
    symtab = elf.get_section_by_name(".symtab")
    if symtab is None:
        return None, None, None, None, []
    candidates = [s.name for s in symtab.iter_symbols()
                  if s["st_info"]["type"] == "STT_FUNC" and s["st_size"] > 0 and func in s.name]
    if not candidates:
        return None, None, None, None, []
    # shortest match wins - the plain member-function mangling
    # (_ZN<class><len><name>Ej...) is shorter than any nested/templated variant
    best = min(candidates, key=len)
    code, relocs, reloc_info = M.extract_func(obj, best)
    return code, relocs, reloc_info, best, candidates


def do_compile(payload: dict) -> dict:
    source = payload["source"]
    func = payload["func"]
    module = payload["module"]
    addr = int(payload["addr"], 0) if isinstance(payload["addr"], str) else payload["addr"]
    version = payload.get("version") or M.CANONICAL
    is_cpp = source.lstrip().startswith("//cpp")
    ext = ".cpp" if is_cpp else ".c"

    base_flags = payload.get("flags") or (M.DEFAULT_FLAGS_ARM7 if module == "arm7" else M.DEFAULT_FLAGS)
    user_supplied_flags = bool(payload.get("flags"))
    flags = M.apply_flags_marker(base_flags, source, allow_thumb_heuristic=not user_supplied_flags)

    with tempfile.NamedTemporaryFile(suffix=ext, mode="w", delete=False, encoding="utf-8") as f:
        f.write(source)
        tmp_path = pathlib.Path(f.name)
    try:
        obj = M.compile_c(tmp_path, version, flags)
    finally:
        tmp_path.unlink(missing_ok=True)

    if obj is None:
        return {"ok": False, "error": f"compile failed ({version}) - check the C compiles "
                                       f"under mwccarm at all; flags used: {flags}"}

    code, relocs, reloc_info, resolved_name, other_candidates = extract_func_fuzzy(obj, func)
    if code is None:
        return {"ok": False, "error": f"symbol '{func}' not found in the compiled object, "
                                       f"including as a substring of a mangled C++ name - "
                                       f"check the function name matches exactly"}
    mangled_note = None
    if resolved_name != func:
        mangled_note = f"'{func}' compiled to mangled symbol '{resolved_name}'" + (
            f" (also matched: {', '.join(n for n in other_candidates if n != resolved_name)})"
            if len(other_candidates) > 1 else "")

    target = M.target_bytes(module, addr, len(code))
    rows = build_rows(target, code, relocs)
    ndiff = sum(1 for r in rows if r["status"] not in ("match", "reloc"))
    is_thumb = "-thumb" in flags and "-noThumb" not in flags
    bad_relocs = [
        {"offset": off, "sym": sym, "want": want, "found": found}
        for off, sym, want, found, ok in M.verify_relocs(addr, target, reloc_info, is_thumb)
        if ok is False
    ]
    match_ok = ndiff == 0 and not bad_relocs

    ghidra = _funcs_by_addr().get((module, addr))
    return {
        "ok": True,
        "match": match_ok,
        "target_size": len(target),
        "candidate_size": len(code),
        "ghidra_size": ghidra["size"] if ghidra else None,
        "ndiff": ndiff,
        "total_words": len(target) // 4,
        "rows": rows,
        "bad_relocs": bad_relocs,
        "mangled_note": mangled_note,
        "flags_used": flags,
        "version_used": version,
        "is_cpp": is_cpp,
    }


class Handler(http.server.BaseHTTPRequestHandler):
    server_version = "ndsDecompViewer/1"

    def log_message(self, fmt, *args):
        pass  # keep the terminal quiet - errors still surface in API responses

    def _json(self, obj, status=200):
        body = json.dumps(obj).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def _text(self, text, status=200, content_type="text/plain; charset=utf-8"):
        body = text.encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def do_GET(self):
        parsed = urllib.parse.urlparse(self.path)
        qs = urllib.parse.parse_qs(parsed.query)
        try:
            if parsed.path == "/":
                html = (pathlib.Path(__file__).parent / "webviewer_static" / "index.html").read_text(encoding="utf-8")
                self._text(html, content_type="text/html; charset=utf-8")
            elif parsed.path == "/api/candidates":
                self._json(list_candidates())
            elif parsed.path == "/api/versions":
                self._json({"sweep": M.SWEEP, "canonical": M.CANONICAL})
            elif parsed.path == "/api/source":
                rel = qs.get("path", [""])[0]
                p = (REPO / rel).resolve()
                if REPO not in p.parents or not p.is_file():
                    self._json({"error": "invalid path"}, 400)
                    return
                self._json({"path": rel, "content": p.read_text(encoding="utf-8"),
                            "editable": (REPO / "scratch") in p.parents})
            elif parsed.path == "/api/target":
                module = qs.get("module", [""])[0]
                addr = int(qs.get("addr", ["0"])[0], 0)
                g = _funcs_by_addr().get((module, addr))
                if not g:
                    self._json({"error": "no ghidra record for this module/addr"}, 404)
                    return
                data = bytes.fromhex(g["bytes"])
                rows = [{"offset": o, "hex": raw.hex(), "text": t, "data": d}
                        for o, raw, t, _, d in decode_stream(data)]
                self._json({"size": len(data), "rows": rows, "name": g["name"]})
            else:
                self._json({"error": "not found"}, 404)
        except Exception as e:  # noqa: BLE001 - surface any failure to the browser, not just the console
            self._json({"error": f"{type(e).__name__}: {e}"}, 500)

    def do_POST(self):
        parsed = urllib.parse.urlparse(self.path)
        length = int(self.headers.get("Content-Length", 0))
        raw = self.rfile.read(length) if length else b"{}"
        try:
            payload = json.loads(raw.decode("utf-8"))
        except json.JSONDecodeError:
            self._json({"ok": False, "error": "bad JSON body"}, 400)
            return
        try:
            if parsed.path == "/api/compile":
                self._json(do_compile(payload))
            elif parsed.path == "/api/save":
                rel = payload.get("path", "")
                p = (REPO / rel).resolve()
                if REPO / "scratch" not in p.parents:
                    self._json({"ok": False, "error": "only files under scratch/ can be saved from the viewer"}, 400)
                    return
                p.parent.mkdir(parents=True, exist_ok=True)
                p.write_text(payload["content"], encoding="utf-8")
                self._json({"ok": True})
            else:
                self._json({"ok": False, "error": "not found"}, 404)
        except Exception as e:  # noqa: BLE001
            self._json({"ok": False, "error": f"{type(e).__name__}: {e}"}, 500)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--host", default="127.0.0.1")
    args = ap.parse_args()

    with socketserver.ThreadingTCPServer((args.host, args.port), Handler) as httpd:
        url = f"http://{args.host}:{args.port}/"
        print(f"ndsDecomp viewer running at {url}  (Ctrl+C to stop)")
        try:
            httpd.serve_forever()
        except KeyboardInterrupt:
            pass


if __name__ == "__main__":
    main()
