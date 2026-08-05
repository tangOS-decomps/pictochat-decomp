// decomp: module=unk_autoload_0 addr=0x02334a18 name=FUN_02334a18
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x106, thumb
// triage: noise=5 statements=79
// verify:  python tools/match.py --c <file> --func FUN_02334a18 --addr 0x02334a18 --size 0x106 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334a18(undefined1 *param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte extraout_r1;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  byte abStack_58 [64];
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  iVar7 = 0;
  iVar3 = (uint)*(byte *)(param_2 + 4) + (uint)*(byte *)(param_3 + 4);
  iVar10 = iVar3 + -1;
  pbVar8 = abStack_58 + iVar3;
  *param_1 = 0;
  pbVar9 = pbVar8;
  if (0 < iVar10) {
    do {
      iVar4 = *(byte *)(param_3 + 4) - 1;
      iVar3 = (iVar10 - iVar4) + -1;
      if (iVar3 < 0) {
        iVar3 = 0;
        iVar4 = iVar10 + -1;
      }
      pbVar5 = (byte *)(param_2 + 5 + iVar3);
      pbVar6 = (byte *)(param_3 + 5 + iVar4);
      iVar3 = (uint)*(byte *)(param_2 + 4) - iVar3;
      iVar2 = iVar4 + 1;
      if (iVar3 < iVar4 + 1) {
        iVar2 = iVar3;
      }
      for (; 0 < iVar2; iVar2 = iVar2 + -1) {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        iVar7 = iVar7 + (uint)bVar1 * (uint)*pbVar6;
        pbVar6 = pbVar6 + -1;
      }
      pbVar9 = pbVar9 + -1;
      FUN_02336018(iVar7,10);
      *pbVar9 = extraout_r1;
      iVar7 = FUN_02336018(iVar7,10);
      iVar10 = iVar10 + -1;
    } while (0 < iVar10);
  }
  *(short *)(param_1 + 2) = *(short *)(param_2 + 2) + *(short *)(param_3 + 2);
  if (iVar7 != 0) {
    pbVar9 = pbVar9 + -1;
    *pbVar9 = (byte)iVar7;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  }
  iVar7 = 0;
  for (; (iVar7 < 0x20 && (pbVar9 < pbVar8)); pbVar9 = pbVar9 + 1) {
    param_1[iVar7 + 5] = *pbVar9;
    iVar7 = iVar7 + 1;
  }
  param_1[4] = (char)iVar7;
  if ((pbVar9 < pbVar8) && (4 < *pbVar9)) {
    pbVar5 = pbVar9;
    if (*pbVar9 == 5) {
      do {
        pbVar5 = pbVar5 + 1;
        if (pbVar8 <= pbVar5) {
          if ((pbVar9[-1] & 1) == 0) {
            return;
          }
          break;
        }
      } while (*pbVar5 == 0);
    }
    FUN_02334948(param_1,param_1[4]);
  }
  return;
}

