// decomp: module=arm7 addr=0x022d9ffc name=FUN_022d9ffc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=4
// verify:  python tools/match.py --c <file> --func FUN_022d9ffc --addr 0x022d9ffc --size 0x20 --module arm7 --version 2.0/sp1


undefined2 FUN_022d9ffc(int param_1)

{
  return *(undefined2 *)(*(int *)(*DAT_022da018 + 0x31c) + param_1 * 0x1c);
}

