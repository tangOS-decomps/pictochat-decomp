// decomp: module=itcm addr=0x01ff81b4 name=FUN_01ff81b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=47
// verify:  python tools/match.py --c <file> --func FUN_01ff81b4 --addr 0x01ff81b4 --size 0x98 --module itcm --version 2.0/sp1


int FUN_01ff81b4(int param_1,int *param_2,int param_3,int param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 in_r12;
  
  if ((param_5 & 1) == 0) {
    in_r12 = FUN_02332080();
  }
  piVar1 = DAT_01ff8244;
  piVar4 = DAT_01ff8244 + param_1 * 3;
  if ((param_5 & 0x10) == 0) {
    iVar3 = 0x20;
    if ((param_5 & 0x20) != 0) {
      iVar3 = param_1 * 4;
      *(short *)(DAT_01ff8244 + param_1 + 0xc) = (short)param_2;
      param_2 = piVar1 + param_1 + 0xc;
    }
  }
  else {
    iVar3 = param_1 * 4;
    DAT_01ff8244[param_1 + 0xc] = (int)param_2;
    param_2 = piVar1 + param_1 + 0xc;
  }
  *piVar4 = (int)param_2;
  piVar4[1] = param_3;
  piVar4[2] = param_4;
  iVar2 = 2;
  if ((param_5 & 2) != 0) {
    iVar3 = *DAT_01ff8244;
    iVar2 = 4;
    if (((param_5 & 4) == 0) && (param_1 == 0)) {
      *piVar4 = 0;
      piVar4[1] = 0;
      iVar2 = DAT_01ff8248;
      piVar4[2] = DAT_01ff8248;
    }
  }
  if ((param_5 & 1) == 0) {
    iVar2 = FUN_02332094(in_r12,iVar3);
  }
  if ((param_5 & 2) != 0) {
    iVar2 = *DAT_01ff8244;
  }
  return iVar2;
}

