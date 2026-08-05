// decomp: module=arm7 addr=0x022c6ce8 name=FUN_022c6ce8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=10
// verify:  python tools/match.py --c <file> --func FUN_022c6ce8 --addr 0x022c6ce8 --size 0x44 --module arm7 --version 2.0/sp1


undefined4 FUN_022c6ce8(int param_1)

{
  FUN_022c6d40();
  if (param_1 < *(int *)(DAT_022c6d28 + 4)) {
    *(int *)(DAT_022c6d28 + 8) = *(int *)(DAT_022c6d28 + 8) + 1;
  }
  *(int *)(DAT_022c6d28 + 4) = param_1;
  FUN_022c6d54();
  return *(undefined4 *)(DAT_022c6d28 + 8);
}

