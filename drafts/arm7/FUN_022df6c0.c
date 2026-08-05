// decomp: module=arm7 addr=0x022df6c0 name=FUN_022df6c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022df6c0 --addr 0x022df6c0 --size 0x7c --module arm7 --version 2.0/sp1


int FUN_022df6c0(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = func_0x037c58fc(*DAT_022df734 + 0x188,0x36);
  if (iVar1 == 0) {
    FUN_022d9088(2);
    iVar1 = 0;
  }
  else {
    *(short *)(iVar1 + 0xc) = (short)DAT_022df738;
    FUN_022dffc4(iVar1 + 0x10,param_1);
    *(undefined2 *)(iVar1 + 0x3c) = param_2;
    *(undefined2 *)(iVar1 + 0x16) = 2;
    *(undefined2 *)(iVar1 + 0x22) = 0x1e;
    *(undefined2 *)(iVar1 + 0x24) = 0xa0;
    iVar1 = iVar1 + 0x10;
  }
  return iVar1;
}

