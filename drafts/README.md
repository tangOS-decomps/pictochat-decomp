# Drafts

Ghidra decompiler output for every function that is not yet matched, one file
per function, plus [INDEX.md](INDEX.md) ordered by how close each draft is to
being usable.

**A draft is a reading aid, not a matching candidate.** Nothing in here has
been compiled, and most of it will not compile. It exists so that the next
person does not have to start from raw disassembly. The only thing that decides
whether C is correct is `tools/match.py` reporting byte-identical output.

```
python tools/match.py --c <file> --func <NAME> --addr <ADDR> \
    --size <SIZE> --module <MODULE> --version 2.0/sp1
```

Every draft carries that exact command in its header, with the coordinates
already filled in. Copy it.

## Regenerating

```
python tools/ghidra_batch.py --corpus --out drafts
```

Re-run it whenever a batch of functions gets matched. Drafts get **better over
time**: before decompiling, the tool pushes every banked, byte-verified
signature into Ghidra, so each newly matched function improves the drafts of
everything that calls it. A caller decompiled against a wrong callee prototype
silently drops arguments and invents `undefined4` casts, and that is most of
what makes a draft hard to read.

## Picking something to work on

[INDEX.md](INDEX.md) is sorted by `noise`, then statement count, then size.

`noise` counts markers that mean the decompiler did not understand something:
`undefined*`, `CONCAT*`, `unaff_*`, `in_*`, `extraout_*`, `switchD`,
`halt_baddata`, `code *`, `WARNING:`. A draft with `noise=0` and few statements
can be read in a minute. One with high noise needs the disassembly open anyway.

`noise` is a proxy for **effort, not for correctness**. A clean draft can still
be wrong, and routinely is - see the type traps below.

Always read the real instructions next to the draft:

```
python tools/disasm.py --module <MODULE> --addr <ADDR> --to-next [--thumb]
```

`--to-next` runs to the next known function, which includes this function's own
trailing literal pool. Ghidra's cached boundary **excludes** that pool for about
42% of functions, so its size is short. The draft headers already show the
corrected size from `funcs.true_size()`; use that number, not Ghidra's.

## The toolchain

`2.0/sp1`. Not `dsi/1.3`. This was established by recompiling the whole matched
corpus both ways - see `notes/setup-mwccarm.md`, which leads with the evidence.
If a function will not match, the toolchain is not the reason; do not go
looking for a different compiler.

## Things that have actually cost people time

Each of these is a real diagnosis from a real match, not a general tip. When a
draft is close but not identical, this is the list to walk.

### Signedness decides the instruction

The decompiler prints `char`, `int` and `uint` fairly loosely, and each choice
picks a different opcode:

| you write | you get | ROM has |
|---|---|---|
| `char` | `ldrsb` | `ldrb` -> use `unsigned char` |
| `short` | `ldrsh` | `ldrh` -> use `unsigned short` |
| `int >> n` | `asrs` | `lsrs` -> the value must be `unsigned int` |
| unsigned compare | `bcc`/`bhi` | `blt`/`bgt` -> read through `int` |

`unsigned short x; x & 0x3c` promotes to `int` and yields an *arithmetic*
shift. To get `lsrs` the value has to be held in `unsigned int`. `FUN_02336764`
needed the mode in `int` (for `blt`) and the control word in `unsigned int`
(for `lsrs`) *in the same function*.

### Association of `+` is load-bearing

The four BG base getters compute `bg + (disp + base)`. Writing the same three
terms left to right as `base + disp + bg` groups as `(base + disp) + bg`, which
reorders the two adds and leaves six mismatched words with every single other
instruction already byte-identical. If the arithmetic is right but the adds are
in the wrong order, re-parenthesise before you change anything else.

### Evaluate operands in the ROM's order

In a read-modify-write, whichever operand is computed *last* tends to land in
the destination register. `*reg = (*reg & ~0xc) | (v << 2)` and
`*reg = (v << 2) | (*reg & ~0xc)` are the same value and different code - the
second computes the shift first and then needs two extra register moves.

### `volatile` on a parameter, to stop sinking

If the ROM loads through a pointer *before* touching a hardware register and
the compiler does it after, the compiler is sinking the load. Marking the
parameter `volatile` pins it. In `FUN_023328b8` that reordering was also what
cost the callee-saved register the ROM actually uses, so the frame changed too.

### Which arm is the if-body

`if (bad) return 0;` followed by the real return **inlines** the zero path.
The ROM often does the opposite - the real return is the if-body and `return 0`
falls through at the end. Same logic, different layout. Invert the condition.

### Declaration order changes registers *and* stack slots

When the instructions are identical but the registers or `[sp,#N]` offsets are
not, the fix is the order of declarations, not the code. `tools/declorder_search.py`
hill-climbs this.

### Do not buy a match with a flag

`FUN_02321770` is byte-identical under `#pragma optimize_for_size on`. It is
**parked, not banked**, because all eight already-matched functions bracketing
it break under that pragma while matching without it, and a translation unit is
laid out contiguously - so it is in the same file as code demonstrably not
built that way. Read `src/arm9/FUN_02321770.cpp` before reaching for a pragma.

Before using any non-default flag or pragma, check its neighbours. If they
contradict it, the bytes are right for the wrong reason and it does not count.

### Relocations are wildcarded

`match.py` cannot check relocation *targets*, only that a relocation is there.
So `&G_02338318` for what is really a bare ROM constant still "matches" while
linking the wrong symbol. If a pool word is a plain hardware address or magic
number, write it as a literal - `(int *)0x80000080` - not as a fake symbol.
`tools/pr_linkcheck.py` catches some of these; it is run on every PR.

### No inline asm for ordinary logic

Banking `asm { ... }` for application logic is not a match, it is a copy of the
answer. It is only acceptable for fixed hardware-register programming sequences
that C genuinely cannot express, such as CP15 setup.

## Tools

| tool | what it is for |
|---|---|
| `tools/match.py` | the only authority on whether something matches |
| `tools/disasm.py` | ROM disassembly, `--to-next` for the true extent |
| `tools/ghidra_batch.py` | regenerate these drafts, with signatures aligned |
| `tools/match_advisor.py` | reads a near-miss diff and suggests the C edit |
| `tools/declorder_search.py` | searches declaration orders for register/slot colour |
| `tools/csweep.py` | sweeps flag/pragma combinations |
| `tools/verify_batch.py` | verify and bank a directory of candidates |
| `tools/pr_linkcheck.py` | what CI runs on a PR |
| `tools/progress.py` | ledger totals |

Deeper background: `notes/mwccarm-codegen.md` (codegen idioms, with the
worked examples), `notes/tooling.md`, `notes/matching-style.md`.

## A note on the older `.cpp` files here

The 37 remaining `.cpp` files predate this corpus and came from a different,
largely automated attempt. Fourteen of them are empty scaffolds with no body at
all. A further 25 described functions that have since been matched properly
under `src/`; those were deleted, because a draft for a function that is
already banked is nothing but a trap for the next reader.

Where a `.c` and a `.cpp` draft exist for the same function, **prefer the
`.c`** - it is regenerated from the current Ghidra project with aligned
prototypes and the corrected size. Either way, check `src/` first.
