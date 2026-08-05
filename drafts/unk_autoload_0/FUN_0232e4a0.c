// decomp: module=unk_autoload_0 addr=0x0232e4a0 name=FUN_0232e4a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, thumb
// triage: noise=2 statements=29
// verify:  python tools/match.py --c <file> --func FUN_0232e4a0 --addr 0x0232e4a0 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e4a0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_18;
  
  iVar6 = 0;
  uVar5 = 0xffffffff;
  local_18 = 0;
  iVar4 = *(int *)(param_1 + 0x28);
  if (iVar4 != 0) {
    do {
      uVar1 = *(uint *)(iVar4 + 4);
      uVar3 = (uVar1 + iVar4 + 0x10) - param_2 & ~(param_3 - 1U);
      if (((-1 < (int)(uVar3 - (iVar4 + 0x10))) && (uVar1 < uVar5)) &&
         ((iVar6 = iVar4, local_18 = uVar3, (*(ushort *)(param_1 + 0x36) & 1) == 0 ||
          (uVar5 = uVar1, uVar1 == param_2)))) break;
      iVar4 = *(int *)(iVar4 + 8);
    } while (iVar4 != 0);
  }
  if (iVar6 != 0) {
    uVar2 = FUN_0232e324(param_1 + 0x24,iVar6,local_18,param_2,1);
    return uVar2;
  }
  return 0;
}

