// decomp: module=arm7 addr=0x022c864c name=FUN_022c864c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022c864c --addr 0x022c864c --size 0x28 --module arm7 --version 2.0/sp1


void FUN_022c864c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = DAT_022c8670;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 0x34) = param_2;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 2;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfe | 1;
  return;
}

