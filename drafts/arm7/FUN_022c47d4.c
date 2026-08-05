// decomp: module=arm7 addr=0x022c47d4 name=FUN_022c47d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022c47d4 --addr 0x022c47d4 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022c47d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_022c4818;
  iVar2 = param_1 * 0xc;
  *(undefined4 *)(DAT_022c4814 + iVar2) = param_2;
  *(undefined4 *)(iVar1 + iVar2) = param_3;
  FUN_022c486c(1 << (param_1 + 3U & 0xff));
  *(undefined4 *)(DAT_022c481c + iVar2) = 1;
  return;
}

