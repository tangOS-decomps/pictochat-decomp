// decomp: module=unk_autoload_0 addr=0x02339ebc name=FUN_02339ebc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60, thumb
// triage: noise=11 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02339ebc --addr 0x02339ebc --size 0x60 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339ebc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  undefined4 extraout_r1_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_1;
  iVar3 = iVar1 + 2000;
  iVar4 = param_1[2];
  iVar2 = param_1[1] + -2;
  if (iVar2 < 1) {
    iVar2 = param_1[1] + 10;
    iVar3 = iVar1 + 1999;
  }
  iVar1 = FUN_02335e0c(iVar3,100,iVar1,param_4,param_4);
  FUN_02335e0c(iVar3,100);
  iVar2 = FUN_02335e0c(iVar2 * 0x1a + -2,10);
  FUN_02335e0c(((int)(iVar1 + ((uint)(iVar1 >> 1) >> 0x1e)) >> 2) +
               ((int)(extraout_r1 + ((uint)(extraout_r1 >> 1) >> 0x1e)) >> 2) +
               extraout_r1 + iVar4 + iVar2 + iVar1 * 5,7);
  return extraout_r1_00;
}

