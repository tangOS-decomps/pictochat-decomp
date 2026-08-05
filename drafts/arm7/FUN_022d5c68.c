// decomp: module=arm7 addr=0x022d5c68 name=FUN_022d5c68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022d5c68 --addr 0x022d5c68 --size 0xa8 --module arm7 --version 2.0/sp1


ulonglong FUN_022d5c68(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 & 0x8000) == 0) {
    param_2 = (param_2 + 0x1c) * 4 + 0x66;
  }
  else {
    param_2 = param_2 & DAT_022d5d04;
  }
  iVar2 = thunk_EXT_FUN_037fef94(param_3);
  for (iVar3 = (param_4 + -2) - (uint)*DAT_022d5d08; iVar3 < 0; iVar3 = iVar3 + 0x107) {
  }
  lVar1 = (longlong)DAT_022d5d0c * (longlong)(iVar3 * 0x7f);
  iVar3 = (int)(lVar1 >> 0x23) - (iVar3 * 0x7f >> 0x1f);
  if ((uint)(iVar3 * 10) < (param_1 + 0x22) * 4 + param_2 * iVar2 + 1000) {
    iVar3 = 0;
  }
  return CONCAT44((int)lVar1,iVar3) & 0xffffffff0000ffff;
}

