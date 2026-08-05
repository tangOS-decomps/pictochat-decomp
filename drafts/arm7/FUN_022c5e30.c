// decomp: module=arm7 addr=0x022c5e30 name=FUN_022c5e30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022c5e30 --addr 0x022c5e30 --size 0xa8 --module arm7 --version 2.0/sp1


undefined4 FUN_022c5e30(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  FUN_022c6d40();
  *(undefined4 **)(DAT_022c5ed4 + param_1 * 4) = param_2;
  param_2[4] = param_2 + 5;
  param_2[1] = param_4;
  for (iVar2 = 0; iVar2 < (int)param_2[1]; iVar2 = iVar2 + 1) {
    iVar1 = param_2[4];
    *(undefined4 *)(iVar1 + iVar2 * 0xc) = 0xffffffff;
    iVar1 = iVar1 + iVar2 * 0xc;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  *param_2 = 0xffffffff;
  param_2[2] = param_2[4] + param_4 * 0xc + 0x1fU & 0xffffffe0;
  param_2[3] = param_3 & 0xffffffe0;
  FUN_022c6d54();
  return param_2[2];
}

