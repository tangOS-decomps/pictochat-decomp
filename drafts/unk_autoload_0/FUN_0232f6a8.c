// decomp: module=unk_autoload_0 addr=0x0232f6a8 name=FUN_0232f6a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x9e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=47  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232f6a8 --addr 0x0232f6a8 --size 0xa4 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232f6a8(uint param_1,int param_2,uint param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_20;
  
  iVar4 = *DAT_0232f748;
  if (*(uint *)(*(int *)(iVar4 + 0x84) + 8) <= param_1) {
    return -1;
  }
  piVar1 = (int *)(*(int *)(iVar4 + 0x84) + 0xc + param_1 * 0x10);
  local_20 = *(uint *)(iVar4 + 0x90);
  if (local_20 == 0) {
    local_20 = param_3;
  }
  iVar5 = 0;
  if (0 < (int)param_3) {
    do {
      uVar6 = param_3 - iVar5;
      if ((int)local_20 < (int)(param_3 - iVar5)) {
        uVar6 = local_20;
      }
      uVar2 = piVar1[1] - param_4;
      if (uVar2 < uVar6) {
        uVar6 = uVar2;
      }
      if (uVar6 == 0) {
        return iVar5;
      }
      iVar3 = FUN_02338a3c(iVar4 + 0x34,*piVar1 + param_4,0);
      if (iVar3 == 0) {
        return -1;
      }
      iVar3 = FUN_02338a54(iVar4 + 0x34,param_2,uVar6);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar5 = iVar5 + iVar3;
      param_4 = param_4 + iVar3;
      param_2 = param_2 + iVar3;
    } while (iVar5 < (int)param_3);
  }
  return iVar5;
}

