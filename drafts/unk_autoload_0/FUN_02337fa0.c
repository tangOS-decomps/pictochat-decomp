// decomp: module=unk_autoload_0 addr=0x02337fa0 name=FUN_02337fa0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80, thumb
// triage: noise=9 statements=45
// verify:  python tools/match.py --c <file> --func FUN_02337fa0 --addr 0x02337fa0 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337fa0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_02337980();
  iVar3 = param_2 * 8;
  iVar7 = param_1 + iVar3;
  iVar6 = *(int *)(iVar7 + 0x18);
  if (iVar6 != 0) {
    if (param_3 == iVar6) {
      FUN_02337990();
      return;
    }
    iVar5 = param_1 + 0x18 + iVar3;
    iVar2 = *(int *)(iVar6 + 0x18);
    if (iVar5 == *(int *)(iVar6 + 0x18)) {
      *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(iVar7 + 0x1c);
      FUN_023314e8(*(undefined4 *)(iVar7 + 0x18),0x3c,iVar6,iVar7,param_4);
    }
    else {
      do {
        iVar1 = iVar2;
        if (iVar1 == 0) break;
        iVar6 = *(int *)(iVar1 + 4);
        iVar2 = iVar6;
      } while (iVar5 != iVar6);
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + iVar3 + 0x1c);
      FUN_023314e8(iVar1,8,iVar6,iVar7,param_4);
    }
  }
  uVar4 = *(undefined4 *)(param_3 + 0x18);
  param_2 = param_2 * 8;
  *(int *)(param_3 + 0x18) = param_1 + 0x18 + param_2;
  *(undefined4 *)(param_1 + param_2 + 0x1c) = uVar4;
  *(int *)(param_1 + 0x18 + param_2) = param_3;
  FUN_02337990();
  FUN_023314e8(param_1,0x3c);
  FUN_023314e8(param_3,0x3c);
  return;
}

