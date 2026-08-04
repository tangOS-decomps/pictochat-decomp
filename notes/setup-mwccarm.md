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

## THE TOOLCHAIN IS `2.0/*` (settled 2026-08-04 by byte evidence)

`tools/match.py`'s `CANONICAL` is **`2.0/base`**, and `PINNED` is the
`2.0/*` family. **Do not "fix" this back to `dsi/*`.** If you are here
because a candidate won't match under `2.0/*`, sweep `--all` and read the
evidence below before concluding the pin is wrong.

### Why this was previously (wrongly) pinned to `dsi/*`

The old pin was a *plausibility argument*, never a verified one: PictoChat is
a DSi system title, the `dsi/*` builds are DSi-era and self-identify as
"Freescale C/C++ for Embedded ARM" (Metrowerks' CodeWarrior division was
acquired by Freescale in 2005), the DSi launched Nov 2008 / Apr 2009, so a
2009-dated `dsi/1.3` "must" be it. The supporting "confirmation" was a trivial
byte-store setter that matched on `dsi/1.3` - a function so simple it compiles
identically on *every* vendored build, so it confirmed nothing.

That reasoning is invalid regardless of how apt the product name looks: **a
single ROM is built by ONE toolchain.** The question is settled by byte
evidence, not by which compiler was marketed for which console. Chasing a
per-function "this one used a different compiler" explanation is a sign of
rationalising a result rather than following it.

### The evidence

Of the entire banked corpus, exactly **four** functions discriminate between
the families. Everything else (156 functions) compiles byte-identically under
both and therefore votes for neither:

| function | `dsi/*` | `2.0/*` | note |
|---|---|---|---|
| `FUN_022ce658` | no | **yes** | structurally wrong under `dsi/*` |
| `FUN_022d3bd4` | no | **yes** | structurally wrong under `dsi/*` |
| `FUN_022d5a64` | no | **yes** | `dsi/*` cannot emit its frame shape at all |
| `FUN_022ce5b4` | yes | **yes** | needs `#pragma opt_strength_reduction off` under `2.0/*` |

`2.0/*` explains all four. `dsi/*` explains one and is *structurally
incapable* of three. Switching the pin is a strict improvement, verified by
recompiling the whole corpus both ways: **156 match under both, 3 match under
`2.0/*` only, 0 match under `dsi/*` only.** Nothing regressed.

`FUN_022ce5b4` is the one that superficially looked like counter-evidence: as
originally written it matched `dsi/*` and not `2.0/*`. The cause is that
`2.0/*` strength-reduces its loop index into a pointer induction variable
while the ROM re-derives `base + i` each iteration. `#pragma
opt_strength_reduction off` (one of the few pragmas mwccarm honours - see
`notes/mwccarm-codegen.md` and sm64ds-decomp 6e) reproduces the ROM shape, and
the file now carries it. Four natural loop rewrites were tried first and none
defeat the reduction. **A single function appearing to prefer the other family
is not evidence of a mixed toolchain - check whether an optimisation pragma
explains it first.**

All ten `2.0/*` builds behave identically on every discriminating function, so
the *family* is pinned but the point release is not; `2.0/base` is the
representative. (`2.0/sp1p5`, `sp1p6` and `sp1p7` were missing from `SWEEP`
entirely until 2026-08-04 and had never been tested - they are included now.)

### The older `1.2/*` line

`1.2/sp2p3` launches cleanly and reports `Metrowerks C/C++ for Embedded ARM
... Version 2.0 build 82`. This is the version `sm64ds-decomp` settled on as
canonical for Super Mario 64 DS. It is **not** this project's pin - the `1.2`
line is structurally wrong on this ROM's discriminating functions - but it is
kept in `--all` sweeps because it costs nothing.

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
