// decomp: module=unk_autoload_0 addr=0x0233029c name=FUN_0233029c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x130 (Ghidra's cache says 0x128 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=99  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233029c --addr 0x0233029c --size 0x130 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233029c(int param_1,int param_2,uint param_3,int param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  short *psVar8;
  short local_18 [2];
  
  uVar7 = DAT_023303c8;
  iVar2 = (param_3 >> 1) * 2;
  iVar5 = 0;
  psVar6 = local_18;
  do {
    uVar3 = (int)*(short *)(param_1 + iVar2 + iVar5 * 2 + -4) -
            (int)*(short *)(param_2 + iVar2 + iVar5 * 2 + -4);
    uVar4 = DAT_023303c4;
    if (((int)DAT_023303c4 <= (int)uVar3) &&
       (uVar4 = uVar3, (int)(DAT_023303c4 >> 0x11) < (int)uVar3)) {
      uVar4 = DAT_023303c8;
    }
    iVar5 = iVar5 + 1;
    *psVar6 = (short)uVar4;
    psVar6 = psVar6 + 1;
  } while (iVar5 < 2);
  iVar2 = ((param_3 >> 1) - 1) * 2;
  psVar8 = (short *)(param_2 + iVar2);
  uVar4 = DAT_023303c4;
  for (psVar6 = (short *)(param_1 + iVar2); DAT_023303c4 = uVar4, (short *)(param_1 + 4) <= psVar6;
      psVar6 = psVar6 + -1) {
    iVar2 = (int)psVar6[-2] - (int)psVar8[-2];
    iVar5 = *psVar8 - iVar2;
    uVar3 = *psVar6 + iVar2;
    if (iVar2 < 0) {
      if ((int)uVar4 < (int)uVar3) {
        uVar4 = uVar3;
      }
      *psVar6 = (short)uVar4;
      if (iVar5 < (int)DAT_023303c8) {
        *psVar8 = (short)iVar5;
      }
      else {
        *psVar8 = (short)uVar7;
      }
    }
    else {
      if ((int)uVar3 < (int)DAT_023303c8) {
        *psVar6 = (short)uVar3;
      }
      else {
        *psVar6 = (short)uVar7;
      }
      if ((int)DAT_023303c4 < iVar5) {
        *psVar8 = (short)iVar5;
      }
      else {
        *psVar8 = (short)DAT_023303c4;
      }
    }
    psVar8 = psVar8 + -1;
    uVar4 = DAT_023303c4;
  }
  iVar2 = 1;
  psVar6 = (short *)(param_1 + 2);
  psVar8 = (short *)(param_2 + 2);
  iVar5 = param_4 + 4;
  do {
    uVar3 = (int)*psVar6 + *(int *)(iVar5 + 0x18);
    uVar7 = uVar4;
    if (((int)DAT_023303c4 <= (int)uVar3) &&
       (uVar7 = uVar3, (int)(DAT_023303c4 >> 0x11) < (int)uVar3)) {
      uVar7 = DAT_023303c8;
    }
    *psVar6 = (short)uVar7;
    uVar3 = (int)*psVar8 - *(int *)(iVar5 + 0x18);
    uVar7 = uVar4;
    if (((int)DAT_023303c4 <= (int)uVar3) &&
       (uVar7 = uVar3, (int)(DAT_023303c4 >> 0x11) < (int)uVar3)) {
      uVar7 = DAT_023303c8;
    }
    *psVar8 = (short)uVar7;
    iVar5 = iVar5 + -4;
    psVar6 = psVar6 + -1;
    psVar8 = psVar8 + -1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  iVar2 = 0;
  psVar6 = local_18;
  do {
    sVar1 = *psVar6;
    iVar2 = iVar2 + 1;
    psVar6 = psVar6 + 1;
    *(int *)(param_4 + 0x18) = (int)sVar1;
    param_4 = param_4 + 4;
  } while (iVar2 < 2);
  return;
}

