# Tooling for contributors

This project's automation is adapted from
[sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp), which has built
a much larger tool pile (~90 scripts) over a longer-running, larger-scale
effort. Most of that is either game-specific (SM64DS actor names, C++ ABI
templates tuned to their class layouts) or built for a scale of coordinated
effort (a hosted claims-lock service, an LLM-fanout pipeline,
worklist/ledger dashboards) this project doesn't need yet. What's ported here
is the subset that's genuinely portable and useful at this project's size:
free-match generators, iteration aids, and the permuter bridge. This doc is
the map of what exists and when to reach for each one.

## The order to reach for things

1. **`tools/sync_ledger.py --apply`** - run this first, always, after cloning
   or pulling. It catches your local (gitignored) match ledger up to what's
   already committed in `src/`, so the free-match tools below don't waste
   time re-deriving functions that are already done.
2. **`tools/cross_match.py`** - free matches from another compatible decomp
   project's already-verified code (SDK/runtime primitives that get linked in
   byte-identical regardless of the game). See
   [cross-project-matching.md](cross-project-matching.md).
3. **`tools/templates.py --apply --extend 0x10`** - free matches from trivial
   leaf shapes (empty stubs, constant/argument returns, single-field get/set,
   two-arg arithmetic, simple global getters) - no hand-writing needed, every
   candidate is oracle-verified before banking. Cheap to re-run periodically
   as more functions get discovered. Always pass `--extend` (see its section
   below) - a one-off run without it missed 31 real matches this session,
   purely because Ghidra's cached size cut off before each one's trailing
   literal pool.
3b. **`tools/find_duplicates.py --apply`** - free matches for any function
   byte-identical to an already-matched one (real example: two functions
   this session turned out to be exact copies of each other). Cheap, worth
   running after every batch of new matches, not just once.
4. **Pick a real target** and read it: `tools/disasm.py` for a quick look.
   For anything past a few instructions, **`tools/m2c_draft.py`** and
   **`tools/ghidra_draft.py`** each give a real semantic C draft to start
   hand-writing a candidate from - see their sections below for why it's
   worth having both, not just one.
5. **Iterate** with `tools/match.py` (pass/fail + full diff) or
   **`tools/fdiff.py`** (always shows the per-instruction diff, with a note
   on which mismatches are "same shape, different register" - i.e.
   permuter-fixable vs a real logic difference).
6. **Close the last mile with decomp-permuter** if you have a candidate that
   compiles with the right *shape* but wrong register coloring/ordering - see
   the permuter section below. This is genuinely free: it brute-forces
   exactly the part that's tedious to do by hand.
7. **If it's logic-correct but genuinely can't be made byte-exact** at this
   compiler tier (a real codegen floor, not "haven't figured it out yet"),
   park it with `tools/nonmatching.py add` instead of leaving it unmatched
   forever.
8. **`tools/progress.py --write-readme`** to refresh the README's progress
   bar before you open a PR.

## tools/ledger.py, tools/sync_ledger.py

The match ledger (`progress/matched.jsonl`, `progress/nonmatching.jsonl`) is
local-only (gitignored) - two contributors' bookkeeping never conflicts on
disk. `tools/ledger.py` is the only code that should touch those files
(`bank()` for a verified match, `append_nonmatching()` for a park); it holds
a cross-process lock so two tools banking at once can't double-write, and it
"adopts" a merged PR's `src/` file cleanly even though the ledger never saw
it land.

Every file `ledger.bank()` writes gets a `// decomp: module=... addr=...
name=...` marker comment prepended. This is what lets `tools/sync_ledger.py`
rebuild the ledger from committed `src/` alone on a fresh clone - it's more
reliable than matching by filename, because a function's Ghidra-cached name
(`FUN_xxxxxxxx`) goes stale the moment it's renamed to a real symbol, and the
filename convention alone can't tell the difference.

## tools/templates.py

A port of sm64ds-decomp's `swarm.py` template-rule engine - every leaf rule
there (the ones needing just `(name, ins, bytes)`, no relocs/symbol table):
empty/constant/argument-return, field load/store/mask/bitfield, bit-test and
bitop patterns, global getters/setters/swaps/indexed access, small fixed-size
struct copies, multi-field constant initializers, and more (33 rules total -
see the file for the full list). Not ported: the C++-ABI rules there
(vtable/ctor/dtor chains, virtual/PMF calls) tuned to SM64DS's own class
layouts, and everything needing callee-name resolution via a populated
`config/relocs.txt`, which this project doesn't have (see
[pictochat-layout.md](pictochat-layout.md) - `dsd init` never finishes for
this ROM).

Mode-aware: tries each rule against the target's own ARM or Thumb encoding
(the `mode` field in `extracted/pictochat_funcs.json`), unlike sm64ds-decomp's
ARM-only version - Thumb mnemonics that implicitly set flags (`movs`/`adds`/
`ands`/...) are normalized to their ARM equivalents so one rule covers both
encodings. A few rules key on ARM's per-instruction condition codes
(`moveq`/`movne`, used for the classic "compare then materialize 0/1" idiom)
that don't exist in Thumb1 on this ARMv5TE-era ROM (no IT-block support) -
those are gated to ARM-mode targets only (`ARM_ONLY_RULES`).

Every proposed candidate is compiled and byte-diffed before being reported,
so a rule misfiring just means "no candidate," never a wrong one.

**`--extend N`**: also retries every rule against windows up to N bytes
*larger* than Ghidra's cached size, reading the extra bytes straight from
the ROM (`rom_bytes()`) rather than trusting `extracted/pictochat_funcs.json`
verbatim. This exists because of a real, recurring bug: Ghidra's function
boundary is code-flow-derived, not from a real linker symbol table (this
ROM has none), so for a leaf like `rule_pool_const`'s `ldr r0,[pc,#0]; bx
lr; .word G` shape, Ghidra sometimes draws the boundary right at `bx lr`
and silently excludes the trailing pool word - the rule then never fires
because the cached bytes are too short to see the `.word`. One `--extend
0x10` pass across the whole project found and banked **31 previously-
invisible matches** this way (mostly `global_getter`/`global_setter`/
`global_store_const`), on top of `templates.py`'s normal count. Cheap to
re-run periodically (same as the base scan), and safe: every hit is still
compiled and byte-diffed at whatever size actually matched (which may
differ from `extracted/pictochat_funcs.json` and is what gets banked -
`main()`'s hit records carry the corrected size, not the cached one)
before being reported, so a rule misfiring at some extended size just
means no candidate at that size, same as the base scan.

Don't confuse this with the OTHER Ghidra-undercounting failure mode this
project has hit repeatedly on hand-matched (non-template) functions - a
trailing pool AFTER a `bx lr`/`pop`, or case bodies past an unresolved
jump-table dispatch (see "Ghidra's function size can exclude a trailing
literal pool" below). `--extend` only helps the *template* tier, where a
byte-pattern rule can cheaply re-check a wider window; for a hand-drafted
candidate hitting the same root cause, find the true size manually the
way that section describes.

### tools/find_duplicates.py

Groups every Ghidra-known function by raw byte content - a function
compiled from a genuinely identical body anywhere else in the ROM is byte-
identical to it (real example: `FUN_0232df74` turned out to be an exact
copy of `FUN_0232df40`, banked for zero extra work). A group with an
already-matched member makes every other member free: same source, new
`// decomp:` marker, still re-verified through the normal compile+compare
oracle before banking (`--apply` does this automatically; dry-run just
reports).

**Guards against a sharp false-positive edge**: the exact same Ghidra
undercounting bug that motivates `templates.py --extend` also **creates
fake duplicate groups**. A pool-const getter's cached bytes are just `ldr
r0,[pc,#0]; bx lr` with the differentiating pool word truncated off - so
ten completely different global-pointer getters, each returning a
different global, all look byte-identical by that truncated cache. Banking
one as the "seed" for the rest would have produced nine plausible-looking
but silently wrong matches (`tools/match.py` would only ever check the 4
cached bytes, never the pool word that's the actual point of the
function). `false_duplicate()` catches this by reading `size + 16` bytes
straight from the ROM for every group member before trusting the group -
a real duplicate stays identical there too; a false one diverges
immediately. Concretely: of 30 raw "duplicate" groups found this session,
**25 were false positives** from exactly this bug - only 5 were real.

## tools/m2c_draft.py

Runs [m2c](https://github.com/matt-kempster/m2c) (matt-kempster's semantic
decompiler) against a function's disassembly, via a capstone-to-GAS-assembly
bridge (this project's version handles the ARM/Thumb mix; see the file's own
docstring for the encoding details). The output is a gcc-flavored semantic
draft - real control flow and data references, useful as a reading aid and a
starting point to hand-write from - but it will **not** compile under
`mwccarm` as-is and is not a matching candidate on its own. Requires
`vendor/m2c` (`git clone https://github.com/matt-kempster/m2c vendor/m2c`).

Two real limits versus sm64ds-decomp's version: no `config/relocs.txt` means
callee/global references show as `func_<addr>` / raw hex instead of real
symbol names (still useful, just less self-documenting); and very large
functions can still trip the pc-relative-pool-window heuristic on unusual
layouts (see `_window()` in the file).

## tools/ghidra_draft.py

Runs Ghidra's own decompiler (the mature, SSA-based one, via `pyghidra`
against `ghidra_project/` - see [ghidra-setup.md](ghidra-setup.md)) for one
function and prints its C. Same disclaimer as m2c: a reading aid, not a
matching candidate, won't compile under `mwccarm` as-is.

Worth pulling **both** this and `m2c_draft.py` rather than picking one -
they fail differently. `m2c`'s capstone-based lifting is more literal
(closer to the raw instruction sequence, which sometimes helps for
scheduling-sensitive code) but can badly mangle local stack structs/arrays;
Ghidra's decompiler models those correctly far more often, at the cost of
sometimes restructuring control flow further from what you actually have to
reproduce. Concretely: for `FUN_02321940`, `m2c_draft.py` produced a bogus
`&subroutine_arg0 - 4` pointer expression where a local stack array was
actually being passed by address - `ghidra_draft.py` got that one right
(`auStack_28`).

Deliberately **not** a batch-export-everything tool - see the module's own
docstring for why (most of a 1500-function backlog never gets looked at in
a given pass, so drafting it all up front is wasted, staleness-prone work).
Run it per function as you pick targets, same as `m2c_draft.py`. It's slower
to start than `m2c_draft.py` (a JVM + Ghidra project load per invocation,
not m2c's near-instant pure-Python pipeline) - expect several seconds.

```
python tools/ghidra_draft.py --name FUN_02321940
python tools/ghidra_draft.py --module arm7 --addr 0x022ce8b0
```

## decomp-permuter

[decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
brute-forces the *exact-codegen* tail of matching (register allocation,
instruction ordering) by randomly applying semantics-preserving C
transformations and scoring each compile against the target. It's the
"stop paying hand-iteration time to nail register coloring" tool: if a
candidate already has the right structure and just doesn't line up in
registers, this finishes it for free.

Setup (one-time per clone - `vendor/` is gitignored):
```
git clone https://github.com/simonlindholm/decomp-permuter vendor/decomp-permuter
```
Then the Windows-compat patches below (also gitignored away with the rest of
`vendor/`, so they need reapplying on a fresh clone - see the diffs in this
project's own history, or ask another contributor for a patch file):
- `src/compiler.py`: route `compile.sh` through `bash` on Windows; when a
  `cc.txt` sidecar exists (written by `import_func.py`), call `mwccarm.exe`
  directly instead (skips a git-bash spawn per candidate, several times
  faster).
- `src/main.py`: skip the Unix executable-bit check on Windows (NTFS doesn't
  track it).
- `src/preprocess.py`: fall back to the in-process `pcpp` preprocessor when
  no external `cpp` binary is on PATH.
- `src/objdump.py` (`get_arch`): default to ARM32 when the file isn't a valid
  ELF (this project's `target.o` is a raw ROM byte slice, not an object file).

Per-function workflow:
```
python tools/permuter/import_func.py --module unk_autoload_0 --addr 0x02320a64 --base draft.c
python tools/permuter/winproc.py --secs 300 -- python vendor/decomp-permuter/permuter.py vendor/decomp-permuter/work/<name> --stop-on-zero -j 4
```
`import_func.py` resolves the function from `tools/funcs.py` (not a
`config/relocs.txt` symbol table, unlike sm64ds-decomp), writes the per-
function compile flags (module + ARM/Thumb aware - this project mixes both),
and wires `tools/permuter/cap_objdump.py` (a capstone-based objdump
replacement, so no external `arm-none-eabi-objdump` install is needed) as the
scorer's disassembler.

### Always run it through `tools/permuter/winproc.py`, never raw `timeout`

`-j 4` spawns multiprocessing workers, each spawning its own
`cap_objdump.py` -> `mwccarm.exe` subprocess. On Windows, killing a parent
process does **not** kill its children - neither a shell `timeout N cmd`
wrapper nor plain `subprocess.run(cmd, timeout=N)` reaches past the direct
child, so the permuter's own worker processes (and *their* `mwccarm.exe`
children) get orphaned and keep running indefinitely once the deadline
passes. This is exactly what happened repeatedly in early sessions - `python.exe`
and `mwccarm.exe` piling up long after a permuter run was reported "done".

`tools/permuter/winproc.py` fixes this properly instead of relying on
anyone remembering to clean up by hand: it assigns the launched process to a
Windows Job Object with `JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE`, so terminating
the job (on timeout, on success, or on any exception) recursively kills the
*entire* tree - direct child, its multiprocessing workers, and their
subprocesses - in one kernel call, no cooperation required from any of them.
No extra dependency (pure `ctypes` against `kernel32`).

- CLI, for interactive/ad-hoc runs: `python tools/permuter/winproc.py --secs N -- <command...>`.
- From Python (this is what `tools/permuter/batch.py` uses internally):
  `winproc.run_bounded(cmd, secs=N, **popen_kwargs)`.

Verified empirically: the same active `-j 4` workload left 5 orphaned
`python.exe` processes running after a plain `subprocess.run(timeout=15)`
call returned, versus zero with `winproc.run_bounded`. Never invoke
`permuter.py` (directly or via `batch.py`) through a raw shell `timeout` or
bare `subprocess` timeout again - always through `winproc`.

For a pile of near-misses at once (drafts that compile but don't byte-match -
often only coloring/ordering is off), use `tools/permuter/batch.py --seeds
nearmiss.jsonl`. A score-0 result is always independently re-verified with
`tools/match.py`'s own oracle before being banked - nothing is trusted on the
permuter's say-so.

### Large/hard-function strategy: lessons from sm64ds-decomp

This project's tooling is ported from sm64ds-decomp
([tangosdev/sm64ds-decomp](https://github.com/tangosdev/sm64ds-decomp),
~95% matched as of this research) - worth checking their notes/ before
re-deriving a large-function strategy from scratch. See
[mwccarm-codegen.md](mwccarm-codegen.md) for this project's own growing
catalogue of confirmed compiler-behavior levers (mined from sm64ds-decomp's
much larger version of the same file and verified against real targets here)
- check it before spending time re-deriving a register-coloring or
instruction-selection fix that's already been found.

Beyond sm64ds-decomp specifically, this project maintains a small library of
other real NDS/mwccarm decomp projects as reference material - see
[extern/README.md](../extern/README.md) for the registered repo list and
`tools/manage_extern.py`/`tools/cross_reference.py` for cloning and searching
them. `cross_reference.py notes <query>` full-text-searches every extern
repo's own codegen/lever documentation (the fastest way to check whether
another project has already solved a given quirk); `search --category <cat>`
greps their matched C source directly for the raw idiom (shift-truncation
pairs, conditional-select pairs, hand-written regalloc-quirk comments,
volatile-for-codegen use - see `config/extern_config.json` for the full
category list). None of these repos are checked out by a fresh clone of this
project by default - run `manage_extern.py clone all` first.

A few concrete, transferable findings pulled from sm64ds-decomp's own
`research-matching-levers.md` and `crack-loop-runbook.md`:

- **Permuter's limits are confirmed upstream, not just observed here.**
  Their own research doc quotes the permuter author: it's "generally best
  towards the end, when mostly regalloc changes remain," and "neither the
  scorer nor the randomizer tends to play well with [reorderings or
  functional changes]." They frame hard residuals as three "walls": (1)
  base-address materialization (no known recipe, controlled experimentation
  only), (2) register-pressure reproduction (mine other same-toolchain
  decomp projects for already-solved idioms rather than reinventing), (3)
  ordering/structural gaps (permuter cannot reliably fix these - accept
  hand-fixing as the realistic path, custom passes are the only mechanical
  lever). Don't burn permuter time on a candidate until it's past wall 3 -
  confirmed the hard way on `FUN_022ce8b0` this session, where an unscoped
  permuter run plateaued at a uniformly bad score for ~9400 iterations
  against a candidate that turned out to have real structural (wall 3)
  divergence, not a coloring problem.
- **m2c drafts are disproportionately valuable specifically on large
  functions.** Their crack-loop runbook reports large functions (0x400+
  bytes) getting "free semantic C scaffolds from m2c tooling without token
  cost," at roughly 64 tokens/byte versus 146+ tokens/byte for smaller
  bands worked without one. Always pull an `tools/m2c_draft.py` (and/or
  `tools/ghidra_draft.py`) draft before hand-translating a large function's
  disassembly yourself.
- **Abandonment heuristic**: they pivot away from a size band once its hit
  rate drops toward ~40%, rather than re-grinding the same territory -
  moving to fresh unworked functions (which resurface easier clusters),
  free/template tiers, or a dedicated "refine" pass on the stuck backlog,
  and coming back later rather than sinking indefinite iteration into one
  function. Applies directly at the single-function scale too: if a
  function has resisted a genuine multi-angle effort (m2c draft read,
  structural hand-iteration, permuter after reaching wall-3-clean), park it
  via `tools/nonmatching.py` with notes on exactly what was tried and
  revisit later with fresh tooling or a dedicated session, rather than
  continuing to spend of-the-moment iteration on it indefinitely.
- They also standardized on `objdiff` (github.com/encounter/objdiff) as
  their visual/machine diff interface (DS ARM support + CodeWarrior symbol
  demangling) instead of a bespoke tool - worth evaluating as a replacement
  or complement to `tools/fdiff.py` if hand-iteration on large functions
  becomes a regular workload here, rather than continuing to grow a
  bespoke diff tool function-by-function.

## tools/probe_versions.py

Compiles a probe C file (`tools/probes/discriminate.c`, a spread of
constructs where CodeWarrior point-releases tend to diverge) with every
candidate `mwccarm` version and reports which functions produce different
bytes across versions. This is how you'd actually nail down the compiler pin
(`dsi/1.3` is currently just a copyright-date guess - see
[setup-mwccarm.md](setup-mwccarm.md)) instead of hoping every match keeps
landing on it by luck. So far the whole `dsi/` family is codegen-identical
for every construct in the default probe file - feed it something more
unusual if you want to actually narrow the pin down.

## tools/match.py never actually checked a relocation's target - only fixed this session

Every relocation (a `bl` to an extern function, a pool-loaded address of an
extern global) got wildcarded by `compare()` unconditionally - the README's
claim that matching is "relocation-aware... a raw byte diff alone would
wildcard a wrong callee/global sitting in a reloc slot; `tools/match.py`
checks both" was **not actually true** until this session. Concretely: for
`src/arm9/FUN_02320938.c` (5 extern calls, 5 extern globals), 13 of its 14
code words are relocations - `compare()` was really only checking 1 word out
of 14. Renaming an extern to point at a completely wrong address would still
report MATCH, as long as the byte count and non-relocated words lined up.

**Fixed, but only where the information exists to fix it.** This project's
own convention already embeds the real address in most placeholder names
(`FUN_<hex>`, `func_<hex>`, `G_<hex>`, ...) - `match.py` now has
`verify_relocs()`, which parses that address back out of each relocation's
ELF symbol name and checks it against what the *real* ROM bytes at that slot
actually decode to: a direct compare for a data/pool relocation (`R_ARM_ABS32`
- allowing `addr | 1` too, since a Thumb function's address stored as a
*value* legitimately carries the ARM/Thumb interworking bit, unlike a
`bl`'s resolved branch target, which capstone always resolves to the true
byte address either way), or a capstone-decoded resolved branch target for a
call relocation. `main()` now downgrades a would-be MATCH to a failure and
prints exactly which symbol claimed which address vs. what the ROM really has
there. Wired into every auto-banking path (`match.py`, `fdiff.py`,
`find_duplicates.py`, `permuter/batch.py`) - `templates.py`'s generated
candidates only ever use address-less placeholder names (`G`, `F1`, ...) so
there's nothing for it to check there.

**This can't retroactively audit most of the existing corpus** - the
overwhelming majority of already-matched files use generic, non-address
placeholder names (`extern int G[]; extern void F1(void);`), which is exactly
as unverifiable as before; `verify_relocs()` silently skips anything it can't
parse an address out of, same as the old blind wildcard. It only closes the
gap for symbols that already claim a specific address in their own name -
which is worth doing consistently going forward, especially on functions
(like the largest unmatched ones) that call many still-unidentified helpers.

A spot-check of the 38 committed files that do use address-encoded names
turned up exactly 2 real issues (both fixed): `FUN_02320728.cpp` had two
globals misnamed after the *enclosing function's own address*
(`gBufferStart_02320728`/`gBufferEnd_02320728`) instead of their real
addresses (`0x02348ee4`/`0x023490e4`) - byte-identical, just a misleading
name, now corrected. `FUN_02332660.c` (`G_023c10c4 = FUN_02332598;`, a Thumb
function pointer stored as data) tripped a false positive that led to the
`| 1` interworking tolerance above. Six other flagged files turned out to be
false alarms from the spot-check script itself, not `verify_relocs()` - they
're already honestly parked `NONMATCHING` (register-coloring/scheduling
floors), which the script didn't filter for.

## tools/match.py's relocation wildcarding had an alignment bug

Fixed this session: `extract_func()` marked a relocation's compare-word as
`o & ~3` (round the reloc's byte offset down to the enclosing 4-byte word)
and wildcarded only that one word. That's wrong whenever the relocation
itself doesn't start on a 4-byte boundary - a Thumb `bl`/`R_ARM_THM_CALL`
relocation is 4 bytes wide but can legitimately start at a 2-mod-4 offset
inside a function (there's no requirement that call instructions land on
word boundaries), in which case its second half spills into the *next*
4-byte word, which was real-compared instead of wildcarded. Concretely: a
function calling the same helper three times back-to-back can have its
third `bl` start 2 bytes into a word - that call's true target-address
encoding was being byte-compared against a placeholder, guaranteeing a
spurious 1-word mismatch no matter how correct the C was. `extract_func()`
now adds both `o & ~3` and `(o+3) & ~3` per relocation, covering both
words a straddling reloc can touch.

This can only have caused **false rejections**, never false acceptances -
wildcarding too little makes the check stricter, not more lenient, so
nothing already banked is affected. But it means some function you tried
earlier and set aside as "close, 1 word off, couldn't figure out why"
might have actually been correct - worth a second look with `--all` (or
even just re-running the same candidate) now that this is fixed, especially
for anything that calls the same helper multiple times or otherwise has a
`bl` landing at an odd position.

## tools/fdiff.py

Like `tools/match.py` but always verbose: a per-instruction table showing
target vs. candidate, with a note on which mismatches are "same shape,
different register" (regalloc/coloring - what the permuter fixes) versus a
real structural difference (what you need to fix by hand). Use this instead
of `match.py`'s plain pass/fail once you're iterating on something that's
close but not there yet.

Two modes added for large functions (past a couple hundred bytes, the plain
per-word table is both unreadable and expensive to keep re-printing every
iteration):

- **`--compact`**: groups mismatching words into contiguous runs and prints
  only a summary + a few boundary lines per run, instead of every word.
  Use this once you're at the "mostly matches, a handful of small clusters
  are off" stage - same-size candidate, register-coloring-scale diffs.
- **`--align`**: for when candidate and target are *different sizes* (a
  missing/extra instruction somewhere) - `--compact` and the plain mode are
  both useless here, since a single insertion shifts every subsequent word
  and makes the whole rest of the function look mismatched even when the
  logic past that point is identical. `--align` instead runs a
  `difflib.SequenceMatcher` over the *decoded instruction stream* keyed on
  `shape()` (mnemonic + operands with register numbers and pc-relative
  offsets squashed - the same normalization the plain table already uses
  for its "same shape" note), so pure coloring differences collapse into
  "equal" and only genuine inserted/deleted/reordered/different-shape
  instructions show up as a block. This is also useful, without a size
  difference, on a candidate that's badly diverged structurally (see the
  `FUN_022ce8b0` case below) - it distinguishes "918 words differ because
  of coloring noise cascading off one bad block" from "918 words differ
  because the C is structurally wrong in a dozen places," which `--compact`
  cannot tell apart on its own (it counts differing words, not differing
  *shapes*).

## tools/frame_shape.py

Reads a function's prologue (`push {...}` / `stmdb sp!,{...}` then
`sub sp,sp,#N`) straight off raw bytes - the ROM target, or a compiled
candidate - and reports the register-save set and frame size, no full
match/fdiff run needed:

```
python tools/frame_shape.py --module arm7 --addr 0x022ce8b0 --size 0x1194 \
    --c candidate.c --func FUN_022ce8b0 --version dsi/1.3 --flags "..." --compare
```

Exists because on a large function, `-O4`'s register allocator's behavior
(what stays in a register vs. gets spilled) is driven by how much frame +
how many callee-saved registers the function ends up needing - a candidate
that implies fewer live temporaries than the real function gets a smaller
frame and a *different push-set*, and the compiler colors the entire body
differently as a result. That shows up in `fdiff.py` as hundreds of
scattered word diffs with no obvious single cause, and diagnosing "is this
even the right frame shape" by eyeballing a huge diff dump is exactly the
kind of grind this project's tooling exists to avoid. This tool answers
that one question directly and cheaply (one compile) before you sink time
into iteration.

Caught in practice on `FUN_022ce8b0`: target pushes 10 registers (incl. an
`r3` alignment-filler with no other use) + `sub sp,#0x28`; an early
candidate pushed 9 + `sub sp,#0x2c` - same *total* stack depth (0x50 bytes
either way), so the candidate wasn't "missing a local," it just had one
fewer register available for the allocator to spread live values across,
which was enough to make it globally cache constants (`mov r5,#0` reused
~15 times) that the target re-materializes fresh at every use site instead.
Knowing the total depth already matched (not just "some diff exists")
correctly ruled out "need another local" as the fix and pointed at register
*pressure*, not register *count*, being the lever to pull.

## tools/frame_search.py

Automates the "which of these C-shape hypotheses actually reproduces the
target's frame?" search that `frame_shape.py` diagnoses but leaves you to
answer by hand - checking one hypothesis used to mean writing a whole new
variant file, recompiling, and re-running `frame_shape.py --compare`, then
repeating for the next guess. Both `FUN_022d5870` and `FUN_022d5a64`
(see their `scratch/*_notes.md` files) needed 15-20+ hand-written variants
each before landing on the right shape, most of them one-line changes from
the last - exactly the kind of repetitive search a tool should do instead.

Author one seed `.c` file with inline toggle markers instead of N full
variant files:

```
@{name}[choice0|choice1|...]
```

Every occurrence sharing the same `name` toggles together (so one logical
decision - "should this base pointer be a named local or recomputed inline
at each use?" - can have different literal text at each of its call sites);
an empty choice (`""`) means "omit this text entirely" for that combination,
which is how you express "only declare this local under choice X". Different
`@{name}` axes combine as a cartesian product, and every combination gets
tried against both `-O4,p` and `-O4,s` automatically (`--no-opt-sweep` to
skip that):

```
python tools/frame_search.py --seed candidate_template.c --func FUN_022d5870 \
    --module arm7 --addr 0x022d5870 --size 0x1ec
```

Reports results sorted by distance from the target frame shape (register
push-set + stack depth; 0 = exact match) and writes the best N to disk.
Validated against `FUN_022d5870`'s already-hand-solved register-count
mismatch: reproduced the known-best shape (9 registers, matching the
target's push-set) in one ~30-second batch run covering 3 toggle axes x 2
optimization levels, versus the ~20 individual hand iterations that took to
find by hand originally. An exact frame match is **necessary, not
sufficient** - it only checks the prologue shape, not the function body -
always follow up with a real `tools/fdiff.py --align` pass on the winning
candidate.

Gotcha: a substituted choice is spliced in as raw text with no
parenthesization added, so it inherits whatever precedence the surrounding
characters imply - `*@{x}[qhead + 1|...]` expands to `*qhead + 1` (parses as
`(*qhead) + 1`, not an lvalue) when you meant `*(qhead + 1)`. Caught this
exact mistake during validation - the tool correctly reported the compile
failure rather than silently mishandling it, but wrap multi-token choices in
their own parens in the seed to avoid the wasted compile attempts.

## The `pop {...,pc}` fold puzzle

A recurring near-miss shape: a candidate matches target instruction-for-
instruction (same operations, same order, sometimes even the same byte
count) except the target's last instruction is a folded `pop {r4-r7,pc}`
while the candidate always emits a separate `pop {r4-r7}` + `bx lr`. This
isn't a source-structure issue - synthetic single-return, zero-branch test
functions reproduce it too - and it isn't rare: of the functions matched via
`tools/templates.py` and the manual loop so far, **none** compile to the
fold form under this project's pinned flags
(`-O4,p` = `-opt level=4 -opt speed`; check with `mwccarm -help opt=O4`).

Switching to `-O4,s` (`-opt space`) reliably produces the fold in synthetic
tests, and re-validating all currently-matched functions under `-O4,s`
instead of `-O4,p` leaves the great majority still matching byte-identical
(as of the 54-function checkpoint, 51/54 - the 3 regressions were unrelated
trivial-template/anomaly cases). So `-O4,s` is a real, safe-to-try lever,
**not** a free fix: on two real fold-blocked near-misses
(`FUN_02323d44`, `FUN_0232dbd0`) it changed *other* codegen choices too
(register allocation, prologue shape, or in one case introduced an
unrelated fixed 6-byte NOP trailer present at every `-O1`-`-O4,s` level
alike, so unrelated to the fold at all) rather than landing a byte-exact
match outright. Treat an `-O4,s` recompile as a fresh iteration starting
point for a fold-blocked candidate - re-derive the exact source shape
against the new flag's behavior rather than expecting the `-O4,p`-tuned
source to carry over unchanged.

Until a specific function's fold is actually cracked, the cheap workaround
is avoidance: before drafting a candidate, check the target's own real
tail bytes (`tools/disasm.py`) and prefer functions that already end in
separate `pop`+`bx lr` (the vast majority) over ones ending in the fold.

## `-O4,s` also fixes a "conditional early-return epilogue" mismatch - a second real success, not just the fold

A different recurring near-miss on small `if (early) { ...; return; } ...more...`-
shaped functions: the target shares ONE epilogue via a forward branch
(`bne label; ...more...; label: pop {..}; bx lr`), while `-O4,p` candidates
instead duplicate the whole epilogue inline as predicated instructions
(`popne {..}; bxne lr`) at the early-return site. Confirmed fixed by
`-O4,s` on a real function this session (`FUN_022cfa90.c`, arm7) - unlike
the fold puzzle above (where `-O4,s` only ever produced *other* codegen
differences on the two real cases tried), here it landed a clean, complete
byte-exact match with no other changes. Worth trying `-O4,s` on this
specific near-miss shape before spending iteration cycles on C rephrasings -
early-return-vs-shared-epilogue doesn't reliably respond to source
restructuring (tried explicit `return` vs. `if/else` on the same function,
no difference; the opt-level switch is what mattered).

To use a non-default flag on a banked file, add `// flags: ...` as the line
right after the `// decomp:` marker (parsed by all of `match.py`/`fdiff.py`/
`nonmatching.py` via the shared `apply_flags_marker()`) - e.g. `// flags:
-O4,s -noThumb`. Multiple tokens on one line are fine. This replaces the
base flags' own `-O<n>,<x>` instead of appending a second one - appending
(the bug before this session) silently produces garbage output from
mwccarm, since it doesn't just take the last `-O4,...` and ignore the
earlier one.

**Also note**: an ARM-mode (non-Thumb) `arm7` function needs `-noThumb` in
that marker line to be independently re-verifiable - `DEFAULT_FLAGS_ARM7`
defaults to `-thumb`. Passing `--flags` by hand on the command line during
iteration works but doesn't get remembered; if the banked file itself
doesn't carry the marker, a later plain `tools/match.py --c file --func ...`
call (e.g. from `tools/sync_ledger.py`-adjacent tooling, or another
contributor) recompiles it in the wrong mode and "loses" the match. Caught
this session after 5 ARM-mode arm7 matches had already been banked without
the marker - all fixed retroactively; check for it on any future ARM-mode
`arm7` bank.

**A sharper version of the same trap: passing `--flags` on the CLI replaces the
ENTIRE base flag set, not just the `-O` token.** `main()` does
`flags = args.flags or DEFAULT_FLAGS_ARM7` - if `--flags` is given at all, even
just `"-O4,s -noThumb"` to force an opt-level/mode override during iteration,
`-enum int -lang c99 -char signed -interworking -proc arm7tdmi -gccext,on
-msgstyle gcc` are ALL silently dropped, not merged in. For most functions this
is harmless (nothing in a plain C89-style draft depends on those flags), which
makes it easy to develop a habit of typing an abbreviated `--flags` string during
iteration and never notice - until a function that DOES depend on one of them
(confirmed on `FUN_022d5540`: one of `-proc arm7tdmi`/`-gccext,on`/the others
changed whether the epilogue got the `pop{...,pc}` fold - a real, structural
4-byte difference, not noise) silently produces a wrong number that then gets
believed for an entire round of iteration. **The safe pattern**: for a file that
already carries a `// flags: ...` marker, don't pass `--flags` on the CLI at all -
let the marker substitute into the real, complete default flags. Only pass
`--flags` explicitly when you need something the marker system can't express,
and when you do, copy the FULL flag string (`DEFAULT_FLAGS_ARM7`/`DEFAULT_FLAGS`
plus your override), never an abbreviated one.

## A base-pointer caching floor: the compiler's CSE-across-calls choice doesn't reliably respond to source phrasing

A third recurring near-miss, seen on 3 sibling arm7 functions this session
(`FUN_022ce658`, `FUN_022cfb24`, `FUN_022cfc48` - all parked NONMATCHING):
the target reloads the same pool constant fresh (a fresh `ldr rX,[pc,#N]`)
at each of 2-3 use sites spread across intervening function calls, while the
candidate's `-O4` optimizer caches it in a callee-saved register instead and
reuses it across the calls - fewer total instructions, but a different
push/pop set and therefore a size/shape mismatch. This is the *opposite*
problem from the frame-shape note above (there, the candidate needed to
cache more; here, it needs to cache *less*, matching the target's apparent
preference to keep the callee-saved register count down rather than avoid
redundant pool loads).

Tried and failed to steer this via source phrasing: a local pointer variable
holding the base, a `volatile`-qualified local (forces a real stack spill
instead - worse, not better), referencing an already-declared named extern
instead of a raw integer-cast pointer, and splitting one struct-typed base
into separate per-field extern globals (needs *more* registers, not fewer,
since there's no longer a shared base to fold). None reproduced the target's
reload-every-time behavior. Unlike the two `-O4,s` wins above, switching
optimization level didn't close this gap either (tested on `FUN_022cfc48`).
Currently unsolved - if you crack the actual lever, document it here.

## `tools/disasm.py` resolves and dereferences pc-relative pool loads

Added this session after doing the equivalent by hand (`target_bytes()` +
`struct.unpack_from("<I", ...)`) about a dozen times while working the
`FUN_022ce8b0` callee cluster. Every `ldr rX, [pc, #N]`-shaped instruction
now gets an inline annotation showing the resolved pool address AND the
4 bytes actually stored there: `ldr r1, [pc, #0x2c]   ; [0x022CE5E8] =
0x023180DC`. Pass `--no-pools` to disable (e.g. for a cleaner diff against
old output). Also added `--to-next`, which disassembles up to the next
known function's start address (from `tools/funcs.py`) instead of a fixed
`--length` - covers this function's own trailing literal pool automatically
in the common case, though not always: if Ghidra never detected a small
function sitting in the gap (a tail-call thunk, usually), `--to-next`
overshoots into that neighbor's bytes too. Caught this on `FUN_022cfa90`,
where the "next function" was actually 0x14 bytes of a separate,
Ghidra-unlisted `bx ip` trampoline - always sanity-check where the real
`bx lr`/`pop {...,pc}` falls before trusting `--to-next`'s span verbatim.

## Ghidra's function size can exclude a trailing literal pool

Second recurring near-miss shape: a candidate compiles to *more* bytes than
the target even though every real instruction matches. Ghidra's cached
function boundary (what `tools/funcs.py`'s `f["size"]` reports) is based on
code-flow analysis, not a linker symbol table (the shipped binary has none)
- so for a function whose `ldr rX,[pc,#N]` pool constants live physically
after its last `bx lr`/`pop`, Ghidra sometimes draws the boundary right at
the return and silently excludes the pool. `FUN_02000e78.c` hit this first
(its comment documents a 48-byte trailing pool past a 184-byte Ghidra
boundary - true size 232, not 184). `FUN_023226d4` hit it again this
session: Ghidra said 46 bytes, but `tools/disasm.py` on the bytes just past
that boundary showed the exact same alignment-NOP + pool-word pattern an
isolated single-function compile of the same source produces, confirming
the real function is 56 bytes (0x38), not 46 (0x2e).

`FUN_022d5a64` hit it a third time (2026-08-04) and is the most expensive
instance so far, because it did NOT present as "candidate too long" - it
presented as a *structural* mismatch that survived multiple sessions of
investigation. Ghidra said 0x1fc; the two words at 0x022d5c60 (`&G_023190dc`)
and 0x022d5c64 (`0xffff`) are this function's own pool, and the next function
starts at 0x022d5c68, so the true size is 0x204. Because the pool was excluded,
the target appeared to have 127 instructions where every candidate had 126, and
that phantom "one instruction short" was recorded across several rounds as a
register-allocation floor (see mwccarm-codegen.md 3m). **Cross-check the
declared size against the NEXT function's start address before concluding
anything about a residual**: `next_addr - this_addr` is the honest upper bound,
and `tools/funcs.py` already has both.

If a candidate is consistently N bytes *too long* and every instruction up
to the target's declared end already matches, don't assume the source is
wrong - check `tools/disasm.py --addr <target_end> --length 0x10` first.
If it decodes as an alignment NOP followed by recognizable pool
constant(s), use the corrected size (round up to include them) as `--size`
instead of trusting the Ghidra cache verbatim.

For a run of tiny sibling functions packed back-to-back (e.g. several
`arg & G[N]`-style one-liners at consecutive addresses a few bytes apart),
the trailing pool word Ghidra excluded from function A can be sitting
*inside* what looks like function B's own address range - i.e. two
adjacent undercounted functions can appear to overlap until both are
corrected. Don't let that overlap read as a sign something's wrong; just
correct each one's size independently from its own `bx lr`/`pop` forward,
the same way as any other instance of this bug.

The same undercounting hits switch/jump-table functions too, for a
different reason: Ghidra's code-flow analysis can't always statically
resolve an indirect `add pc,rX` dispatch, so it stops the function right
at the table instead of including the case bodies and default handler
past it. `FUN_02329270` and `FUN_02329a08` both hit this. **Don't assume
the true boundary is wherever the next function's first real instruction
starts, though** - `FUN_02329a08`'s cached size (0x2a) undercounted by
more than just the missing case bodies; the correct boundary (0x32) sits
2 bytes *before* the next function's own first instruction (0x34), with
one inter-function alignment NOP in between that belongs to neither
function's own compiled output. Confirm the exact boundary empirically:
try the size that ends right after the last real `bx lr`/`pop` first (a
clean, zero-mismatch `tools/match.py` run confirms it), before assuming
you need to include trailing bytes up to the next function.

Same bug, much bigger instance: `FUN_022ce8b0` (arm7, a ~4.4KB dispatcher -
the largest unmatched function as of this session) has a Ghidra-cached size
of 4428 (0x114c) bytes, but its true size is 4500 (0x1194) - a 72-byte
trailing pool Ghidra's analysis didn't reach. Confirmed cheaply without any
disassembly: the *next* function in `extracted/pictochat_funcs.json`
(`FUN_022cfa44`) starts at exactly `0x022ce8b0 + 4500`, with zero gap - so
for any function you suspect is undercounted, checking the next function's
address in the cache is a fast sanity check before reaching for
`tools/disasm.py`. The corrected size was also applied directly to the
local `extracted/pictochat_funcs.json` cache entry (gitignored, safe to
patch) so every size-reading tool (`tools/funcs.py`, `tools/match.py`,
`tools/permuter/import_func.py`, `tools/m2c_draft.py`'s `--name`/`--addr`
resolve path, etc.) picks up the fix automatically instead of needing a
`--size` override at every call site.

## A few more codegen idioms worth trying before you conclude "stuck"

Found while hand-matching `unk_autoload_0` 0x02328000-0x02330000:

- **`x &= ~C` for a small constant `C`**: if the compiler is pool-loading a
  full-width mask and ANDing instead of emitting a `BICS`, try keeping the
  intermediate value as a plain `int` (not `unsigned short`/other narrow
  type) and writing the result straight back through the pointer, rather
  than caching it in a local first. This nudged mwccarm into the shorter
  `BICS`-based form that matches this kind of clear-some-bits target.
- **Register-pairing swaps in loop/pointer-walk shapes**: if two variables
  come out in the opposite registers from target (a pure recolor, same
  instruction shape otherwise), try declaring the plain scalar(s) (loop
  counters, indices) *before* the pointer variable in source order. Fixed
  one real case this way - but isn't universal, a sibling case with the
  same symptom didn't respond to it, so treat it as one more thing to try,
  not a rule.
- **A pointer register reused via cheap arithmetic to materialize an
  unrelated second constant**: e.g. having just computed `base+0x50` for
  one purpose, the compiler notices `base+0x50` is *also* useful nearby
  and re-derives it with a cheap `add r4,#0x50` instead of a fresh pool
  load, even where the two uses aren't obviously related in the source.
  This is a genuine optimizer behavior (CSE/rematerialization across
  supposedly-unrelated expressions), not something source phrasing
  reliably suppresses - if you hit it, it's likely a real, if frustrating,
  compiler floor rather than a bug in your candidate.

## Inline asm is not a shortcut for ordinary application logic

It's tempting, once a candidate is byte-for-byte identical to the target
except for one compiler-scheduling choice (an instruction order a dozen
plain-C rephrasings won't reproduce), to just hand-write the exact target
instruction sequence as inline asm and call it matched. **Don't, for
normal application code.** It technically passes `tools/match.py`, but it
isn't decompilation - it's re-encoding the same bytes in a different
syntax, and defeats the actual point of this project: source a human can
read as an honest account of what the function does. This was tried and
reverted for two ordinary functions (an all-zero-word check, a linked-list
append) this session - both got stuck on a two-or-three-instruction
scheduling swap that no statement reordering reproduced, and asm was
reached for instead of pushing further on the C or parking the function.

`src/arm9/FUN_02000e78.c` is **not** a precedent for this - it's a
different category. That function's "logic" is a fixed CP15/cache/MPU
register-programming sequence where the instruction order essentially *is*
the specification (mirrors sm64ds-decomp's own hand-asm `SystemSetup`
equivalent); there's no higher-level C shape being discarded by writing it
as asm, because there isn't a meaningfully different one. A linked-list
insert or a loop, by contrast, has a real C shape, and if the compiler's
scheduler won't reproduce the target's exact ordering, the right moves are
(in order): try more source-level rephrasings, try decomp-permuter, try
other flags/optimization levels, and only if genuinely stuck, park the
function with `tools/nonmatching.py` rather than banking asm as if it were
a match.

If a genuine hardware/runtime-primitive case like `FUN_02000e78.c` does
come up again, two mwccarm inline-asm gotchas are worth knowing up front:

- mwccarm's inline assembler wants **bare** mnemonics even for Thumb1 forms
  that inherently set flags and disassemble with an implicit `s` - write
  `mov`/`add`/`sub`/`orr`/`asr`/... not `movs`/`adds`/`subs`/`orrs`/`asrs`/...
  The encoding is identical either way (Thumb1 `movs` and ARM-syntax `mov`
  in this context assemble to the same bits); the `s` form is simply not
  accepted as *input* syntax by this assembler, only produced by the
  disassembler reading it back. Numeric local labels (`1f`/`1b`/`0:`) also
  aren't accepted - use named labels (`Lbody:`, `b Lbody`) instead.
- `tools/match.py`'s CLI auto-strips `-thumb` from the compile flags
  whenever the source text contains the literal word `asm` (see
  `main()`'s `-thumb`-stripping block) - a heuristic for the CP15-style
  ARM-mode asm functions like `FUN_02000e78.c`, where `-thumb` would make
  mwccarm reject coprocessor instructions. That heuristic is wrong for a
  Thumb-mode function whose inline asm is itself genuinely Thumb code -
  compiling it in ARM mode instead just produces confusing "illegal
  operand" errors. Pass `--flags "..."` explicitly (copy `DEFAULT_FLAGS`
  from `tools/match.py` verbatim, keeping `-thumb`) to override the
  heuristic for this case.

## tools/csweep.py - sweep COMBINATIONS of source edits, not one at a time

Added 2026-08-04, while closing `FUN_022d5a64`. Hand-testing one C phrasing per
compile is the slow part of a near-miss: each lever (a `volatile`, a cast, a
declaration order, a pragma) is cheap alone, but the ones that matter usually
only pay off in COMBINATION - `FUN_022d5540`'s best candidate needed two pragmas
that were each individually a regression (mwccarm-codegen.md round 3j), and
`FUN_022d5a64`'s match needed five independent changes at once. `csweep.py` runs
the cartesian product and ranks the results.

A sweep is a JSON spec naming a base file, the target coordinates, and a list of
independent `axes`; each axis replaces an `anchor` string with one of several
`options`:

```json
{ "base": "scratch/draft.c", "func": "FUN_022d5a64", "addr": "0x022d5a64",
  "size": "0x204", "module": "arm7", "version": "2.0/base",
  "axes": [ {"name": "first", "anchor": "    int first;",
             "options": {"plain": "    int first;",
                         "vol":   "    volatile int first;"}} ] }
```

```
python tools/csweep.py sweep.json --top 10 --keep-dir scratch/_sweep
```

Each candidate is scored through the same oracles as everything else
(`match.py` to compile, `fdiff.py --align` to score) and reported as
`insn±N blocks=N size±N`, ranked best-first; a byte-exact hit stops the run and
prints the file. Two deliberate design points:

- **Anchors must occur EXACTLY once** in the base, checked up front. A typo'd
  anchor that silently matches nothing would make every combination compile the
  identical base and report a uniform (meaningless) result - the same class of
  self-inflicted bug that cost a full round earlier in this project's history
  (see mwccarm-codegen.md's "false lead" note on a sweep whose string
  replacement silently failed).
- **`blocks` is the shape metric, not size.** It comes from `fdiff --align`,
  which collapses pure register-coloring differences, so a falling block count
  means the STRUCTURE is converging even while byte size stands still. On
  `FUN_022d5a64` the last stretch went 27 -> 25 -> 21 -> 17 -> 15 -> 6 -> 1
  blocks with the size barely moving; ranking on size alone would have hidden
  that progress.

## tools/nonmatching.py

The park hatch for a function that's logic-correct (compiles, and the oracle
divergence is small) but can't be made byte-exact at this compiler tier - a
real codegen floor, not "haven't figured it out." Discipline: only use this
when you're actually stuck on the *compiler*, not the logic; a fresh target
you haven't cracked yet belongs in the normal matching loop, not here.

## tools/progress.py

Regenerates the README's progress bar. Matched-function *count* is always
computable from committed `src/` alone; the total/percentage needs a local
`extracted/pictochat_funcs.json` (the Ghidra function cache), since this
project's `config/` never finished generating (unlike sm64ds-decomp, whose
`progress.py` can run from committed data alone with no ROM - see the file's
own docstring for why that's not true here yet).
