// decomp: module=arm7 addr=0x022d71ec name=FUN_022d71ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xa8 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022d71ec --addr 0x022d71ec --size 0xb0 --module arm7 --version 2.0/sp1


undefined4 FUN_022d71ec(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 10) {
    uVar1 = 5;
  }
  else {
    *(short *)(*DAT_022d7294 + 0x33c) = (short)param_1;
    if (param_2 != 0) {
      *DAT_022d7298 = (short)param_1;
    }
    iVar2 = *DAT_022d7294;
    if (*(short *)(iVar2 + 0x4a4) != 0) {
      iVar3 = *(int *)(iVar2 + 0x4ac) + 0x24;
      iVar4 = iVar3 + (uint)*(ushort *)(iVar2 + 0x3da);
      if (*(short *)(iVar2 + 0x352) == 1) {
        FUN_022d8d40(iVar4 + 6,param_1 & 0xff,iVar3,param_4,param_4);
        FUN_022d8d40(iVar4 + 7,(int)param_1 >> 8 & 0xff);
      }
      else {
        FUN_022d8d40(iVar4 + 6,0xff,iVar3,param_4,param_4);
        FUN_022d8d40(iVar4 + 7,0xff);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}

