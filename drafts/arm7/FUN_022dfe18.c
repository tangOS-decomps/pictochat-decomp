// decomp: module=arm7 addr=0x022dfe18 name=FUN_022dfe18
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xb8 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022dfe18 --addr 0x022dfe18 --size 0xc0 --module arm7 --version 2.0/sp1


int FUN_022dfe18(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  short sVar2;
  
  if ((param_3 == 0) || (iVar1 = FUN_022df690(), iVar1 != 0)) {
    iVar1 = func_0x037c58fc(*DAT_022dfed0 + 0x188,param_2 + 0x3d);
    if (iVar1 == 0) {
      FUN_022d9088(2);
      iVar1 = 0;
    }
    else {
      *(short *)(iVar1 + 0xc) = (short)DAT_022dfed4;
      FUN_022dffc4(iVar1 + 0x10,param_1);
      sVar2 = 0;
      if (param_2 != 0) {
        FUN_022d8d40(iVar1 + 0x42,0x10);
        FUN_022d8d40(iVar1 + 0x43,param_2 & 0xff);
        sVar2 = (short)param_2 + 2;
      }
      *(short *)(iVar1 + 0x16) = sVar2 + 6;
      *(short *)(iVar1 + 0x22) = *(short *)(iVar1 + 0x16) + 0x1c;
      *(undefined2 *)(iVar1 + 0x24) = 0xb0;
      iVar1 = iVar1 + 0x10;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

