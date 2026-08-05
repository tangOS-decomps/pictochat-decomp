// decomp: module=unk_autoload_0 addr=0x023274b4 name=FUN_023274b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_023274b4 --addr 0x023274b4 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_023274b4(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 in_r3;
  int iVar4;
  
  FUN_0233746c(0,DAT_023274ec,0x940,in_r3,in_r3);
  uVar2 = DAT_023274f4;
  iVar1 = DAT_023274ec;
  iVar4 = 0;
  *DAT_023274f0 = 0;
  do {
    pvVar3 = FUN_023215e4();
    FUN_02321664(pvVar3,iVar1 + iVar4 * 0x94 + 0x50,uVar2,1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  return;
}

