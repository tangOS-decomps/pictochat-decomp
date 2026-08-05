// decomp: module=unk_autoload_0 addr=0x0232e424 name=FUN_0232e424
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c, thumb
// triage: noise=2 statements=29
// verify:  python tools/match.py --c <file> --func FUN_0232e424 --addr 0x0232e424 --size 0x7c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e424(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  
  iVar6 = 0;
  uVar5 = 0xffffffff;
  local_1c = 0;
  iVar4 = *(int *)(param_1 + 0x24);
  if (iVar4 != 0) {
    do {
      uVar3 = ~(param_3 - 1U) & (param_3 - 1U) + iVar4 + 0x10;
      uVar1 = *(uint *)(iVar4 + 4);
      if (((param_2 + (uVar3 - (iVar4 + 0x10)) <= uVar1) && (uVar1 < uVar5)) &&
         ((iVar6 = iVar4, local_1c = uVar3, (*(ushort *)(param_1 + 0x36) & 1) == 0 ||
          (uVar5 = uVar1, uVar1 == param_2)))) break;
      iVar4 = *(int *)(iVar4 + 0xc);
    } while (iVar4 != 0);
  }
  if (iVar6 != 0) {
    uVar2 = FUN_0232e324((int *)(param_1 + 0x24),iVar6,local_1c,param_2,0);
    return uVar2;
  }
  return 0;
}

