// decomp: module=arm7 addr=0x022d8794 name=FUN_022d8794
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022d8794 --addr 0x022d8794 --size 0x68 --module arm7 --version 2.0/sp1


void FUN_022d8794(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  
  *DAT_022d87f8 = 0x100;
  uVar1 = 0;
  local_18 = 0;
  iVar2 = 100;
  do {
    FUN_022e2e4c(iVar2,1,&local_18);
    FUN_022d862c(uVar1,local_18);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (uVar1 < 0x69);
  FUN_022d862c(0x5a,2);
  return;
}

