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

### Narrowing: `2.0/base` is ruled out too, the pin is `2.0/sp1` or later

Verifying **all 189** banked matches against every `2.0/*` build narrows it
further. Five functions (`MultiStore_Int`, three `CP15` cache primitives, and
`FUN_023320f0`) match every `2.0/*` build **except `2.0/base`**, which emits
genuinely different code for them - `FUN_023320f0` compiles to 0x10 bytes
under `base` against the target's 0xc, a real codegen difference, not an asm
or size artifact.

The intersection that satisfies all 189 verified matches is therefore:

    2.0/sp1, 2.0/sp1p2, 2.0/sp1p5, 2.0/sp1p6, 2.0/sp1p7,
    2.0/sp2, 2.0/sp2p2, 2.0/sp2p3, 2.0/sp2p4

Those nine are indistinguishable from each other across the entire corpus, so
the family *and* the "sp1 or later" floor are pinned but the exact point
release is not. `CANONICAL` is **`2.0/sp1`**, the earliest build consistent
with every byte of evidence. If you ever find a function that discriminates
among those nine, narrow it further and update this section.

(`2.0/sp1p5`, `sp1p6` and `sp1p7` were missing from `SWEEP` entirely until
2026-08-04 and had never been tested by any sweep in this project's history.
They are included now - and they turned out to be in the answer set.)

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

## Provisioning the PR-validator build box

The validator (`.github/workflows/pr-validate.yml` -> a private relay -> a build
box that clones the repo and runs `tools/pr_linkcheck.py`) compiles every
changed `src/arm{7,9}/*.c|*.cpp` and byte-compares it. The compilers are
gitignored, so **the box needs its own copy of the pinned toolchain** - the
repo cannot ship it.

This bites when the pin changes. Moving the pin from `dsi/*` to `2.0/*` left
the box provisioned with only the `dsi/*` set, and because `match.py`'s
`compile_c()` returns `None` both for "not installed" and "your C is broken",
every PR touching a src file was told its source *failed to compile*.

**Check the box first - this is a one-liner, and it compiles a probe rather
than just looking for files:**

```
python tools/check_toolchain.py          # exit 0 = can validate; --json for CI
```

It reports, per pinned build, whether `mwccarm.exe` is present, whether its
support files are present, and whether a probe actually compiles; plus
`license.dat`, and (off Windows) whether `MWCCARM_LAUNCHER` is set and `wine`
is on PATH.

**To provision:**

1. Put the pinned build directories **outside the clone** and point
   `MWCCARM_DIR` at them. In-tree the compilers are untracked (gitignored), so
   a `git clean -xdf`, a re-checkout or a fresh clone deletes them silently and
   the next job reports a provisioning gap. Git cannot touch `/opt`:

   ```
   mkdir -p /opt/mwccarm
   cp -r <source>/tools/mwccarm/* /opt/mwccarm/
   # in the validator's environment, alongside MWCCARM_LAUNCHER:
   MWCCARM_DIR=/opt/mwccarm
   ```

   `match.py` reads `MWCCARM_DIR` and falls back to the in-tree
   `tools/mwccarm/` when it is unset, so dev machines need no change and this
   is a no-op for every existing caller. `check_toolchain.py` prints which of
   the two it resolved, so a misconfigured box is visible in one line.

   Either way the layout is the same:

   ```
   <toolchain dir>/2.0/sp1/     <- CANONICAL; the minimum needed to validate
   <toolchain dir>/2.0/sp1p2/   ... and the rest of match.py's PINNED list
   <toolchain dir>/license.dat  <- shared, one level up, not per-version
   ```

   Each version directory needs `mwccarm.exe` **plus** `ELFIO.dll`,
   `MSL_All-DLL80_x86.dll`, `lmgr8c.dll`, `mwasmarm.exe` and `mwldarm.exe`.
   `mwccarm.exe` alone fails at runtime with a DLL error that looks nothing
   like "not installed". ~3.6 MB per version, ~36 MB for the whole `2.0` tree.

   All nine pinned `2.0/*` builds are the same ones sm64ds-decomp already
   carries in its `tools/mwccarm/2.0/`, so provisioning is a copy from an
   existing checkout rather than a fresh hunt.

2. Non-Windows box: install Wine and set `MWCCARM_LAUNCHER=wine` in the
   validator's environment (`compile_c()` reads it and prefixes the command).

3. Re-run `python tools/check_toolchain.py` and expect exit 0.

**Minimum vs complete.** Only `2.0/sp1` (the `CANONICAL`) is strictly required
- `pr_linkcheck.py` sweeps `PINNED` and accepts a match from any installed
build, and all nine pinned builds are byte-equivalent across the entire banked
corpus. Installing all nine is still preferable so a local `--trio` sweep and
CI agree exactly. **Do not provision `2.0/base` alone**: it is deliberately
excluded from `PINNED` because five banked functions match every other `2.0/*`
build and not it, so a box holding only `base` would reach wrong verdicts.

## If you need to re-set-up on a fresh machine

Same as `sm64ds-decomp`: get `mwccarm.zip` from the DS-decompilation Discord
(https://discord.com/invite/gwN6M3HQrA, resources channel) and extract to
`tools/mwccarm/`. `license.dat` is the standard community FlexLM unlock file
used across DS decomp projects for this otherwise-unobtainable-without-a-
Nintendo-devkit compiler; ask in the same Discord if you don't have a copy.
