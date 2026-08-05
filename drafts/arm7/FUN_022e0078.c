// decomp: module=arm7 addr=0x022e0078 name=FUN_022e0078
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022e0078 --addr 0x022e0078 --size 0x74 --module arm7 --version 2.0/sp1


int FUN_022e0078(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = *DAT_022e00e8;
  uVar4 = (uint)*(ushort *)(iVar2 + 0x362);
  FUN_022d8d40(param_1,0);
  FUN_022d8d40(param_1 + 1,uVar4 & 0xff);
  iVar3 = 2;
  for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1) {
    uVar1 = FUN_022d8d6c(iVar2 + 0x364 + uVar5);
    FUN_022d8d40(param_1 + iVar3,uVar1);
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

