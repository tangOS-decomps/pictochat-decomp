// decomp: module=arm7 addr=0x022da0e8 name=FUN_022da0e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=4
// verify:  python tools/match.py --c <file> --func FUN_022da0e8 --addr 0x022da0e8 --size 0x20 --module arm7 --version 2.0/sp1


undefined2 FUN_022da0e8(int param_1)

{
  return *(undefined2 *)(param_1 * 0x1c + *(int *)(*DAT_022da104 + 0x31c) + 2);
}

