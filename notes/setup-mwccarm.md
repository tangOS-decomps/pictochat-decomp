# mwccarm (already set up in this repo)

Unlike `sm64ds-decomp` (which needs you to fetch `mwccarm.zip` by hand from
the DS-decompilation Discord), this repo already has a working, verified
compiler toolchain checked out under `tools/mwccarm/` (gitignored - it's
proprietary, not redistributable, so it isn't committed, but it's already
extracted on this machine).

## What's there

```
tools/mwccarm/1.2/{base,sp2,sp2p3,sp3,sp4}/mwccarm.exe
tools/mwccarm/2.0/{base,sp1,sp1p2,sp1p5,sp1p6,sp1p7,sp2,sp2p2,sp2p3,sp2p4}/mwccarm.exe
tools/mwccarm/dsi/{1.1,1.1p1,1.2,1.2p1,1.2p2,1.3,1.3p1,1.6sp1,1.6sp2}/mwccarm.exe
tools/mwccarm/2004/b56/mwccarm.exe   # experimental, archive.org-recovered - see below
tools/mwccarm/license.dat
```

Verified working: `1.2/sp2p3` launches cleanly and reports
`Metrowerks C/C++ for Embedded ARM ... Version 2.0 build 82` under the
project's `license.dat`. This is the version `sm64ds-decomp` settled on as
canonical for Super Mario 64 DS (byte-identical to `1.2/base` and `1.2/sp2`
across their whole probe corpus) - **but PictoChat is a DSi system title, not
a 2004 NTR-SDK game, so that pin almost certainly does not apply here.**

The `tools/mwccarm/dsi/` builds are the real starting hypothesis. All launch
cleanly and self-identify as **"Freescale C/C++ for Embedded ARM"**
(Metrowerks' CodeWarrior division was acquired by Freescale in 2005):

| version    | copyright |
|------------|-----------|
| `dsi/1.1`  | 2007      |
| `dsi/1.2`  | 2009      |
| `dsi/1.3`  | 2009      |
| `dsi/1.6sp1` | 2009    |
| `dsi/1.6sp2` | 2009    |

The DSi launched November 2008 (Japan) / April 2009 (Americas/Europe), so a
2009-dated build fits a launch-window built-in title like PictoChat better
than the 2007 one - `tools/match.py`'s `CANONICAL` defaults to `dsi/1.3` on
that basis.

**Confirmed**, not just a guess: the first real match
(`src/arm7/FUN_022c8268.c`, a trivial byte-store setter) landed byte-identical
on `dsi/1.3` with the default flags. That's one data point, not a full pin -
keep sweeping (`tools/match.py --all` or `--trio`) as more functions get
matched, in case a nearby service pack turns out to be the more precise
version for most of the codebase - but `dsi/1.3` is a real, working starting
point now, not just a hypothesis.

One flag correction the first match surfaced: **`-thumb` is required.**
Without it, `mwccarm` defaults to ARM-mode output even for tiny functions the
real binary has as Thumb (confirmed by a size mismatch: 8 bytes of ARM-mode
`strb`+`bx` vs. the real 4 bytes of Thumb). `tools/match.py`'s
`DEFAULT_FLAGS`/`DEFAULT_FLAGS_ARM7` now include it. Not every function will
necessarily be Thumb (hot paths are sometimes compiled `-noThumb` even in a
mostly-Thumb codebase) - if an otherwise-correct-looking candidate comes out
the wrong size, try toggling it with `--flags`.

The `2004/b56` build is a separate, experimental recovery (see
`tools/recover_cw2004.py`'s docstring for the archive.org range-fetch
technique). Earlier notes here said it did not launch
(`STATUS_INVALID_IMAGE_FORMAT`) - **re-verified 2026-08-04, it launches fine**
(`mwccarm.exe -version` reports `Metrowerks C/C++ for Embedded ARM ...
Version 2.0 build 56`), so whatever DLL mismatch caused that is no longer an
issue on this machine. It's included in `--all`/`--trio` sweeps for real, not
silently no-op'd.

**Is the vendored build set complete?** Checked 2026-08-04 by reading the 7z
header of the archive.org-preserved Metrowerks FTP mirror
(`archive.org/details/ftp_metrowerks_updates.7z`, see
`tools/recover_cw2004.py`'s technique) and, more relevantly, the file list of
`archive.org/details/cw_consoles` - a separately-preserved, dated mirror of
Nintendo's own official DSi CodeWarrior distribution channel. Its `DSi/`
folder has exactly nine builds, one-to-one with what's vendored here:
`cw_dsi-1_1-20081209.zip` + `-patch1-20090525` (= `1.1`/`1.1p1`),
`cw_dsi-1_2-20091006.zip` + `-patch1-20091027` + `-patch2-20100121` (=
`1.2`/`1.2p1`/`1.2p2`), `cw_dsi-1_3-20100413.zip` + `-patch1-20100615` (=
`1.3`/`1.3p1`), `cw_dsi-1_6-sp1-20110929.zip`, `cw_dsi-1_6-sp2-20120312.zip`.
No `1.4`, `1.5`, or plain `1.6` exists in that archive - the version-number
gap is how Nintendo itself numbered these SDK releases, not a hole in this
project's toolchain set. The Metrowerks FTP mirror's own `CWARM/` folder
(the pre-Freescale-acquisition public line) tops out at `CW_ARM_2.1.1_Update.exe`
(Oct 2004, already recovered as `2004/b56`) - nothing there is more recent or
DSi-relevant than what's already vendored either. **Conclusion: for anyone
chasing a hard residual and wondering "is this actually a different,
unvendored compiler build" - it almost certainly is not.** The full known
universe of DSi-era CodeWarrior builds is already in `tools/mwccarm/`.

## If you need to re-set-up on a fresh machine

Same as `sm64ds-decomp`: get `mwccarm.zip` from the DS-decompilation Discord
(https://discord.com/invite/gwN6M3HQrA, resources channel) and extract to
`tools/mwccarm/`. `license.dat` is the standard community FlexLM unlock file
used across DS decomp projects for this otherwise-unobtainable-without-a-
Nintendo-devkit compiler; ask in the same Discord if you don't have a copy.
