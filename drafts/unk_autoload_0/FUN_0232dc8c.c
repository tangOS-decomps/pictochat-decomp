// decomp: module=unk_autoload_0 addr=0x0232dc8c name=FUN_0232dc8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8a, thumb
// triage: noise=2 statements=41
// verify:  python tools/match.py --c <file> --func FUN_0232dc8c --addr 0x0232dc8c --size 0x8a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232dc8c(int *param_1,undefined4 param_2,int param_3,int param_4,ushort param_5,
                 undefined4 param_6)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  int local_1c;
  
  uVar1 = *(ushort *)((int)param_1 + 0x16);
  uVar4 = 0;
  uVar2 = 0;
  local_1c = 0;
  puVar6 = (ushort *)(*param_1 + (int)(short)param_1[5] * (uint)param_5 * 2);
  uVar3 = (uVar1 & 0x3ff) >> 5;
  if (uVar3 != 0) {
    do {
      iVar5 = 0;
      if ((uVar1 & 0x1f) != 0) {
        do {
          if (uVar2 == 0) {
            uVar4 = (uint)*puVar6;
          }
          if ((uVar4 & 1) == 0) {
            FUN_0232dc4c(param_2,param_3 + iVar5,param_4 + local_1c,param_6);
          }
          uVar4 = uVar4 >> 1;
          uVar2 = uVar2 + 1;
          if (0xf < uVar2) {
            uVar2 = 0;
            puVar6 = puVar6 + 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(uVar1 & 0x1f));
      }
      local_1c = local_1c + 1;
    } while (local_1c < (int)uVar3);
  }
  return;
}

