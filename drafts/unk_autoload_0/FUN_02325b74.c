// decomp: module=unk_autoload_0 addr=0x02325b74 name=FUN_02325b74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8, thumb
// triage: noise=0 statements=33  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02325b74 --addr 0x02325b74 --size 0xb8 --module unk_autoload_0 --version 2.0/sp1


int FUN_02325b74(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_02327990();
  iVar2 = (uVar1 & 0xfffffff8) + 0x18;
  iVar2 = ((int)(iVar2 + ((uint)(iVar2 >> 2) >> 0x1d)) >> 3) * 0x20;
  if (param_3 != 0) {
    FUN_0233746c(0,param_1,iVar2);
    FUN_0233746c(0,param_1 + 0x400,iVar2);
  }
  *param_2 = 5;
  while ((iVar3 = FUN_02325c2c(param_1,0x800), iVar3 != 0 && (*param_2 != 0))) {
    param_1 = param_1 + 0x800;
    *param_2 = *param_2 + -1;
  }
  if (*param_2 != 0) {
    if (0 < *param_2) {
      while (iVar3 = FUN_02325c2c(param_1 + (*param_2 + -1) * 0x800,0x800), iVar3 != 0) {
        *param_2 = *param_2 + -1;
      }
      if ((param_3 != 0) &&
         ((iVar3 = FUN_02325c2c(param_1,iVar2), iVar3 == 0 ||
          (iVar2 = FUN_02325c2c(param_1 + 0x400,iVar2), iVar2 == 0)))) {
        *param_2 = *param_2 + 1;
        param_1 = param_1 + -0x800;
      }
    }
    return param_1;
  }
  return 0;
}

