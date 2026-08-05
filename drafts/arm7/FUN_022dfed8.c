// decomp: module=arm7 addr=0x022dfed8 name=FUN_022dfed8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022dfed8 --addr 0x022dfed8 --size 0x94 --module arm7 --version 2.0/sp1


int FUN_022dfed8(undefined4 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 == 0) || (iVar1 = FUN_022df690(), iVar1 != 0)) {
    iVar1 = func_0x037c58fc(*DAT_022dff64 + 0x188,0x36);
    if (iVar1 == 0) {
      FUN_022d9088(2);
      iVar1 = 0;
    }
    else {
      *(short *)(iVar1 + 0xc) = (short)DAT_022dff68;
      FUN_022dffc4(iVar1 + 0x10,param_1);
      *(undefined2 *)(iVar1 + 0x3c) = param_2;
      *(undefined2 *)(iVar1 + 0x16) = 2;
      *(undefined2 *)(iVar1 + 0x22) = 0x1e;
      *(undefined2 *)(iVar1 + 0x24) = 0xc0;
      iVar1 = iVar1 + 0x10;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

