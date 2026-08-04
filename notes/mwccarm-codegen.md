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

**Round 10** (testing whether this session's two `FUN_022d5a64` levers - volatile-on-
parameter, u64-laundering the SPECIFIC mis-colored variable rather than its derivatives
- generalize here; they don't):
- `volatile unsigned short a0` (the twewy-sourced parameter lever that closed
  `FUN_022d5a64`'s prologue/epilogue gap): regresses to 0x1fc (16 bytes over, vs v13's
  4). `a0` here is used exactly once, right at function top - nothing like `FUN_022d5a64`'s
  `ctx` (carried live across the whole function). The lever's mechanism (keeping a
  stack-resident parameter materialized) has no purchase on a parameter that's already
  dead after its first use. (mwccarm syntax note: `volatile` must precede the type in a
  parameter decl - `unsigned short volatile a0` produces cascading unrelated-looking
  "expression syntax error"s deep in the function body, a confusing failure mode.)
- `char * volatile conn` (the lever applied directly to the mis-colored variable):
  regresses further, 0x210 (36 bytes over) - forcing every use to reload from memory
  is the opposite of what's needed (target keeps `conn` resident in one register the
  whole function).
- Re-ran u64-laundering on `conn` itself specifically (this section's existing bullet
  says "5 candidate base pointers" were tried previously, but doesn't name `conn`
  explicitly among them) - reconfirms the same zero-effect result: still 0x1f0,
  `conn` still colors to `r4` per `fdiff.py --align`.

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

### Round 4, same session: found a real-world precedent via actual ARM/NDS mwccarm source, closed to 4 bytes

Per direct instruction to research rather than guess: searched beyond sm64ds-decomp and
pret (both GameCube/PS2-adjacent or, for pret, not yet at this level of `volatile`
idiom documentation) for an ACTUAL mwccarm decomp targeting this same platform (NDS
ARM). Found two real ones on `decomp.wiki`'s project list - `Yotona/twewy` (The World
Ends With You) and `Eebit/fe11-us` (Fire Emblem: Shadow Dragon) - both real mwccarm/NDS
codebases, cloned/searched via `gh search code`.

**Found the exact idiom class in `twewy`'s `src/Engine/Core/OamMgr.c`**: a function
(`func_02003ef4`) with the identical symptom this project has been fighting -
"Nonmatching: Regswaps, argument spills are ordered differently" - uses **`volatile`
directly on function PARAMETERS** in the signature (`volatile s32 arg5, volatile s32
arg6`), and a sibling pattern (`volatile u16* const pArg4 = &arg4;`) taking a volatile
pointer straight to a parameter (not a local copy - copying first breaks the mechanism,
confirmed empirically below). This is a real, currently-used technique in an actual
matched-adjacent mwccarm/NDS codebase for exactly this symptom class, not something
inferred abstractly.

**Applied directly: `volatile`-qualifying the `ctx` parameter** (the 5th, stack-passed
argument) on top of the existing `cur == chunk` + `volatile consumed` base **closed the
prologue AND epilogue to an exact match** - `pop {r4,r5,r6,r7,r8,sb,sl,fp,lr}` is now
byte-identical to target, zero duplicates, for the first time. Total size **0x1f8 vs
target's 0x1fc - 4 bytes**, the closest this function has ever been by a wide margin.

Swept every other single parameter as the volatile target (`index`, `a1`, `chunk`,
`len`) both alone and stacked on top of the working `ctx` version - `ctx` alone is
uniquely the one that gives a clean push AND the smallest size; every other parameter
either breaks the clean push again or doesn't help. Confirmed the twewy repo's own
"copy to a local first, then take a volatile pointer to the copy" sub-pattern does NOT
transfer to `a1` here (copying breaks the arg-spill-preserving mechanism specifically
because it stops reusing the ORIGINAL incoming register's own stack-spilled address -
`&a1` needs to point at the real parameter, not a fresh local, for this function).

**Current best: `scratch/FUN_022d5a64_BEST_dsi13.c`** (`cur == chunk` implicit test +
`volatile unsigned int consumed` + `volatile void *ctx` parameter, `dsi/1.3`,
`-O4,s`) - exact register set, exact push AND pop instructions, frame `0x14` vs
target's `0xc` (1 stack word), **4 bytes total**. Remaining diff (`fdiff --align`,
26 blocks) is now overwhelmingly plain register coloring (`sb`/`sl`, `r4`/`r5`/`r6`
swaps) plus the same `moveq`/`movne` polarity flip on the `v30`/`v32` swap-pick logic
noted in round 1 - re-derived the source logic against the original Ghidra pseudocode
and confirmed the C is correct (`pkt[0x21] = flag ? v30 : v32`, matches exactly);
the polarity flip is downstream coloring from an equivalent computation, not a bug.
Tried `volatile` on `v30`/`v32` directly and on `pktSrc`+`afterHdr` together - neither
closes the last 4 bytes; next angle is the coloring residuals directly (declaration-
order or access-expression levers per section 1, not yet re-swept against this exact
2-byte-away candidate).

### Round 5, same session: full grid search on `first`, confirmed the `v30`/`v32` block was already correct

Ran the complete 2x2x2 grid (`first` present-as-volatile / present-as-plain / absent,
crossed with `consumed` volatile on/off and `ctx` volatile on/off - 8 combinations) to
settle whether reintroducing the literal `first` flag (which round 3 showed target
genuinely has, as a one-time pre-loop write) could be combined with the round-4 `ctx`
fix. It cannot: every combination that includes `first` as a real variable is either
worse (0x204+) or, at best, ties the no-`first` form (0x1f8) while losing the clean
push (reverts to a duplicate). The implicit `cur == chunk` form remains strictly
best despite not matching target's literal one-time-write shape in that one block -
a real, confirmed tradeoff, not an oversight.

Also went back to the `v30`/`v32` swap-pick block (the `moveq`/`movne` polarity flip
flagged as "probably just coloring" in round 4) with fresh attempts: rewrote it as
default-then-override statements (the documented ternary-vs-override lever) and as
two fully independent `if`/`else` blocks. **Both made the total size WORSE (0x1f4,
8 bytes under, vs the ternary form's 0x1f8, 4 bytes over)** - checking the disassembly
confirmed why: the EXISTING ternary form already compiles to the exact `movne r1,r2;
moveq r1,r3; strh r1,[r0,#0x40]` shape target has (single store, predicated register
select) - the override-statement rewrites instead produced predicated CONDITIONAL
STORES (`strhne`/`strheq`, two stores) because the destination is a direct memory
write, not a scalar local - the override lever's own precondition (a variable that
gets used again after selection) doesn't hold here. Round 4's diagnosis was right
that this specific residual is pure coloring, not a structural gap; confirmed by
this round's regression rather than assumed. Reverted these changes - current best
remains `scratch/FUN_022d5a64_BEST_dsi13.c` at 0x1f8 (4 bytes over 0x1fc), exact
register set, both blocks flagged in earlier rounds now individually verified
correct-shape-modulo-coloring rather than open questions.

### Round 6, same session: two hypotheses disproven directly, one real structural fix (exact total SIZE match, still not byte-identical)

**C++ member-function hypothesis, disproven.** Tested whether `FUN_022d5a64` is
actually a non-static C++ member function (`ConnMgrClass::FUN_022d5a64`, real
mangled symbol `_ZN12ConnMgrClass12FUN_022d5a64EjjPtjPv`, genuine implicit `this`
instead of the free-function `G_023190dc` global lookup) - compiled both forms
side by side at every opt level tried: byte-identical output. Member-function ABI
is not the missing piece; the free-function form is exactly as good.

**Full loop-body duplication, disproven.** The `first`-flag's role (round 3) is to
pick between reading the header from `&a1` on iteration 1 vs from `cur` on later
iterations. Tried the maximally literal reading of "target may not use a flag at
all, just duplicated code" by peeling iteration 1 out as fully separate source (own
`notify1` label, no shared boolean, `scratch/FUN_022d5a64_v19_fullpeel.c`): compiles
to **0x354, roughly 2x target's 0x1fc**. The compiler does not merge the duplicated
logic back down - proves target's real source shares the loop body via some flag
mechanism (the `cur == chunk` implicit test already in use), not literal duplication.

**subIndex shift-form fix - first-ever exact TOTAL SIZE match.** While auditing the
4-byte gap (a real arithmetic correction this round: earlier text in this file said
"2 bytes over" in several places - 0x1fc - 0x1f8 is actually 4 bytes / 1 whole
instruction, not 2 - fixed throughout), re-examined every remaining diff block for
an idiom-shaped residual rather than assuming it was pure coloring. Found one:
`subIndex = (hdr & 0xf00) >> 8;` (a direct arithmetic right-shift) was written where
target's real source apparently uses the shift-left-then-shift-right pair form -
`subIndex = ((hdr & 0xf00) << 8) >> 16;` - mathematically identical, but selects a
different instruction sequence (this is the exact same "shift-form idiom" class first
noticed on `FUN_022d5870`'s mask computation: an `asr`/direct-shift single instruction
vs an `lsl`+`lsr` pair). Applying the shift-left/shift-right pair form here **closed
the gap to exact total size, 0x1fc == target's 0x1fc**, for the first time this
function has ever hit its target size.

**Not byte-identical even at exact size**: `tools/match.py` still reports
`MATCHING VERSIONS: none`. Internally, the candidate decodes to 126 real instructions
vs target's 127 - a genuine 1-instruction content gap (not literal-pool padding),
concentrated in the first-loop-iteration entry block per a stack-offset audit (this
candidate uses 5 distinct stack slots - `[sp+0]`,`[sp+4]`,`[sp+8]`,`[sp+0xc]`,`[sp+0x10]`
- vs target's 3 - `[sp+0]`,`[sp+4]`,`[sp+8]`). Extended the round-5 grid search (more
`first`-reintroduction combinations, layered on top of the shift-form fix; forced early
`ctx` materialization via self-assignment; redundant-recompute splitting of the
`cur == chunk` test itself) - no combination improved past this point. **Current best
remains `scratch/FUN_022d5a64_BEST_dsi13.c`**, now updated with the shift-form fix:
exact register set, exact push/pop, exact total size (0x1fc), a real 1-instruction
content gap concentrated in the iteration-1 entry path, still not byte-identical.

### Round 7 - root cause of the 1-instruction gap identified precisely (via extern/ cross-reference tooling + raw disasm), still not fixed

Used `tools/cross_reference.py notes` to search extern repos' own codegen docs for
this residual's shape before guessing blind again - no direct hit, but it steered
toward re-reading the target's raw disassembly (`tools/disasm.py`, not the noisy
`fdiff --align` view) end to end, which found the real mechanism:

**The `cur == chunk` implicit test (this project's own best lever, section above)
is provably TRUE on the very first loop entry - mwccarm exploits that.** Since
`cur = chunk;` is assigned immediately before the loop, the compiler can statically
resolve the first pass's outcome and PARTIALLY PEELS the iteration-1 header-read
path (the `p = &a1; hdr = *p;` computation and its immediate consumers - the
`(hdr&0xff)`-derived `chunkLen`/flag-bit work) out of the loop into the function's
lead-in block, rather than leaving it as a runtime-tested branch inside the shared
loop body. Target's real source does NOT get this treatment: it uses a genuine
runtime-tested `first` flag (`mov r0,#1; str r0,[sp,#8]; b <loop-condition-test>`,
then `ldr r0,[sp,#8]; cmp r0,#1` inside the shared loop body, `first` cleared to 0
only inside the `first==1` arm, `hdr = *p` read unconditionally after) - a shape
this project's earlier grid search (round 5) never modeled exactly (it always
tested `first = 0;` written unconditionally after both arms, not conditionally
inside just the `if` arm, and `hdr = *p` duplicated in both arms rather than
hoisted after). Block-by-block delta accounting on `fdiff --align`'s output
(target[26:40] = 14 real instructions vs candidate[27:36] = 9) confirms this is
where essentially all of the net 1-instruction gap actually lives - everything
else in the 27 non-equal blocks is downstream coloring/scheduling noise from this
one structural difference, not independent content gaps.

**Two precise, well-targeted fixes tried against this exact mechanism, both
regressed:**
1. **Reproduce target's exact `first`-flag shape** (conditional-only reset inside
   the `if` arm, `hdr = *p` hoisted after the if/else instead of duplicated inside
   both arms - `scratch/FUN_022d5a64_v21_hoistread.c`). Regressed to 0x208 (129
   instructions, +2 vs target): reintroducing `first` as a named variable at all
   costs a register regardless of the precise internal shape (candidate's push set
   grew to 10 registers, `r3` included, vs the correct 9) - this reconfirms round
   5's finding from a different angle rather than escaping it. The register-cost
   problem and the peeling problem are apparently two independent costs of the same
   underlying tension, and fixing the peeling by bringing `first` back doesn't
   avoid paying the register cost.
2. **`unsigned short * volatile cur`** (defeat the compiler's static proof that
   `cur == chunk` on first entry, the same "volatile-in-condition defeats CSE per
   branch arm" lever sm64ds-decomp's own notes document for an analogous case -
   `scratch/FUN_022d5a64_v22_volatile_cur.c`). Regressed heavily, 0x214: volatile
   on the whole pointer forces a reload at every one of `cur`'s several uses
   through the function, not just at the peeling-triggering comparison - far too
   blunt an instrument for this specific case.

**Not resolved.** The mechanism is now understood precisely (a genuine, nameable
compiler behavior - static branch-outcome peeling on a provably-true first-loop-
entry condition - not a mystery), which is real progress over "1-instruction gap,
location unknown" from round 6, but no source-level phrasing tried yet avoids
paying either the register cost (reintroducing `first`) or the peeling cost
(keeping `cur == chunk`) simultaneously.

### Round 8 - direct instruction from the user to reach byte-exact; ~12 more variants, a full permuter run, and a second independent micro-issue found - still not matched

Per explicit direction that this must reach 100%, not be banked as a documented
near-miss. Tried every remaining angle that could be reasoned about concretely
rather than guessed blind:

**The narrower volatile-barrier idea from round 7's "next steps" - tried, also
too blunt.** `*(unsigned short * volatile *)&cur == chunk` (a scoped volatile
read of `cur`'s value at only the comparison site, not qualifying `cur` itself -
`scratch/FUN_022d5a64_v23_volread_cmp.c`). Regressed to 0x214, identical to full
`volatile cur`: taking `&cur` at all forces the variable out of register
allocation for the WHOLE function (address-taken locals can't live purely in a
register on this compiler), not just at the read site - the same cost as full
qualification, just reached by a different route.

**Manually writing the peel as a `goto` instead of relying on `cur == chunk` to
trigger it implicitly** (`scratch/FUN_022d5a64_v24_gotopeeled.c`: read `&a1`
directly before the loop, `goto` into a label inside the loop body, no comparison
at all). Regressed further than expected - 123 instructions (candidate now SHORT
by 4, not just 1) and the register push grew to 10 (`r3` included) anyway. Tried
consolidating the duplicated `val = 0xFFFF` into the shared label instead of
before the goto too (`v30_gotopeeled_v2.c`) - made it dramatically worse in a
different direction (119 instructions but 12 registers pushed, the compiler
apparently choosing to keep MORE state live in registers across the whole
function once the code got shorter). Neither goto variant beats the implicit
`cur == chunk` form.

**`volatile int first` retested now that the shift-form fix (round 6) is in
place** (round 5's grid search predates that fix). Two internal shapes tried,
both land at exactly 0x208 regardless: the original round-3 shape (`first = 0`
unconditional after the if/else, `hdr = *p` duplicated in both arms -
`v25_volfirst_plus_shiftfix.c`) and the more precise target-matching shape
(conditional-only reset, hoisted read - `v26_volfirst_hoistread.c`). Declaration
position of `first` (top of the variable list vs its original position -
`v27_volfirst_declfirst.c`) also made no difference. `volatile`'s forced-real-
memory-op semantics apparently make these C-level orderings equivalent to the
compiler - it was worth checking given the shift-fix interaction was genuinely
untested, but the answer is a clean, confirmed no.

**Representation swap: track position via an integer byte offset (`off`) instead
of a raw pointer (`cur`), testing `off == 0` instead of `cur == chunk`**
(`scratch/FUN_022d5a64_v29_offset.c`) - on the theory that a constant-vs-variable
comparison might dodge the same static-peeling treatment a pointer-identity
comparison gets. It doesn't: regressed to 0x208, confirming the peeling
optimization keys on "is this value's precise content known at this program
point," not on the compared value's type or shape.

**Compiler-help-driven levers, both tried:** the compiler's own `-help
opt=option` text ties "loop transformations, loop-invariant code motion"
specifically to level 3+, suggesting level 1/2 might dodge the peeling entirely.
- All 15 individual `-opt [no]cse/deadcode/deadstore/lifetimes/loopinvariants/
  prop/strength` toggles, standalone, against the `BEST_dsi13.c` base - zero
  byte-level effect on every single one (same signature already established for
  `FUN_022d5870`'s wall - this compiler build's peephole/front-end folding
  clearly isn't gated by any of the named, documented optimization passes).
- `-opt level=1,space` / `level=2,space` / `-O1,s` / `-O2,s` - levels 1 and 2
  regress badly (0x230, more registers spilled, the compiler apparently needing
  higher opt levels just to reach the already-established 9-register baseline);
  level 2 alone reproduces `-O4,s`'s exact byte output (126/127, same 27 diff
  blocks) - the peeling happens even at the lowest level that still hits the
  right register count, confirming it's baked into basic constant propagation /
  dead-branch folding, not the documented level-3+ "loop transformations" pass
  specifically.
- u64-mask laundering (section 6h) applied to the `cur = chunk` assignment
  itself, not a derived pointer (`scratch/FUN_022d5a64_v28_launder_curinit.c`) -
  zero effect, this build folds the all-ones mask away here too, consistent with
  every other laundering attempt on this project so far.

**decomp-permuter, 300s / 3557 iterations, seeded from `BEST_dsi13.c`**
(`tools/permuter/import_func.py` + `winproc.py --secs 300`). Best score plateaued
in the 9600-12700 range with error count climbing monotonically (36 -> 44) over
the run, never trending toward 0 or converging - the identical non-convergent
drift signature already documented for `FUN_022d5870`'s permuter runs (rounds 4
and 8 there). Confirms this residual is still scored in the structural
(insertion/deletion) tier, not pure coloring, despite the exact-size/near-exact-
instruction-count property that made it look promising - the permuter cannot
resolve a genuine content/structure difference by shuffling statements.

**A second, independent micro-issue found and investigated (not the peeling
issue - a different block entirely), still open.** `fdiff --align`'s per-block
delta accounting (candidate_count - target_count summed across all 27 blocks)
confirms the entry-peeling region is NOT the only source of the net -1 instruction
gap - several smaller blocks elsewhere also contribute, netting the total. One
specific block in the mask/ack-window comparison (`val = (unsigned short)(val <<
1); if ((unsigned short)(existing - val) < 0x100)`) shows target using an
UN-fused `lsl r7,r7,#1` + `sub r3,r3,r7` pair (2 plain instructions, truncating
only the SUBTRACTION result afterward) while every phrasing tried here either:
(a) reproduces that exact unfused shape but with an extra truncation-pair
overhead (`val`'s assignment truncating `val<<1` a beat too early - the original,
`BEST_dsi13.c`'s shape), or (b) lets mwcc's peephole FUSE the shift directly into
the subtract's shifter operand (`sub ip,r0,r8,lsl #1` - single instruction,
shorter than target) the moment the shifted value is used inline in the
subtraction rather than stored to a real variable first, even when routed
through a freshly-named `int` temp (`v31_deferred_trunc.c`, `v32_named_shifted.c`
- both land at 0x200, an even worse regression, confirming naming a temp does not
block this specific peephole on this compiler). Grepped extern repos' real
matched C source (not just docs) for this "windowed sequence-number comparison"
idiom (`(u16)(a-b) < threshold`, a recognizable networking pattern) looking for
a real precedent of the unfused shape - no exact hit in twewy/fe11-us/khdays-
decomp/sm64ds-decomp's checked-out source.

**Where this leaves it, honestly:** ~34 total source variants across 8 rounds
this session, a full 15-flag pragma sweep, 4 opt-level points, one u64-laundering
attempt on every plausible target, and a 3557-iteration permuter run - the widest
search this project has run against any single residual. `BEST_dsi13.c` remains
the best candidate: exact register set (13/13), exact push AND pop, exact total
size (0x1fc), 126 vs target's 127 real instructions, two independently-diagnosed
but unresolved micro-mechanisms (first-iteration branch peeling; a shift/subtract
fusion-vs-truncation tension in the ack-window compare). Not byte-identical.
Genuinely untried next steps, in rough order of promise: (1) let the permuter run
substantially longer (hours, not 300s) on the theory that its non-convergence at
3557 iterations doesn't rule out a later basin - the project's own crack-loop
precedent treats 800 iterations as a floor-confirmation bar, not an upper bound;
(2) a combinatorial declaration-order + structural-axis sweep in the style of
`tools/frame_search.py`, scoped to this function's specific variables, rather
than the hand-picked single-axis changes tried so far; (3) clone and grep a wider
set of extern repos' real matched source (not just the 13 currently registered)
for the exact unfused shift-subtract-truncate shape.

### Round 9 - the `first == 1` polarity fix (real), a properly-scoped/reloc-fixed permuter search (clean negative), and the precise register-competition mechanism identified by hand

**Real, verified fix: `if (first == 1)` instead of `if (first)`.** Re-reading the
target's predicated prologue instruction-by-instruction (`cmp r0,#1` / `streq` /
`addeq`, not `cmp r0,#0` / `strne`) showed target's C almost certainly spells the
test as an explicit `== 1` comparison, not idiomatic truthiness - `if (first)`
compiles to `cmp r0,#0` (wrong immediate/polarity), `if (first == 1)` compiles to
`cmp r0,#1` with the predicated arms in the SAME order as target. Confirmed
byte-for-byte on the predicated block itself. This is now the correct base for
any `first`-based draft, even though (see below) it alone doesn't close the gap.

**Reference-repo search, done properly this time - a real, decisive negative, not
inconclusive.** Grepped `notes/mwccarm-codegen.md` across all 13 registered repos
for every "spill" mention (not just keyword-matched phrases) and found two
genuinely on-point levers: 6r (`#pragma opt_propagation off` keeps a 0/1 selector
stack-resident) and the `ok++`-vs-`ok=1` update-form lever (2140). Retested both
against the corrected `first == 1` base - zero effect, cleanly. Section 6k
("declare the spill victim dead-last, competing locals in reverse-register order")
was the most specific hit in the whole corpus; swept all 12 orderings of the six
other competing pointer locals with `cur` pinned last - **all 12 compiled to the
identical result**, a clean negative, not a partial improvement.

**The actual mechanism, found by hand-tracing every register in the target
disassembly (not inferred): this was never really about forcing `cur` to spill in
isolation - it's a straight competition between `cur` and `index` for the same
register (`sl`), and the two builds pick different losers.** Enumerating target's
full register set instruction-by-instruction gives exactly 8 persistent
(register-resident) values - `r4`=typeFlagBase, `r5`=conn, `r6`=chunkLen,
`r7`=val-sentinel, `r8`=slot, `sb`=len, `sl`=index, `fp`=subIndex - matching this
project's own 8 non-`cur` "hot" variable names 1:1. `cur` is the genuine 9th
competitor, and target's allocator spills IT (reloading from `[sp+0]` via a fresh
`ldr` at each use - including reading the same slot via two separate `ldr`
instructions back-to-back for two different purposes, the redundant-recompute
idiom again, not cached in one register and reused). Every candidate compiled
here does the opposite: keeps `cur`/`chunk` in `sl` and spills `index` instead
(confirmed via a direct `ldr r1,[sp,#4]` right before `index`'s one late use in
the notify block) - a different but equally valid 8-registers-plus-1-spill
resolution of the same 9-way pressure, just with the two builds' allocators
picking a different loser.

**Six more concretely-targeted techniques tried against this specific
competition, all negative:**
1. Decoupling `index`'s one late reuse (`pkt[9] = index`) into a fresh local
   (`idx = index` right after the guard clause, use `idx` at the late site) - no
   effect on register assignment at all.
2. Moving `cur = chunk`'s initialization from the very top of the function to
   just before the loop (matching target's own prologue, which initializes
   `chunk`→`[sp+0]` LAST among the parameter shuffling, not first) - no effect;
   confirms this specific allocator decision isn't driven by simple textual
   statement order (plausible for a full-function liveness/interference-graph
   allocator rather than a greedy left-to-right one).
3. Forcing the redundant-read pattern explicitly at the C level
   (`pktSrc = cur; p = pktSrc + chunkLen;` instead of deriving `p` from `cur`
   directly) - mwcc's CSE saw through the syntactic decoupling and merged the
   values back into one register anyway; textual restructuring alone doesn't
   defeat value-based CSE on this compiler.
4. `cur` as a 1-element array (`unsigned short *curArr[1]`, all uses rewritten to
   `curArr[0]`) - the sm64ds-documented "stack-resident constants are a local
   ARRAY, not volatile locals" lever. This compiler promotes small arrays back to
   registers via SROA just as readily as the single-member struct tried earlier
   (round 8) - no effect, identical register assignment.
5. `register` storage-class hint on the `index` parameter specifically (not
   previously tried on this exact parameter, only on locals elsewhere this
   project) - ignored, as already established for every other `register` hint
   tried at `-O4` this session.
6. An explicit `ctx = ctx;` self-assignment right after `conn`'s setup, matching
   a genuinely separate real difference spotted in target's prologue (target
   loads the stack-passed `ctx` arg and immediately stores it back at
   `[sp+0x40]`, very early - my candidates defer `ctx`'s only real access to its
   actual use site deep in the notify block). This DID reproduce target's exact
   early load-then-store-back shape when checked directly - a second, genuinely
   separate confirmed micro-fact about target's structure - but cost 2 more
   instructions elsewhere (0x210) and, critically, is independent of the
   `sl` competition (`cur`/`chunk` still won `sl` over `index` even with this
   applied). Worth keeping for a future combined draft; doesn't fix this
   residual alone.

A combinatorial sweep of all 8 combinations of (idx-decouple x cur-late-init x
early-ctx) was run to check for an interaction effect none of the single-axis
tests would show. The first pass appeared to find a real improvement (0x204,
better than the 0x208 floor every single-axis attempt had hit) - **this was
a bug, not a result**: the sweep script's second string replacement silently
failed to match after the first had already edited the text, so the generated
candidate was missing `cur`'s initialization entirely (a real, uninitialized-
variable correctness bug that happened to compile smaller). Caught by checking
`"cur = chunk;" in text` on the generated candidate before trusting the number,
fixed the sweep to compose edits via non-overlapping anchors, and reran: **all 8
combinations, correctly composed, land on 0x208 or worse - no interaction effect
exists between these three specific axes.** Flagging the false lead explicitly
here since this file is the project's record of what's actually been ruled out -
an uncaught version of this bug would have wrongly closed off this combination
space as "tried and failed" when the real (buggy) candidate was never a valid
C program to begin with.

**A properly-scoped, correctly-scored permuter run - clean negative, highest
confidence result yet.** Two real problems with the prior permuter attempts were
found and fixed this round: (1) `tools/permuter/import_func.py`'s
`candidate_reloc_offsets()` compiled the raw seed directly to detect which byte
offsets are relocations (to wildcard during scoring) - a seed containing
`PERM_GENERAL`/`PERM_RANDOMIZE` macros isn't valid C on its own, so that compile
silently failed and fell back to an empty reloc list, meaning the scorer
compared 3 link-address-dependent words strictly instead of wildcarding them -
an unreachable floor above 0 baked into every prior PERM-macro-based run's score
(confirmed concretely: baseline score went from ~10915-11055 under the bug to
~9745 after the fix - a large, real difference). Fixed by expanding PERM_ macros
to one concrete candidate via decomp-permuter's own parser
(`src.perm.parse.perm_parse` + `EvalState`, seed=0) before falling back to a real
compile error - now a committed fix, not a one-off workaround. (2) Rather than
mutating the whole function (diluting search effort across code that already
matches) or hand-enumerating a fixed set of alternatives (limited by what a human
thinks to write), wrapped just the `first`/`cur` test region in `PERM_RANDOMIZE`
- real random mutation, concentrated entirely on the ~15 lines that are actually
wrong. Ran for the full 1200s budget: 16,377 iterations, best score plateaued at
8240, error count non-convergent (climbing 37→38 across the run) - no match
found. ~~This is the most rigorous, correctly-configured search run against this
residual to date~~

**Correction (found next round): that search was NOT correctly configured after
all - a second, more consequential `tools/permuter/import_func.py` bug meant it
never actually tested this project's real iteration baseline.**
`setup_dir()` computed the permuter's compile flags via `flags_for(module, mode)`
alone, which only knows arm7-vs-arm9 and arm-vs-thumb - it never applies the
seed's own `// flags: ...` marker the way `match.py`/`fdiff.py` both do via
`apply_flags_marker()`. Since this whole investigation's structural wins (exact
register set, exact push/pop, exact total size) all specifically require
`-O4,s` rather than the default `-O4,p`, and the seed's `// flags:` marker was
never being read, **the 16,377-iteration run above was silently compiled and
scored entirely at `-O4,p`** - a genuinely different compiler configuration from
the one every other conclusion in this document is based on. Confirmed directly
by inspecting the generated `flags.txt` for that run's working directory before
the fix (showed `-O4,p`) and after (showed `-O4,s`, matching the seed's marker).
This also revealed the seed file's own `// flags:` marker was itself incomplete
(only `-noThumb`, missing the `-O4,s` override this whole investigation depends
on) - fixed alongside `BEST_dsi13.c`'s matching marker gap.

Fixed `import_func.py` to apply `apply_flags_marker()` (committed, PR #41) and
re-ran the identical scoped `PERM_RANDOMIZE` search under the corrected `-O4,s`
baseline: base score 5145 (vs the invalid run's ~10915-11055 - confirming the
configurations really were different, not just a scoring-noise difference), full
1500s budget, 13,646 iterations, error count settled at 24 (still nonzero, still
non-convergent), best score 4155. **Still no match** - so the qualitative
conclusion (this residual is not permuter-reachable via random mutation) holds,
but now on a genuinely correctly-configured run rather than the flawed one
originally reported. Worth remembering: a permuter "negative result" is only as
trustworthy as its import configuration - check the generated `flags.txt`
against the seed's own marker before trusting a non-convergent run as meaningful
evidence, not just the seed's compile-success/failure.

**Where this leaves it.** The mechanism is now understood with real precision
(a straight `cur`-vs-`index` competition for one register, not a vague "cur needs
to spill" framing), one genuinely new fix was found and banked (`first == 1`
polarity), a second real micro-fact was confirmed (`ctx`'s early materialization
shape), and a serious permuter tooling bug was found and fixed (benefits any
future PERM-macro-based work on any function, not just this one). Despite all of
that, no combination of source-level techniques tried - across roughly 60
variants total this investigation, spanning every lever this project and its 13
reference repos document for register-allocation steering - has flipped which of
`cur`/`index` the allocator spills. This is now the most thoroughly searched
single residual in this project's history (matching sm64ds-decomp's own
"believed impossible, has been swept" category for comparably-resistant coloring
walls). Not matched. Best candidate remains exact register SET (13/13), exact
push/pop, exact total size (0x1fc) - everything except the literal final bytes.

## 3b. `FUN_022d5540` - first real translation, closest first-attempt result this
session, plus a real `match.py` methodology bug found and fixed

The third and largest of the `FUN_022ce8b0` callee cluster (0x328/808 bytes,
arm7), never translated to C before this round - earlier notes only had a
Ghidra-summary read (unreliable, transcribed from memory) and an `m2c` draft
(explicitly not a matching candidate). Picked up on the theory that a fresh,
simpler-in-parts function might surface the same register-allocation lever the
`FUN_022d5a64` wall (section 3a) needed, in a cleaner setting.

**Method: traced the target's full 202-instruction raw disassembly
(`tools/disasm.py`) end to end by hand before writing any C**, the same lesson
learned partway through the `FUN_022d5a64` investigation, applied from the start
this time. This resolved a real ambiguity the earlier notes had flagged: of the
"ten mysterious 0xFFFF sentinel stack slots" noted as needing consolidation
before translating, nine turned out to just be the literal constant `0xFFFF`
redundantly re-materialized at different comparison/write sites (the same
redundant-recompute idiom already established this session) - not real distinct
source variables. Only one slot holds a genuine persistent value.

**First compile, no iteration: 0x340 vs target's 0x328 (24 bytes over) - and the
register push set already matched target's exactly** (`r4,r5,r6,r7,r8,sb,sl,fp,
lr`, 9 registers) on the very first draft. Substantially better than either
sibling function's first real attempt this session (`FUN_022d5a64`'s first
serious draft was 88 bytes over AND had the wrong register count) - directly
attributable to hand-tracing the disasm before writing C rather than iterating
from a summary.

**Two real structural mechanisms identified, both partially or fully
independent of the sibling functions' known walls:**

1. **LICM (loop-invariant code motion) hoists `queueHeadBase`/`typeFlagBase`
   computations out of the outer 4-queue loop and spills them to stack slots**,
   even though the source writes them freshly inside the loop body (matching
   target's own apparent redundant-recompute-per-iteration shape) - mwccarm
   proves they don't depend on the loop counter and hoists them anyway, then
   pays a spill/reload cost across the loop's 4 iterations since their live
   range now has to survive the whole loop instead of one pass. Every
   documented `-opt` pragma lever tried against this (`noloopinvariants`,
   `nocommonsubs`, `nocse`) had zero effect, consistent with this compiler
   build's established pattern of ignoring named optimizer-pass toggles
   entirely. Removing the affected variables as named locals and inlining
   `conn + <offset>` directly at each use site DOES defeat the hoist (closest
   raw byte count found, 0x330/8 over) but costs an extra pushed register
   (`r3`, confirmed not actually live across either function call in this
   candidate - the same "conservative extra register instead of a stack spill"
   pattern found on `FUN_022d5a64`'s `cur`/`index` competition). Banked the
   safer variant instead: inlining `freelistBase` alone gets most of the same
   benefit while preserving the exact 9-register push set.
2. **`prevIdx` and `firstKept` both spill to stack in every candidate tried;
   target keeps `prevIdx` (written+tested every inner-loop iteration) in
   register `sb` and spills only `firstKept` (write-once, read-once-after-the-
   loop)** - a second, independent instance of the same "which of two
   competing variables does the allocator spill" question `FUN_022d5a64`'s
   wall never resolved. Declaration-order swap and relieving pressure by
   inlining the unrelated `tailStruct` pointer both had zero effect. Given the
   dedicated effort that specific question resisted on `FUN_022d5a64`, not
   pursued further here without a new idea - now THREE independent instances
   of this exact class of allocator behavior across this session
   (`FUN_022d5870`'s original coloring wall, `FUN_022d5a64`'s `cur`/`index`,
   this function's `prevIdx`/`firstKept`), reinforcing that it's a genuine,
   consistent property of this compiler build rather than something any one
   function's source is doing wrong.

**A real `match.py` invocation bug found and fixed mid-investigation (full
writeup in `notes/tooling.md`'s "sharper version of the same trap" entry) -
flagged here too because it directly changed this function's own numbers.**
Passing `--flags` on the CLI replaces the
complete default flag set, not just the token you meant to override; this
session's habit of typing an abbreviated `--flags "-O4,s -noThumb"` during
iteration silently dropped `-lang c99`/`-proc arm7tdmi`/`-gccext,on`/others for
every test. Most functions don't care - this one did: under the complete flag
set, the epilogue changes from an (incorrect, coincidentally byte-saving)
folded `pop {...,pc}` to the correct separate `pop {...}` + `bx lr` matching
target - a real, structural 4-byte difference that had been silently baked into
an entire round of "0x33c" measurements before being caught. Corrected figure
is 0x340 (24 bytes over), with the epilogue now genuinely, not
coincidentally, matching target. Spot-checked `FUN_022d5a64`'s own
`BEST_dsi13.c` under the same bug - confirmed unaffected (identical result
either way, because every abbreviated invocation of that file happened to
still include the one override, `-O4,s`, that actually mattered for it) - but
fixed both files' `// flags:` markers to include `-O4,s` explicitly so future
work can safely omit `--flags` entirely rather than depending on remembering
to re-type it correctly every time.

**Round 3d - the "spill slots grouped by TYPE" lever (sm64ds section, `func_020319fc`)
tried against `prevIdx`/`firstKept`, a second permuter tooling bug found and
fixed, then a properly-configured scoped search - still not matched.**

sm64ds-decomp's own notes document a real case where a stack-slot-ordering
residual was fixed purely by changing a local's declared type
(`unsigned int` -> `int`, "signed/unsigned was pinning the slot grouping") -
untried on this project's own `prevIdx`/`firstKept` question until this round.
Swept 9 combinations (`int`/`unsigned int`/`short`/`signed short` crossed
against the original `unsigned short`, both orders) - every combination is
either identical to the `unsigned short`/`unsigned short` baseline (0x340) or
measurably worse (up to 0x368 for `signed short`/`signed short`); none improve
on it. This specific lever doesn't transfer to this specific pair, joining
declaration-order, inlining, and address-taking/volatile as techniques that
have now all failed against this exact competition.

**A second, more consequential `import_func.py` bug found while setting up a
scoped permuter search for this function** - the same root cause already
documented in section 3a's correction above (`setup_dir()` never applies the
seed's `// flags:` marker, so every permuter import silently used `-O4,p`
instead of the `-O4,s` this whole investigation's structural wins depend on).
Fixed once, generally, in `import_func.py` (PR #41) - benefits every future
permuter import on any function, not just this one or `FUN_022d5a64`.

With the corrected `-O4,s` baseline, wrapped both of this function's own
unresolved regions - the `queueHeadBase`/`typeFlagBase`/`firstKept`/`prevIdx`
per-queue setup block, and the `prevIdx`/`firstKept` update block inside the
inner loop - in `PERM_RANDOMIZE` and ran the full 1500s budget: 16,390
iterations, error count climbing to 147 (non-convergent), best score 4180 (down
from a base ~5630, but nowhere near 0). Inspected the single best-scoring
candidate directly: a plausible but minor mutation (factoring `queueHeadBase +
q*4` into one shared temp reused for both `cur`'s dereference and `qhead`'s
assignment, and chaining `firstKept = (prevIdx = 0xFFFF)`) - not a real
structural insight, not close to a match. **Still not matched.**

**Where this leaves it**: `scratch/FUN_022d5540_BEST.c` - exact register push
set (9/9), exact epilogue (verified structurally correct, not a size
coincidence), correct overall control flow (verified against a full hand-trace,
not guessed). 0x340 vs target's 0x328, 24 bytes / 6 instructions over,
concentrated entirely in the two mechanisms above, both now confirmed resistant
to every technique tried (type-based, declaration-order, inlining, and a
correctly-configured scoped random search). Not matched, but the strongest
first-attempt result any of this cluster's three hard functions has had this
session, and now with the SAME residual-class confirmation across all three
(`FUN_022d5870`'s original wall, `FUN_022d5a64`'s `cur`/`index`, this function's
`prevIdx`/`firstKept`) under properly-configured tooling rather than a mix of
valid and invalid measurements.

**Round 3e - a genuinely new axis: sweeping `dsi/*` POINT RELEASES (not just the
already-ruled-out `2.0/*` vs `dsi/*` FAMILY distinction) against this specific
function - found a real, reproducible, function-specific 4-byte win.** This
project vendors 9 distinct `dsi/*` builds (`1.1`, `1.1p1`, `1.2`, `1.2p1`,
`1.2p2`, `1.3`, `1.3p1`, `1.6sp1`, `1.6sp2`) - every prior version-sensitivity
check this session (the `2.0/*`-vs-`dsi/*` sanity check early on, `FUN_022d5870`'s
own round-7 `--all` sweep) only ever tested `dsi/1.3` within this specific point
range, treating the whole `dsi/*` line as interchangeable once the FAMILY was
confirmed correct. It isn't, for every build: `dsi/1.1` alone compiles
`FUN_022d5540_BEST.c` to 0x33c instead of every other version's 0x340 - a real,
reproducible 4-byte/1-instruction improvement, with the exact register set and
exact epilogue both still preserved. Sanity-checked this isn't a general
"`dsi/1.1` is just better" effect: swept all 9 versions against both
`FUN_022d5a64`'s `BEST_dsi13.c` and `FUN_022d5870`'s `v13.c` too - byte-identical
across all 9 versions for both (confirming `FUN_022d5870`'s own earlier `--all`
finding extends to the point-release granularity, not just the major-family
one) - so this specific win is real but function-specific, not a blanket "switch
the pinned version" fix.

Re-ran the inline-variable sweep (`queueHeadBase`/`typeFlagBase`/`freelistBase`)
and the `prevIdx`/`firstKept` type-sweep from rounds 3c/3d under `dsi/1.1`: the
whole shape of both sweeps is IDENTICAL to the `dsi/1.3` results, just uniformly
4 bytes better across every combination - including the `queueHeadBase`-inlined
variant, which STILL costs the same extra register (`r3`) under `dsi/1.1` as it
does under every other version (checked directly). So `dsi/1.1`'s win is a real,
separate, additive fix for something else entirely in the function (traced to
one specific block - the `entry[4] |= ...; entry[3] &= ~entry[4];` compound
update, where target does a genuine redundant fresh reload of `entry[4]` after
storing it and `dsi/1.3`'s candidate lets CSE cache the just-computed value
instead) - it does not touch either of the two already-identified structural
mechanisms, which persist unchanged under the new baseline. Tried forcing the
redundant reload explicitly at that spot via a `volatile`-cast read
(`*(volatile unsigned short *)&entry[4]`) to see if that lever, not the version
switch, was the real fix - regressed `dsi/1.1` back to 0x340 (undoing its own
natural win) while leaving `dsi/1.3` unchanged at 0x340, confirming `dsi/1.1`
was already doing the right thing on its own and the volatile cast was a
net-harmful, unnecessary intervention once the better version is used as the
base.

**New best**: `scratch/FUN_022d5540_BEST.c` compiled against **`dsi/1.1`**
(not `1.3`) - 0x33c vs target's 0x328, 20 bytes over (down from 24), same exact
register set and epilogue, with the two already-documented structural
mechanisms as the sole remaining content. Worth remembering as a general lever
for any future hard-residual work on this project: don't assume the pinned
`dsi/1.3` is uniformly representative of the whole `dsi/*` line just because the
`2.0/*` family was ruled out - sweep the individual point releases too, cheaply
(9 versions x one `match.py` invocation each), before concluding a residual is
version-independent.

**Round 3f - searched the full `dsi/1.1` diff for more instances of the same
"CSE ate a redundant reload" pattern; found a different-shaped difference
instead (predication polarity), confirmed it's not independently fixable from
source.** Generated the complete `--align --align-max-blocks 0` diff of
`FUN_022d5540_BEST.c` against target under the new `dsi/1.1` baseline (42
non-equal blocks) and read through it end to end. Most blocks are either
register-coloring noise or the already-documented `queueHeadBase`/
`typeFlagBase` LICM+spill block (visibly the single largest block in the
diff, `target[37:37]` vs `candidate[37:49]` - target hoists these two
pointers once before the loop and keeps them live across all 4 iterations;
candidate, in the freelistBase-inlined shape, recomputes them from spilled
stack slots every iteration). No second "redundant reload" spot was found.

One new-shaped block did stand out: the `(entry[1] & 8) == 0 && entry[9] ==
0` short-circuit (`if (...) goto notify;`, guarding the "already queued,
nothing to do" fast path) compiles on target as a 6-instruction predicated
sequence (`ldrh`; `tst r0,#8`; `ldrheq`+`cmpeq`+`beq` - the second half of
the condition executes under condition code rather than behind a branch),
but on the candidate as a 7-instruction branchy sequence (`ldrh`; `tst`;
`bne`; `ldrh`; `cmp`; `beq`) - one extra instruction, a real byte-for-byte
difference, not just coloring. This has the same shape as the `first == 1`
predication-polarity fix banked for `FUN_022d5a64` (section 3a) - a plausible
new lever. Tested it: rewrote the condition three ways (`(a==0) &
(b==0)` bitwise-AND instead of `&&`, to remove short-circuit semantics
entirely; nested `if (a==0) { if (b==0) goto notify; }`; and the original
`&&`) - **all three produced byte-identical machine code**, confirmed via
direct hex-dump diff of the `tst r0,#8` region, not just matching total size.
Unlike `FUN_022d5a64`'s `first == 1` fix (a real, source-visible comparison
polarity), this one doesn't respond to any source-level restructuring -
mwcc's if-converter is making the branch-vs-predicate call here based on
something outside the condition's own syntax (most likely the same
register/scheduling pressure behind the `prevIdx`/`firstKept` competition
wall, given its proximity in the loop body), not a fixable idiom mismatch.
Recorded as a negative result rather than silently dropped, per this file's
purpose as a record of what's actually been ruled out.

No further progress this round. `FUN_022d5540`'s remaining 20-byte gap under
`dsi/1.1` is now attributable entirely to the two already-identified
structural mechanisms (LICM+spill, `prevIdx`/`firstKept` register
competition) plus this newly-confirmed-unfixable predication difference -
three symptoms, all consistent with a single underlying register-allocation/
scheduling floor rather than three separate bugs to chase independently.

**Round 3g - swept the full mwccarm flag space (not just `-O`/version) looking
for a missed compiler option, per a direct user question. Ruled out the whole
remaining flag surface; along the way, corrected a wrong claim about this
project's match state.** Dumped the complete `-help all,obsolete,...` listing
from `mwccarm.exe` and tested every option plausibly relevant to codegen
shape against all three hard residuals (`FUN_022d5540`, `FUN_022d5a64`,
`FUN_022d5870`):

- `-opt` per-pass toggles (`[no]cse`, `[no]loopinvariants`, `[no]lifetimes`,
  `[no]prop`, `[no]strength`, `[no]deadcode`, `[no]deadstore`) - **byte-
  identical to baseline in every case**, confirmed even against a probe
  function hand-written to trigger CSE (`x=a+b; y=a+b;`). Not a testing bug:
  the compiler's own `-help` text says so directly - "all options besides
  `-opt off|on|all|space|speed|level=...` are for backwards compatibility;
  other optimization options may be superceded by use of `-opt level=xxx`."
  At `-O4` these suboptions are inert stubs. Worth banking so nobody re-tries
  this specific idea later.
- `-proc` (target core) swept across all ~25 values. Real, reproducible
  signal: a cluster of cores (`v5t`, `arm7ej`, `arm1020e`, `arm1022e`,
  `arm1026ej`, `XScale`, `pxa255`) all land on the same 4-byte-better result
  for `FUN_022d5540` (0x338 vs the `-proc arm7tdmi` baseline's 0x33c) -
  consistent across unrelated core families, not noise - while `v6`/`v6t2`/
  `v7` make it worse (0x344) and several others regress relocation handling
  in our own diff tooling entirely (a different literal-pool addressing
  sequence throws off `fdiff`'s patch-in-the-resolved-address logic - a
  tooling limitation, not evidence either way about the code). None reach a
  match on any of the three functions. Since the DSi's ARM7 core is
  definitively an ARM7TDMI in real hardware, and even the best alternate
  core only closes 4 of 20 bytes, this reads as further evidence of a real
  register/scheduling floor rather than a wrong `-proc` value.
- `-pic`, `-pid`, `-constpool`/`-noconstpool`, `-ipa file`, `-align8` - no
  effect on any of the three functions.

While regression-checking these flag changes, tried to find already-verified
arm7 matches to test against and initially misread `progress/matched.jsonl`:
every arm7 record (and nearly every record project-wide) carries the version
tag `sync:marker`, which I wrongly concluded meant "hand-written asm only,"
leading me to (incorrectly) tell the user arm7 had zero real-compile
verified matches anywhere in the project. That was wrong, and worth
recording as a correction per this file's own honesty standard: `sync:marker`
just means "banked via the bulk-sync tool using the file's own `// decomp:`
marker for verification," and covers genuine compiled C matches as well as
asm stubs. Direct proof: `src/arm7/FUN_022c59a4.cpp` (a real, non-trivial
doubly-linked-list unlink, no asm) matches byte-exact on **all 22** tracked
compiler versions once compiled with the correct arm-mode flags (my first
attempt used the wrong ones - `tools/match.py --c` doesn't know a given
file's ARM/Thumb mode unless the file's own `// flags:` marker says so or
`--flags` is passed explicitly; `FUN_022c59a4.cpp` has neither, so it
silently thumb-compiled by default and looked like a fail). This is good
news for the project as a whole: it confirms the standard baseline
(`-O4,p`/`-O4,s`, `-proc arm7tdmi`, the rest of `DEFAULT_FLAGS_ARM7`) does
produce genuine byte-exact matches on real arm7 logic, so the three hard
residuals' gap is a narrow, real edge case, not a symptom of an unproven or
wrong project-wide compiler configuration.

**Net effect of this round**: the compiler-flag search space is now
exhausted for these three functions - `-O` level/space-speed and dsi
point-release (section 3e) are the only flag-level levers that did anything,
and both are already applied in the current best candidates. Further
progress here most likely requires either the unread `sm64ds-decomp` notes
sections (section 4) or accepting these three as a documented floor for now.

**Correction (round 3h, immediately below): "exhausted" above was about the
CLI `-opt` surface specifically. `#pragma opt_*` directives are a distinct
mechanism this round didn't test and turned out to matter.**

## 3h. `#pragma opt_*` is a genuinely different lever from `-opt` on the CLI -
found via sm64ds-decomp's notes, real movement on `FUN_022d5540`, no match

Read `sm64ds-decomp/notes/mwccarm-codegen.md` sections 6c/6d/6e/6f/6g (not
previously consulted by this project) per the "where to look next" pointer.
Section 6f is explicit and, per this project's round 3g, easy to miss: the
CLI `-opt nocse`/`-opt noloopinvariants`/etc. tested in round 3g are inert
because they're "superceded by `-opt level=xxx`" (mwccarm's own words) - but
`#pragma opt_common_subs off`, `#pragma opt_propagation off`, and
`#pragma opt_strength_reduction off`, written INTO the C source above the
function, are a separate code path the compiler actually honors, confirmed
live (not silently accepted-and-ignored) on sm64ds's own corpus and
independently re-confirmed here.

Swept all 5 documented-live pragmas (`opt_common_subs`, `opt_propagation`,
`opt_strength_reduction`, plus `opt_dead_assignments`/`opt_lifetimes` for
completeness) against all three hard residuals:

- **`#pragma opt_common_subs off` genuinely changes `FUN_022d5540`'s
  codegen**: 0x334 vs the round-3e baseline's 0x33c (dsi/1.1) - 8 bytes
  closer, the best raw byte count reached this session. But it's a mixed
  result, not an unambiguous win: the previously-EXACT 9-register push
  (`r4,r5,r6,r7,r8,sb,sl,fp,lr`, matching target since the very first draft
  in section 3b) breaks under this pragma - the candidate pulls in `r3` as
  an extra register (`r3,r4,r5,r6,r7,r8,sb,sl,fp,lr`, 10 total), apparently
  needed as an alignment/scratch pad once CSE stops sharing an address
  computation the original coloring relied on. Whole diff shape changes
  extensively (44 vs 42 non-equal blocks) - this is a different local
  optimum, not a strict improvement on the 3e/3f baseline's two identified
  mechanisms.
- **Tried to scope the pragma to avoid the register-set regression** (CW
  pragmas support `#pragma opt_common_subs reset` to re-enable, so a source
  file can toggle a region rather than the whole function). Scoped it two
  ways - only around the outer 4-queue loop, and only around the pre-loop
  prelude (isType9/mask setup) - and **both scopings collapse the result
  back to the exact 0x33c baseline, losing the win entirely**. The effect
  only appears when the pragma covers the WHOLE function; it isn't
  attributable to one isolable region, so there's no way found yet to get
  the size win without also inheriting the r3 regression.
- Stacking `opt_propagation`/`opt_strength_reduction`/`opt_dead_assignments`/
  `opt_lifetimes` off on top of `opt_common_subs off` adds nothing further -
  still exactly 0x334, `opt_common_subs` is doing all the work here.
- `FUN_022d5870`: `opt_propagation off` makes it slightly WORSE (0x1f4 vs
  0x1f0 baseline); `opt_common_subs off` is neutral (0x1f0, unchanged).
- `FUN_022d5a64`: no pragma tested changed anything - still the same known
  126-vs-127-real-instruction near-miss from section 3a.

**Not banked as the new best** - a smaller total byte count with a wrong
register set isn't closer to a match in any sense `tools/match.py` cares
about, and every attempt to keep the win while fixing the r3 regression
(scoping) failed outright. Recorded here as real, verified, transferable
knowledge for the next person who reaches for `-opt` flags and finds them
inert per round 3g: try the `#pragma opt_*` form before concluding the whole
optimizer-toggle avenue is dead.

## 4. Where to look next

`../sm64ds-decomp/notes/mwccarm-codegen.md` sections not yet read into this project's
knowledge (see the list in section 2 above) are the highest-value next research step
before more blind experimentation - this file's two confirmed levers (section 1) both
came directly from that source, and its authors have already run into and solved
problems this project hasn't hit yet at this scale.
