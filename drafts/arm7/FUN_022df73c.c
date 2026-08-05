// decomp: module=arm7 addr=0x022df73c name=FUN_022df73c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022df73c --addr 0x022df73c --size 0xa8 --module arm7 --version 2.0/sp1


int FUN_022df73c(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *DAT_022df7dc;
  iVar2 = func_0x037c58fc(iVar3 + 0x188,0x5e);
  if (iVar2 == 0) {
    FUN_022d9088(2);
    iVar2 = 0;
  }
  else {
    *(short *)(iVar2 + 0xc) = (short)DAT_022df7e0;
    FUN_022dffc4(iVar2 + 0x10,param_1);
    *(undefined2 *)(iVar2 + 0x3c) = *(undefined2 *)(iVar3 + 0x3c0);
    *(undefined2 *)(iVar2 + 0x3e) = *(undefined2 *)(iVar3 + 0x3b4);
    iVar3 = FUN_022e0078(iVar2 + 0x40);
    sVar1 = FUN_022e00ec(iVar2 + 0x40 + iVar3);
    *(short *)(iVar2 + 0x16) = (short)iVar3 + sVar1 + 4;
    *(short *)(iVar2 + 0x22) = *(short *)(iVar2 + 0x16) + 0x1c;
    *(undefined2 *)(iVar2 + 0x24) = 0;
    iVar2 = iVar2 + 0x10;
  }
  return iVar2;
}

