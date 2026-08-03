# mwccarm codegen notes

How mwccarm turns C into the exact ARM bytes in the PictoChat DSi ROM, and the specific
levers found so far for closing near-misses. This project's own compiler-behavior
knowledge base - separate from
[sm64ds-decomp's much larger version](../../sm64ds-decomp/notes/mwccarm-codegen.md)
(2400+ lines, thousands of matched functions), which is the primary external reference:
**read it before re-deriving a lever from scratch.** Most of what's below was found by
mining that file for applicable levers and testing them against this project's own
targets, not by independent discovery - credit and cross-reference accordingly.

Toolchain here: `dsi/1.3` is the pinned canonical version (see `tools/match.py`'s
`CANONICAL`), default flags `-O4,p -enum int -lang c99 -char signed -interworking
-thumb -proc arm7tdmi -gccext,on -msgstyle gcc` for arm7 (`DEFAULT_FLAGS_ARM7`), with
`-O4,s` as a documented, frequently-necessary alternate (`-O4,s` fixes duplicated
early-return epilogues that `-O4,p` doesn't - see notes/tooling.md's own section on
this). `tools/match.py --all` / `--versions` sweeps every vendored build
(`tools/mwccarm/{1.2,2.0,2004,dsi}/*`) if a version-selection issue is suspected.

## 1. Confirmed levers (found this project, 2026-08-02, cracking the `FUN_022ce8b0`
arm7 dispatcher callee cluster)

### 1a. Mask/narrowing-type lever: widen to `int`, not `unsigned short`

Mirrors sm64ds's section 6l ("named `u16` local forces the `and/lsl/lsrs` narrowing
triple over a single `ands`"). A masking computation whose real type is narrow
(`unsigned short mask = ~a0 & *(unsigned short*)(...)`) compiles to a spurious
2-instruction `lsl #0x10` / (implicit) `lsr #0x10` truncation-simulation pair around
the `and`, where the ROM emits one plain `and`. **Widening the variable's storage
type to plain `int`** (keeping the same expression, adding explicit narrowing casts
back at each *use* site, e.g. `entry[3] = (unsigned short)(entry[3] & mask)` instead
of `entry[3] &= mask`) eliminates the spurious pair - the single `and` reproduces
exactly. Tried and ruled out first: `unsigned int` (made it *worse*, not neutral -
this is not simply "any wide type works", `int` specifically was needed here);
operand-order swap; a separate named intermediate for the loaded flag byte; explicit
cast chains. Confirmed on `FUN_022d5870` (arm7, dsi/1.3, `-O4,s`) - a real, ~10th
attempt after 3 earlier rounds of failed narrow-type phrasings.

### 1b. Redundant-recompute lever: split a shared boolean into two independent tests

Found by re-reading raw disasm rather than trusting a Ghidra/m2c-collapsed view. A
natural single `if (cond) {A} else {B}` deciding TWO downstream values (e.g. which
pointer a loop continues from, and which value it reads next) compiles to one shared
compare + branch. The ROM instead **re-tests the same condition twice, independently**
- one compare deciding value 1, a second separate compare (often against a
freshly-reloaded pool constant) deciding value 2. Splitting the C into two
back-to-back, independently-conditioned `if/else` blocks (each re-testing the same
boolean expression fresh, not sharing a cached branch) reproduces this exact
redundant-compare shape instruction-for-instruction. Took `FUN_022d5870`'s candidate
from 122-vs-123 instructions (structurally short by one) to a genuine 123-vs-123 exact
count. General shape: whenever the ROM's disasm shows the SAME `cmp`-style instruction
appearing twice in quick succession against what should be one boolean, suspect this
lever before assuming CSE elimination is unreachable.

## 2. The pure-coloring wall: ruled out, this compiler build, `FUN_022d5870`

After levers 1a/1b closed every structural/idiom gap on `FUN_022d5870`, one residual
remained: a base pointer (`conn`, loaded once from a global at function top, used
throughout) colors to `r4` in every candidate tried; the ROM has it in `sb` (r9).
Frame shape (9 registers, same set, same stack depth) is otherwise EXACT - this is
pure register-coloring, not a count or structural mismatch. The following documented
sm64ds levers were tried against this specific residual and had **zero effect** on
`dsi/1.3`:

- u64-mask laundering (`(long long)(int)(p) & 0xffffffffffffffffLL` round-trip,
  sm64ds section 6h) - applied individually to every one of 5 candidate base
  pointers. This compiler build appears to constant-fold the all-ones mask away
  entirely (confirmed via disassembly - identical bytes with/without the launder),
  unlike whatever build produced sm64ds's own documented win with this trick. **Try
  this lever first on any future residual anyway** - it's real and cheap, just
  confirmed non-transferable to `dsi/1.3` specifically so far, not disproven in
  general.
- GCC-style explicit register binding, `register T x asm("sb")` (`-gccext,on` is
  already in this project's default flags) - compiles without error, silently
  ignored; disassembly confirms the binding has no effect.
- All 10 tested `#pragma opt_* off` toggles (`opt_common_subs`, `opt_strength_reduction`,
  `opt_propagation`, `opt_peephole`, `opt_lifetimes`, `opt_dead_code`, `opt_dead_store`,
  `opt_loop_invariants`, plus plain `scheduling off` / `peephole off`) - all silently
  accepted, zero byte-level effect.
- Opt levels 1-3 (`-O1` through `-O3`, both `,p` and `,s`) - none closer than level 4's
  result; level 2 and up all converge to the same coloring.
- The full 5!-permutation (120 combinations) sweep of top-level declaration order
  (`tools/frame_search.py`-style, but a bespoke script since this needed whole-
  statement reordering, not the tool's per-token toggle model) - best found matches
  the levers-1a/1b result exactly, no ordering beats it.
- Declaration TYPE lever (sm64ds's "TYPE of a named local selects its callee-saved
  rank" - hoisting a value to `u32`/`int` at function scope changed its rank on their
  target) - applied to `conn` (storing the raw address as `unsigned int` instead of
  `char *`, casting at every use site): zero effect here, still colors to `r4`.
- Zero-instruction web-priority booster (`x = cond ? x : x;`, sm64ds lever 6y-1) and
  `volatile`-pinning a memory-sourced pointer (sm64ds lever 6y-4) - both zero effect.
- Threading a hypothetical return value from the paired lock function through to the
  unlock call (testing whether `func_037ca044`/`func_037ca0c8` might have an
  IRQ-state-passing signature like the SDK's disable/restore-interrupt pair) - made
  the result slightly *worse*, not better; no real evidence supports this signature
  change beyond the (unconfirmed) hypothesis.

**Where this leaves it**: `scratch/FUN_022d5870_v13.c` is the closest candidate found
(123/123 instructions, one pure register permutation remaining). Not banked - still
not byte-identical, and per this project's own standard that's not a match. Next
genuinely untried angle: sm64ds's own "persistence across disjoint angles" method note
(6y) - their hardest coloring walls fell only after multiple agents attacked the SAME
residual with genuinely different ideas in parallel and cross-pollinated, not from one
line of attack pushed further. Also untried: reading the ~85% of sm64ds's codegen
notes not yet consulted (sections 4-5, 6, 6b-6c, 6e-6g, 6n-6p, 6t-6z, 6ac-6am, 7a-7c, 9,
9a - only 1-3, 6d, 6h-6m, 6q-6r, 6y-6ab, and the "type selects rank" / "stack-slot
order" parts of 6al were read before this session's time budget ran out).

## 3. The arg-spill-prologue wall: partial progress, `FUN_022d5a64`

`FUN_022d5a64` (arm7, 0x1fc/508 bytes, a bit-packed chunk decoder) needs a genuine
`push {r0,r1,r2,r3}` argument-homing prologue (all 4 incoming register args spilled to
fixed stack slots) BEFORE its normal 9-register callee-saved frame push - 13 registers
total. No candidate C written for this function across two separate investigation
rounds has ever produced this prologue; every draft's compiler decides it needs far
fewer registers (5-10, depending on flags) and never reaches for the arg-spill.

**Real progress this session**: `-O4,s` (never previously tried on this specific
function; earlier rounds only tried the default `-O4,p`) jumped register count from
5-6 to **10 of 13** and shrank the total size gap from 88 bytes over to 16 bytes over.
Always sweep both `-O4,p` and `-O4,s` on a fresh draft before judging register-pressure
distance - this project's own docs already say this for the epilogue-duplication case,
and it applies here too.

**Tried and ruled out**: widening bitfield-derived locals (`chunkLen`/`consumed`/
`subIndex`) from `unsigned int` to `int` (sm64ds lever 1a's mask trick, applied
speculatively - zero effect, this isn't a narrowing-idiom problem); fully un-collapsing
the bitfield computation into m2c's own granular temp-per-value decomposition instead
of consolidated expressions (testing sm64ds's "a minimized stub under-expresses the
pressure" theory directly - zero effect); taking the address of the raw parameter
(`&a1`) instead of a local copy (small win, ~4 bytes, not the structural fix); combining
the first two parameters into a single `unsigned long long` to mechanically trigger
sm64ds's documented "`u64 f(u64 d, int flag)` reproduces `push {r0-r3}`" lever (section
6s) - zero effect, and architecturally this project's function doesn't share that
lever's exact shape (5 args across 4 registers + stack, not a leading 64-bit value).

**Not yet tried**: the sm64ds 6s cluster's full byte-access idiom (`READ8`/`WRITE8`
ternary/if-else macros) doesn't apply here (no unaligned-byte VRAM access in this
function), but the general principle - that arg-homing prologues in their codebase
always trace to a specific, identifiable source construct rather than being a floor -
suggests there IS a real, discoverable cause here too, most likely something about how
the caller's actual argument TYPES are declared (this project's read of the signature,
`FUN_022d5a64(uint index, undefined4 a1, ushort *chunk, uint len, undefined4 ctx)`, may
itself be wrong in a way that's suppressing the pressure - `a1`'s Ghidra type
`undefined4` and its use as `&a1`-then-read-as-`ushort` is exactly the kind of
un-resolved-type signal sm64ds's docs repeatedly flag as worth re-deriving from raw
stack-offset reads rather than trusting the decompiler's guess, per their own
`arm9-endgame.md` `func_0206f46c` case study).

## 3a. A different compiler BUILD can change prologue shape, not just coloring

sm64ds-decomp's section 6ai documents recovering a genuinely different compiler build
(`Metrowerks C/C++ for Embedded ARM, Version 2.0 build 56`, Sept 2004,
`tools/recover_cw2004.py`) that reproduces prologue SHAPES (not just register colors)
their entire 24-build `1.2`/`2.0` sweep could not - a `push {fp,lr}` dynamic-frame
prologue vs. a fixed-frame one, from IDENTICAL C source. Real, hard evidence that
"a structural gap never appears from any C phrasing" can be a **compiler-build**
question, not a source-phrasing one.

**Fixed and now live in this project (2026-08-02).** `tools/mwccarm/2004/b56/` was
vendored with `mwccarm.exe` correctly recovered (verified: exact expected size and
banner, `Version 2.0 build 56`), but the DLLs sitting alongside it were the *wrong*
ones - the genuine, much older (1.6 MB vs 100 KB) `ELFIO.dll` that shipped inside the
original 2004 installer, which itself depends on a `PluginLib4.dll` that was never
extracted (confirmed by reading the PE import tables directly - `tools/recover_cw2004.py`
correctly documents "the runtime DLLs are identical across builds; borrow the 1.2 set"
and copies from `1.2/sp2p3`, but the DLLs actually present in `2004/b56/` didn't match
what the script would have produced, so this build silently never worked). Manually
copying `tools/mwccarm/1.2/sp2p3/{ELFIO.dll,MSL_All-DLL80_x86.dll,lmgr8c.dll}` into
`2004/b56/` (i.e. actually doing what the recovery script's own comment says) fixed it
- `mwccarm.exe -version` now runs and reports the correct banner, and it compiles real
source. Added to `tools/match.py`'s `SWEEP` (as `CW2004_SWEEP`) so `--all` covers it
automatically going forward. If this ever regresses (DLL mismatch again after a fresh
vendor/tools sync), re-copy those 3 files from any working `1.2/*` directory - no
network access needed, the fix is entirely local.

**Tested against both open near-misses:**
- `FUN_022d5870`: `2004/b56` gives 0x220 under both opt levels - *worse* than
  `dsi/1.3 -O4,s`'s 0x1f0 best. Not the fix for this function's coloring wall.
- `FUN_022d5a64`: **real breakthrough.** Plain `2004/b56` alone (no other source
  change) gets the full 9-register callee-saved push, more complete than `dsi/1.3`
  ever reached, but still no arg-spill. Combined with the small already-known lever
  (taking the address of the raw parameter, `&a1`, instead of a local copy) -
  **`2004/b56` + `&a1` reproduces the EXACT target push set**: `{r0,r1,r2,r3,r4,
  r5,r6,r7,r8,sb,sl,fp,lr}`, all 13 registers, matching byte-for-byte. This is the
  first time in this function's multi-round history that the arg-spill prologue has
  been reproduced at all - `dsi/1.3` never got there from any of ~20 source variants
  tried across two sessions; this specific compiler-build + source-lever combination
  gets it immediately. Confirms the section 3a hypothesis directly: this was a
  compiler-build question, and `&a1` alone (tried extensively under `dsi/1.3`, only
  ever worth ~4 bytes there) was apparently always the right lever, just needed the
  right build to matter.

  Not a full match yet - stack FRAME size still differs a lot (`sub sp,#0x2c` vs
  target's `#0xc`, 32 bytes over) once the push set is right, and `fdiff --align`
  shows the divergence is now concentrated in the notify-packet-building block: this
  candidate appears to pre-compute several packet field CONSTANTS (0, 0x200, 2, 0x82,
  0x15) into stack slots early/unconditionally, where the ROM only computes them
  inside the branch that actually sends the packet - looks like 2004/b56's older,
  weaker optimizer is less willing to defer/inline these than dsi/1.3's, and the C
  may need restructuring (e.g. explicit late initialization instead of relying on the
  optimizer to hoist-and-discard) to suit this specific compiler generation's
  behavior. Real, promising, unfinished - `scratch/FUN_022d5a64_v3_b56.c` is the
  seed to continue from.

Bottom line: this build is now a real, working, permanent addition to the toolkit
(previously silently broken - see above), worth including in every future version
sweep, and has already produced the single most significant structural breakthrough
of this investigation.

### Follow-up: the WHOLE `2.0/*` line reproduces the prologue even better than `2004/b56`

Once `&a1` was confirmed as the real trigger (not `2004/b56` specifically), swept it
against every vendored version. Result: **every `2.0/*` build** (`base` through
`sp2p4`, all identical output) reproduces the target's push set **exactly**
(`{r0,r1,r2,r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}`, 13/13) **and the exact frame size**
(`sub sp,#0xc`, matching target's `0xc` precisely - `2004/b56` only matched the
register set, not the frame). `scratch/FUN_022d5a64_BEST_2.0sp2p4.c` +
`2.0/sp2p4 -O4,s` compiles to **0x210 vs target's 0x1fc - 20 bytes / ~5 instructions
over**, by far the closest this function has ever come (previous best under `dsi/1.3`
was 0x20c but with the WRONG prologue shape entirely - this is the first candidate
with the right structural skeleton at all). `dsi/1.3` itself, same source, only gets
a partial/malformed push set (`-O4,p` even shows a duplicate `r3` in the probe,
suggesting genuinely confused register allocation, not just a smaller subset).

Remaining gap per `fdiff --align`: mostly coloring (`sb`/`sl` swapped for two
mid-function values, `r6` vs `r8` for the slot-array base) plus one real
instruction-selection difference - target computes the `subIndex` field via
`and r1,r1,#0xf00` / `lsl r1,r1,#8` / `lsr fp,r1,#0x10` (a 3-instruction shift
pair) where this candidate's natural `(hdr & 0xf00) >> 8` collapses to `and` +
single `asr`/`lsr`. Tried two shift-respellings (`((hdr&0xf00)<<8)>>16` both signed
and unsigned) - both made it slightly *worse* (0x214), so the natural form is
already better; the right respelling to reach the target's exact pair is still
unfound. Given how far this has come in one push (never-reproduced structural gap
-> 20 bytes of pure coloring/idiom residue), this function is now realistically
close to a full match with more of this specific angle (declaration-order sweep,
more shift-idiom variants, the redundant-recompute lever from section 1b applied
here too - none of section 1's levers have been tried yet on THIS candidate).

**Open question worth resolving before banking anything here**: none of this
project's confirmed matches are known to use `2.0/*` yet (the `dsi/*` line is the
working hypothesis per `CANONICAL = "dsi/1.3"`in `match.py`, chosen because DSi
launched 2008/9 and a 2.0-line NTR build predates that). If `FUN_022d5a64` only
ever matches under `2.0/*` and never under any `dsi/*` build, that's either a real,
surprising finding (this function's translation unit was compiled with an older
toolchain than the rest of the title - not unheard of, sm64ds-decomp found exactly
this pattern for their own arm9 MSL cluster, section 6ai) or a sign the candidate
C is still structurally wrong in a way that happens to compile smaller under an
older/weaker optimizer without being correct. Don't bank a `2.0/*`-only match
without extra scrutiny (cross-check relocs carefully, re-derive the packet-field
struct layout independently) given it would be this project's first confirmed
non-`dsi` match.

### Remaining residual, catalogued (0x210 vs 0x1fc, 20 bytes / ~5 instructions)

`fdiff --align` on `scratch/FUN_022d5a64_BEST_2.0sp2p4.c` under `2.0/sp2p4 -O4,s`
breaks the residual into two distinct classes, neither closed yet:

1. **Plain coloring** (majority of blocks): `sb`/`sl` swapped for two mid-function
   values, `r6` vs `r8` for the slot-array base pointer - same flavor of wall as
   `FUN_022d5870`'s (section 2), not yet attacked with that section's lever
   catalogue on this candidate specifically.
2. **Two real instruction-selection differences**, both genuine, neither fixed by
   the attempts below:
   - `subIndex` extraction: target emits `and r1,r1,#0xf00` / `lsl r1,r1,#8` /
     `lsr fp,r1,#0x10` (3 instructions); this candidate's natural `(hdr & 0xf00) >>
     8` collapses to `and` + one `asr`/`lsr`. Tried: explicit `((hdr&0xf00)<<8)>>16`
     both signed and unsigned-typed (both *worse*, 0x214) - the natural short form
     beats every respelling tried so far.
   - Retry-countdown block: target does `lsl r7,r7,#1` (double) then a SEPARATE
     `sub r3,r3,r7` / `lsl r3,#0x10` / `lsr r3,#0x10` (4 plain instructions);
     candidate's `-O4,s` fuses the double directly into the subtract's barrel
     shifter (`sub ip,ip,r3,lsr#16`) plus reshuffles into 5 instructions using an
     extra `ip` register - a genuine fused-vs-separate operation choice, not
     coloring. Tried: splitting the doubled value and the difference into two
     separate named temps (to break the data-flow chain the fusion needs), and
     replacing the shift with `old + old` instead of `old << 1` - neither changed
     the output at all (byte-identical to the unmodified version in both cases).

Next things worth trying, not yet attempted on this candidate: section 1b's
redundant-recompute-splitting lever (never applied here, and this function has
several `if/else` blocks deciding two downstream values that could have the same
"ROM re-tests twice" shape `FUN_022d5870` did); the full declaration-order
permutation sweep (also never run against this specific 2.0-line candidate); and
`#pragma opt_strength_reduction off` specifically targeting the fused-shift-into-
subtract instruction-selection choice (the individual pragma sweep in section 2 was
only ever tested against `FUN_022d5870`, not re-tried here even though this is a
structurally different residual class where it's more likely to matter). Tried:
all 5 relevant pragmas re-tested directly on this candidate under `2.0/sp2p4` -
zero effect on any of them (same 0x210 either way).

### CORRECTION, same session: sanity-checked against 6 already-confirmed matches - `2.0/*` is NOT this title's build

Swept all 6 clean (non-`NONMATCHING`) already-matched arm7 files
(`FUN_022ce2c4/5b4/784/884`, `FUN_022cfa44/90`) through `--all` (after fixing a
self-inflicted test error - their recorded `size` in `config/arm7/symbols.txt`
excludes the trailing literal-pool word(s); `extract_func`'s `st_size` includes
them, so a naive re-test using the recorded size alone spuriously "fails" on size
mismatch for every version including the correct one - always add the pool's
bytes, found per-function by bisecting size until a version matches, before
trusting a version-sweep result). Real result once sized correctly:

- **Every one of the 6 matches under every `dsi/*` build** (all 9), no exceptions.
- **5 of 6 also happen to match under the entire `2.0/*` line** - coincidental
  codegen overlap on simple leaf functions, not evidence `2.0` is a valid
  alternative build for this title.
- **`FUN_022ce5b4` is the exception that settles it**: matches every `dsi/*` build,
  but `2.0/*` gets it wrong by a real 10-word margin. This is a confirmed,
  in-cluster divergence between the two lines, not a hypothetical - proof `2.0/*`
  is not simply "as good as `dsi`" for this title, just coincidentally close on
  functions simple enough that the two lines don't diverge.
- `1.2/*` never matches any of the 6 (either 999 or a real word-diff count).
  `2004/b56` never matches any of the 6 either (999, or 4-10 words off on the ones
  close enough to report a real count).

**Conclusion: `dsi/*` remains the only evidenced-correct line for this title.**
`FUN_022d5a64`'s apparent breakthrough under `2.0/sp2p4` (arg-spill prologue
reproduced exactly) is very likely the SAME kind of coincidental overlap seen on 5
of the 6 confirmed matches above, not evidence this function's real translation
unit used a different compiler - chasing it to a byte-exact match under `2.0`
would produce something with the same false-confidence risk as chasing
`FUN_022ce5b4` under `2.0` would have (10 words that would never actually close,
because the compiler is simply wrong, no matter how the C is phrased). **The `&a1`
lever itself is still real and worth keeping** - it's what finally produced the
right prologue SHAPE, a genuine structural finding - but the next step is
re-testing it specifically under `dsi/1.3` (where it was only shallowly checked
before finding the `2.0` result and getting side-tracked), not continuing to tune
a `2.0`-only candidate.

### `&a1` re-tested under `dsi/1.3`: real result, new three-way tension found

Swept all 8 opt-level/space-speed combinations (`-O1` through `-O4`, `,p`/`,s`
each) under `dsi/1.3` with the `&a1` candidate. Two distinct, mutually exclusive
problems, not one:

- **`-O3,p` is the only combination with a clean, non-duplicated 13-register push**
  (`{r0,r1,r2,r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}`, exactly matching target) - `-O1,p`/
  `-O2,p`/`-O4,p` all show a spurious duplicate `r3` in the push; every `,s` variant
  (`-O1,s` through `-O4,s`) emits TWO separate push instructions with an overlapping
  register set (confirmed via direct disassembly: `push {r0,r1,r2,r3}` immediately
  followed by `push {r1,r2,r3,r4,...}` - r1/r2/r3 genuinely pushed twice, a real
  compiler artifact, not a probe misread).
- **But `-O3,p` triples the early-return epilogue** - this function's 5-condition
  guard clause (already written as ONE combined `if (A||B||C||D||E) return;` in the
  C, not five separate returns) still compiles to 3 separate predicated
  `addeq/popeq/bxeq`-style inline epilogues under any `,p` variant, where the ROM
  branches all five conditions to one shared exit. This is the EXACT pattern this
  project already has a documented fix for ("`-O4,s` fixes duplicated early-return
  epilogues", used on `FUN_022cfa90.c` and others) - except `-O4,s` is precisely the
  flag that breaks THIS function's prologue (the double-push issue above). Rewriting
  the two `return;` statements as `goto out;` targeting one trailing label had NO
  effect (byte-identical output to the plain `return` version) - the duplication
  isn't about syntactic return-statement count, the compiler already treats the
  combined `||` condition as one logical unit internally and still duplicates it.

Best real candidate under the confirmed-correct `dsi/1.3` build:
`scratch/FUN_022d5a64_v3_b56.c` (despite the filename, this is the same source,
just also tested against `2.0`/`2004` builds earlier) + `-O3,p` = **0x270 vs
target's 0x1fc, 116 bytes over** - correct prologue shape, but the epilogue
tripling alone accounts for most of the gap. This is WORSE in raw byte count than
the `2.0/sp2p4` result (0x210) but is the only candidate built on the
CONFIRMED-correct compiler line, so it's the one actually worth continuing from,
per the section above's sanity-check finding.

**Open problem, now investigated exhaustively without a fix**: `-O3,p` gives the
correct prologue but triples the epilogue; `-O4,s` shares the epilogue correctly
but double-pushes `r1-r3` in the prologue. This is a genuine `,p`-vs-`,s` AXIS
behavior, not an opt-level or bug: `,s` (optimize for space) merges identical
tail code to save bytes - which is exactly the epilogue-sharing this function
needs - but the SAME space-focused register allocator mode also reaches for
`r1-r3` a second time for unrelated general-purpose locals elsewhere in the body,
forcing a second push. `,p` (optimize for speed) does the reverse trade on both
counts. Confirmed BOTH behaviors are tied to the same axis, not independently
controllable: every `,p` variant (`-O1` through `-O4`) triples the epilogue;
every `,s` variant double-pushes. Tried and ruled out this round, all against the
`-O3,p` (clean-prologue) baseline:
- Nested `if` instead of one flat `||` chain, `goto`-retargeting, and
  `do { ... } while(0)` + `break` for the guard clause - all three byte-identical
  to the plain flat `return` form. Matches sm64ds-decomp's own documented floor
  for this exact symptom (section 6d), now confirmed independently on a second
  project/toolchain instance.
- All 14 individual `-opt [no]cse/lifetimes/strength/loop/prop/deadcode/deadstore`
  toggles layered on top of `-O3,p` - zero effect on any of them (same 0x270).
- Exotic flag combinations mixing level/space/speed tokens directly (`-opt
  level=N -opt space`, `-O3,p -opt space`, `-O4,s -opt nospace`, etc.) - every
  attempt either falls back to the `,s`-family double-push behavior or gets
  strictly worse; none isolate epilogue-sharing from the prologue side effect.
- Source-level attempts to reduce `r1-r3` register pressure in the body under
  `-O4,s` specifically (reordering `payload`/`cur` computation, inlining
  `maskWord` to remove a named local) - zero effect, still double-pushes.

Given how deep this has been searched (compiler-flag space exhausted across both
axes, several source restructurings tried, cross-referenced against an
independently-documented floor of the identical symptom class), this now reads as
a genuine mwccarm behavior tension rather than an unexplored angle. Note the target
ROM's actual shape here is a plain `beq`/`bhi`/etc. to ONE shared tail label
(`add sp,#0xc; pop {...}; add sp,#0x10; bx lr` at a single address, reached by
several branches) - not a call - so any fix needs to be genuinely inline, same
constraint every `,p`/`,s` attempt above already respected.

### Real progress via `sm64ds-decomp/notes/pret-idioms.md` (mined from pret/pokeplatinum,
pret/pokediamond - same compiler family, matched to ~100% - not yet read before this round)

That file's lever #3 ("reuse a variable instead of introducing a new one - avoid an
extra slot/register") led to a genuine, measurable fix for the `-O4,s` prologue's
double-push (previously double-pushed `r1,r2,r3`; now only `r3`):

**The `first` boolean flag was itself the extra register.** The function used an
explicit `int first = 1;` to distinguish "read the header from `&a1`" (iteration 1)
from "read it from `cur`" (every later iteration), then cleared it. Replacing this
flag with an **implicit test** - `if (cur == chunk)` instead of `if (first)`, since
`cur` provably never re-equals its own starting value `chunk` once the loop has
advanced past iteration 1 (`consumed` is always > 0) - removes one persistent
variable entirely. Result: prologue push count dropped from 16 (3 duplicates:
`r1,r2,r3`) to 14 (1 duplicate: `r3` only), size improved from 0x208 to **0x1f4**
(target 0x1fc - now UNDER target by 8 bytes rather than over, a qualitatively new
regime). `-O3,p`'s epilogue-tripling side also shrank (0x270 -> 0x258) though the
duplicate-epilogue-count itself didn't change (still 8 copies) - the size win there
is a smaller, separate effect of one fewer live variable throughout the function.

Other pret-idioms.md levers tried against this same candidate, no further
movement: C89-style declare-all-locals-at-top (item 2, byte-identical to natural
declare-at-first-use - this build doesn't care about textual position the way
the pret decomps' compiler evidently did); `ok++`/`first--` instead of `first=0`
style assignment (item from a separate mwccarm-codegen.md batch about spill
behavior - no effect, tested before finding the real fix was eliminating the
variable rather than changing how it's assigned); consolidating `hdrPtr`/`payload`
into one reused pointer variable (no effect - this specific merge doesn't touch
the register in question); inlining `hasLenField`/`hasMaskField` to remove their
named-local status (made things WORSE, 0x1dc undershooting further - these two
ARE genuinely separate stored values in the real source, don't remove them);
declaration-order permutation of the remaining top-level locals (no improvement
beyond what the `first`-elimination alone already found).

**Current best: `scratch/FUN_022d5a64_BEST_dsi13.c`** (`dsi/1.3`, `-O4,s`) - 0x1f4
vs target's 0x1fc, ONE duplicate register left in the prologue (`r3`), everything
else in the same shape as before. This is the closest this function has been
under the confirmed-correct compiler build across every round of this
investigation. Not matched. Next step: the same "eliminate a variable via an
implicit test" pattern that worked for `first` may apply to whatever's forcing
`r3`'s second push (likely tied to `len`'s specific role - it gets copied to `sl`
immediately after entry, and the pushed copy is never read again, suggesting the
same "unnecessary persistent-value" shape `first` had) - tried a `lenParam`/`len`
split and an `&len` address-taken probe, neither helped, but the general pattern
(find what's using r3's identity past its natural point of death, restructure to
avoid it) is the one proven lever from this round and worth continuing with fresh
eyes on exactly `len`'s handling, not yet on any other variable.

### Round 2, same session: confirmed root cause precisely, extensive further search, no additional win

Traced the remaining `r3` duplicate to its exact instruction-level cause: an
`ip`-register spill. **Target NEVER uses `ip`/r12 anywhere in this function**
(confirmed by disassembling the real ROM bytes and checking every operand). The
candidate does, in the `diff = *maskWord - (old<<1)` computation, where mwccarm
fuses the shift into the subtract's second operand (`sub ip,ip,r3,lsr#16`) instead
of the ROM's plain, unfused 4-instruction form (`lsl;sub;lsl;lsr`, no `ip`). This
matches this file's own section 2 finding almost exactly ("bigger function -> low
regs fill -> the allocator spills a temp to ip") and sm64ds's own explicit
disclaimer: "you usually CANNOT force ip/r12 coloring from C source... there is no
reliable knob."

Tried against the current best candidate specifically, all zero-effect (byte-
identical) or worse: a block-scoped `doubled` temp to break the fusion's data-flow
(no change); `volatile`-pinning the pre-subtraction value (worse, 0x210); a cached
`maskWord` pointer variable instead of re-deriving `slot+maskOff` inline 4 times (no
change); widening `val`'s type to `int` (no change - confirms `FUN_022d5870`'s mask-
widening lever does NOT transfer to this shape, it's specific to that function's
different symptom); all 4 relevant `#pragma opt_* off` toggles re-tested on this
exact candidate (no change, consistent with every earlier pragma sweep this
session); 300 random declaration-order permutations of all 18 locals (no
improvement - confirms the earlier hand-picked permutation tests weren't just
unlucky); bisection stubbing (removing the mask-field block entirely makes things
WORSE, not better - 16 duplicates instead of 14 - confirming this is a whole-
function pressure balance, not something isolable to one block).

**Went to the primary source, not just sm64ds's paraphrase**: cloned
`pret/pokeplatinum` locally (`../pokeplatinum`, sibling directory) and grepped its
actual matched C for the literal idioms behind pret-idioms.md's summarized rules
(`"to match"`, `"reus... match"`, `"spilled"`, `"regalloc"`, `"declar... match"`
etc.). Found the same general categories already summarized in pret-idioms.md
(declaration order, C89-style, variable reuse, type choice) but no example
specifically addressing an ip-spill-from-a-fused-shift-subtract shape - this exact
symptom doesn't appear to have a documented pret solution either, consistent with
sm64ds's own "no reliable knob" conclusion. `pret/pokediamond` was NOT cloned/
searched this round (only pokeplatinum) - worth trying if picked up again, in case
its independent contributor base hit and solved this exact shape.

**Where this leaves it**: `scratch/FUN_022d5a64_BEST_dsi13.c` at 0x1f4 (target
0x1fc, 8 bytes under) remains the best result, now understood at the instruction
level (one ip-spill from one fused shift-subtract) rather than "one duplicate
register, cause unknown." Two projects' worth of hard-won knowledge (sm64ds-decomp's
own extensive corpus, pret/pokeplatinum's large match-comment corpus) both
independently lack a source-level lever for this exact class - a real, meaningful
negative result, not an unexplored gap. Remaining budget is probably better spent
triaging the other ~25 diff blocks (mostly plain register coloring, not yet
individually characterized this round) than continuing to force this one ip-spill.

### Round 3, same session: EXACT register-set match found (0x200 vs target's 0x1fc, 4 bytes)

Pushed further after PR #35 (this file + the viewer + the `2004/b56` sweep addition)
was committed and merged into its own branch. Two more real findings:

1. **`volatile` on `first` reproduces target's real flag structure AND is closer than
   the `cur == chunk` implicit-test workaround.** Re-reading target's actual bytes for
   this block confirmed it genuinely has an explicit flag - `cmp r0,#1` against a value
   loaded from a **stack slot** (`ldr r0,[sp,#8]`), with `streq r0,[sp,#8]` clearing it
   back to 0 on the first pass - not an implicit pointer comparison. Declaring `first`
   `volatile int` (forcing it to always be memory-resident, never register-allocated)
   reproduces this stack-resident structure almost exactly (same shape, offset differs)
   while STILL avoiding the register-count blowup a plain `int first` caused - `volatile`
   was the missing piece connecting the two working-but-incompatible approaches from
   round 2. Result: 0x200 (down from 0x1fc target - so this is not yet the final answer
   on its own, see #2).

2. **`volatile unsigned int consumed` (on top of the `cur == chunk` form, not the
   `volatile first` form) gives an EXACT 13/13 register-set match** -
   `{r0,r1,r2,r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}`, byte-identical push list to target, for
   the first time in this function's entire multi-round history. Found via a full
   single-variable `volatile` sweep (tried on `val`, `hdr`, `chunkLen`, `consumed`,
   `subIndex`, `maskOff` individually) - `consumed` and `subIndex` both give a clean
   push in isolation, but `consumed` gives the smaller total size (0x200 vs
   `subIndex`'s 0x1fc... - **note: `volatile subIndex` alone lands on the exact SAME
   TOTAL SIZE as target, 0x1fc, but with a still-duplicated push and a different
   internal shape - a size coincidence, not structural correctness; don't mistake
   matching total size for matching structure, always check the push set too.**

**Current best: `scratch/FUN_022d5a64_BEST_dsi13.c`** (`cur == chunk` implicit test +
`volatile unsigned int consumed`, `dsi/1.3`, `-O4,s`) - **exact register SET match**
(not just count), frame `0x14` vs target's `0xc` (8 bytes / 2 stack words over), total
size **0x200 vs target's 0x1fc - only 4 bytes over**. This is unambiguously the
closest this function has been. Tried and ruled out for shrinking the remaining 2
stack words: `volatile` on `chunkLen`/`subIndex`/`maskOff`/`p`/`pktSrc`/`afterHdr`
individually and in combination with the working `consumed` version - every
additional `volatile` either regresses the register count (loses the clean push) or
doesn't shrink the frame at all. The 2 extra stack words are still unaccounted for -
next step is identifying exactly which 2 of the ~13 remaining stack-resident locals
correspond to slots target doesn't have, by comparing stack offset usage
instruction-by-instruction (not yet done this round - ran out of time on the`volatile`
sweep axis before starting the stack-offset audit).

## 4. Where to look next

`../sm64ds-decomp/notes/mwccarm-codegen.md` sections not yet read into this project's
knowledge (see the list in section 2 above) are the highest-value next research step
before more blind experimentation - this file's two confirmed levers (section 1) both
came directly from that source, and its authors have already run into and solved
problems this project hasn't hit yet at this scale.
