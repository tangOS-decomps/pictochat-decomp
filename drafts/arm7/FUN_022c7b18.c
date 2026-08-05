// decomp: module=arm7 addr=0x022c7b18 name=FUN_022c7b18
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_022c7b18 --addr 0x022c7b18 --size 0x48 --module arm7 --version 2.0/sp1


void FUN_022c7b18(undefined4 param_1)

{
  if (*DAT_022c7b50 == 0) {
    *DAT_022c7b50 = 1;
    FUN_022c9c18();
    thunk_EXT_FUN_037fcac8(DAT_022c7b54,DAT_022c7b58,0,DAT_022c7b5c,0x400,param_1);
    thunk_EXT_FUN_037fcde0(DAT_022c7b54);
  }
  return;
}

