# Nintendo DS Firmware / PictoChat Decompilation (ndsDecomp)

A from-scratch decompilation (decomp) of **PictoChat**, targeting the
standalone DSi system title (`assets/pictochat.nds`), into matching C.
Started as an attempt to decompile PictoChat directly out of the original DS
firmware chip; that investigation is preserved as real, verified work (see
[notes/firmware-investigation.md](notes/firmware-investigation.md)) but is no
longer the critical path, once a genuine, unencrypted copy of PictoChat
turned up as a DSi system utility.

## Status

<!-- progress:start -->
**146 / 1551 functions matched (9.4%)**  `[#-------------------]`
2750 / 167020 bytes (1.6%)
<!-- progress:end -->

(regenerate with `python tools/progress.py --write-readme`; needs a local
`extracted/` - see Setup below. The total is Ghidra's current function count,
not a precise figure - see [notes/pictochat-layout.md](notes/pictochat-layout.md).)

See [CONTRIBUTING.md](CONTRIBUTING.md) for the matching workflow and
[notes/tooling.md](notes/tooling.md) for the tooling that helps with it.

## What "matching" means

The goal is source code that, when compiled with the original toolchain,
produces a binary byte-for-byte identical to the real PictoChat binary. This
is the same standard `sm64ds-decomp` and the wider decomp community hold to.
Every matched function is checked against the real binary with
`tools/match.py`, so the source is known to be correct, not just plausible.

## Legal and scope

This repo contains only original work: the tooling, the hand-written C, and
the notes. It contains no firmware dump, no ROM, and no extracted Nintendo
assets - those are read locally from your own dumps and are git-ignored.
Never commit anything derived from `assets/`. `assets/pictochat.nds` has to
be dumped from your own Nintendo DSi - see
[notes/dumping-pictochat.md](notes/dumping-pictochat.md).

## Setup

You supply your own PictoChat title and ARM7 BIOS dump (both git-ignored
under `assets/pictochat.nds` and `assets/bios7.bin` - see
[notes/dumping-pictochat.md](notes/dumping-pictochat.md); no firmware dump
needed unless you're picking up the separate, parked firmware investigation).
This repo already has a verified `mwccarm` toolchain checked out
(see [notes/setup-mwccarm.md](notes/setup-mwccarm.md) - no Discord round-trip
needed unless you're starting fresh on a new machine).

```
pip install ndspy capstone pyelftools pyghidra
python tools/extract_pictochat.py    # -> extracted/ (git-ignored)
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for the full matching workflow and
[notes/tooling.md](notes/tooling.md) for the free-match tools, `m2c`, and
decomp-permuter setup (`pip install toml pcpp pycparser`, plus
`git clone https://github.com/matt-kempster/m2c vendor/m2c` and
`git clone https://github.com/simonlindholm/decomp-permuter vendor/decomp-permuter` -
both optional, `vendor/` is git-ignored).

## Project layout

```
assets/            your own dumps: pictochat.nds + bios7.bin required, firmware.bin/bios9.bin only for the parked firmware investigation - gitignored
extracted/         unpacked binaries, derived from assets/ - gitignored
ghidra_project/    Ghidra analysis database - gitignored, see notes/ghidra-setup.md
vendor/            cloned third-party tools (m2c, decomp-permuter) - gitignored, see notes/tooling.md
src/arm9/ src/arm7/  matched C, one function per file - THE actual deliverable
tools/             extraction, matching, free-match, and permuter-bridge tooling
notes/             setup docs, the memory-layout writeup, the tooling reference
config/            per-module symbol/relocation config (dsd-format; see notes/pictochat-layout.md)
progress/          local match ledger (gitignored - see tools/ledger.py)
CLAIMS.md          how to avoid duplicating another contributor's work
```

## How matching works

Compile a candidate with `mwccarm`, then compare the result to PictoChat's
real binary byte-for-byte, relocation-aware (`tools/match.py`). Nothing
counts as matched until that check passes.

The compiler flags follow `sm64ds-decomp`'s for the same compiler family:

```
-O4,p -enum int -lang c99 -char signed -interworking -proc arm946e -gccext,on -msgstyle gcc
```

but the **version** is a different story: `sm64ds-decomp` pinned `1.2/sp2p3`
for a 2004 NTR-SDK game. PictoChat is a DSi system title (DSi launched
Nov 2008/Apr 2009), so `tools/match.py` instead defaults to `dsi/1.3` - the
`tools/mwccarm/dsi/` builds self-identify as "Freescale C/C++ for Embedded
ARM" (Freescale acquired Metrowerks' CodeWarrior division in 2005) with 2009
copyright dates, a much better fit for a DSi launch-window title. See
[notes/setup-mwccarm.md](notes/setup-mwccarm.md) for the full reasoning.
**Neither pin is verified yet** - once a handful of functions are matched,
sweep versions (`tools/match.py --all`) and pin whichever one actually
produces byte-identical output.

## PictoChat's real layout

PictoChat's ARM9 side isn't one flat binary - it's a tiny crt0 stub plus a
separate ~300KB application module loaded to a different RAM address, plus a
couple of small extras. Read
[notes/pictochat-layout.md](notes/pictochat-layout.md) before assuming an
address maps where you'd expect.

## Credits

Toolchain and conventions adapted from
[tangosdev/sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp) - same
compiler family, same matching standard, same overall shape of project. The
`dsd` toolkit is [AetiasHax/ds-decomp](https://github.com/AetiasHax/ds-decomp).
KEY1 encryption details are from GBATEK
(https://problemkaputt.de/gbatek.htm) and cross-checked against the real
`bios7.bin` disassembly from
[PikalaxALT/ndsbios](https://github.com/PikalaxALT/ndsbios).

## License

The original work in this repo (the C, the tooling, the notes) is released
under the MIT License, see [LICENSE](LICENSE). This applies only to that
original work and grants no rights to any Nintendo material, which is not
present here.
