// decomp: module=unk_autoload_0 addr=0x02337584 name=FUN_02337584
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x130, arm
// triage: noise=2 statements=97
// verify:  python tools/match.py --c <file> --func FUN_02337584 --addr 0x02337584 --size 0x130 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337584(ushort *param_1,ushort *param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  if (param_3 == 0) {
    return;
  }
  if (((uint)param_2 & 1) != 0) {
    if (((uint)param_1 & 1) == 0) {
      uVar1 = *param_1;
    }
    else {
      uVar1 = *(ushort *)((int)param_1 + -1) >> 8;
    }
    *(ushort *)((int)param_2 + -1) = *(ushort *)((int)param_2 + -1) & 0xff | uVar1 << 8;
    param_1 = (ushort *)((int)param_1 + 1);
    param_2 = (ushort *)((int)param_2 + 1);
    param_3 = param_3 - 1;
    if (param_3 == 0) {
      return;
    }
  }
  if ((((uint)param_2 ^ (uint)param_1) & 1) == 0) {
    puVar3 = param_2;
    if ((((uint)param_2 ^ (uint)param_1) & 2) == 0) {
      if (1 < param_3) {
        puVar4 = param_1;
        puVar6 = param_2;
        if (((uint)param_2 & 2) != 0) {
          puVar4 = param_1 + 1;
          puVar6 = param_2 + 1;
          *param_2 = *param_1;
          param_3 = param_3 - 2;
          if (param_3 == 0) {
            return;
          }
        }
        if ((param_3 & 0xfffffffc) != 0) {
          puVar7 = (ushort *)((param_3 & 0xfffffffc) + (int)puVar6);
          puVar3 = puVar4;
          puVar5 = puVar6;
          do {
            puVar4 = puVar3 + 2;
            puVar6 = puVar5 + 2;
            *(undefined4 *)puVar5 = *(undefined4 *)puVar3;
            puVar3 = puVar4;
            puVar5 = puVar6;
          } while (puVar6 < puVar7);
        }
        param_1 = puVar4;
        puVar3 = puVar6;
        if ((param_3 & 2) != 0) {
          param_1 = puVar4 + 1;
          puVar3 = puVar6 + 1;
          *puVar6 = *puVar4;
        }
      }
    }
    else if ((param_3 & 0xfffffffe) != 0) {
      puVar4 = param_1;
      puVar6 = param_2;
      do {
        param_1 = puVar4 + 1;
        puVar3 = puVar6 + 1;
        *puVar6 = *puVar4;
        puVar4 = param_1;
        puVar6 = puVar3;
      } while (puVar3 < (ushort *)((param_3 & 0xfffffffe) + (int)param_2));
    }
    if ((param_3 & 1) != 0) {
      *puVar3 = *puVar3 & 0xff00 | *param_1 & 0xff;
      return;
    }
    return;
  }
  param_1 = (ushort *)((uint)param_1 & 0xfffffffe);
  uVar1 = *param_1;
  while( true ) {
    uVar2 = uVar1 >> 8;
    if (param_3 < 2) break;
    param_1 = param_1 + 1;
    uVar1 = *param_1;
    *param_2 = uVar2 | uVar1 << 8;
    param_2 = param_2 + 1;
    param_3 = param_3 - 2;
  }
  if ((param_3 - 2 & 1) != 0) {
    *param_2 = *param_2 & 0xff00 | uVar2;
    return;
  }
  return;
}

