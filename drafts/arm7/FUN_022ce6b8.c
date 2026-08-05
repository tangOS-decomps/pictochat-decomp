// decomp: module=arm7 addr=0x022ce6b8 name=FUN_022ce6b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022ce6b8 --addr 0x022ce6b8 --size 0x60 --module arm7 --version 2.0/sp1


void FUN_022ce6b8(void)

{
  undefined4 uVar1;
  char *pcVar2;
  
  uVar1 = func_0x037cb520();
  func_0x037c9d2c();
  func_0x037c9b84(DAT_022ce710,*(undefined4 *)(DAT_022ce70c + 0x578));
  pcVar2 = FUN_022d6bec();
  func_0x037c9b84(pcVar2,*(undefined4 *)(DAT_022ce70c + 0x57c));
  func_0x037c9b84(DAT_022ce714,*(undefined4 *)(DAT_022ce70c + 0x580));
  func_0x037c9d64();
  func_0x037cb534(uVar1);
  return;
}

