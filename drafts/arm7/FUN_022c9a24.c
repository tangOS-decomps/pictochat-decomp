// decomp: module=arm7 addr=0x022c9a24 name=FUN_022c9a24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=5
// verify:  python tools/match.py --c <file> --func FUN_022c9a24 --addr 0x022c9a24 --size 0x1c --module arm7 --version 2.0/sp1


void FUN_022c9a24(int param_1,int param_2,undefined2 param_3)

{
  *(undefined2 *)(*DAT_022c9a3c + param_1 * 0x24 + param_2 * 2 + 0x20) = param_3;
  return;
}

