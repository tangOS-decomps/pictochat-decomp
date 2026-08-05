// decomp: module=unk_autoload_0 addr=0x02335db0 name=FUN_02335db0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, arm
// triage: noise=7 statements=84
// verify:  python tools/match.py --c <file> --func FUN_02335db0 --addr 0x02335db0 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x02335d3c) */
/* WARNING: Removing unreachable block (ram,0x02335d38) */
/* WARNING: Removing unreachable block (ram,0x02335d7c) */

ulonglong FUN_02335db0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r1;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  if (param_4 == 0 && param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_2 == 0 && param_4 == 0) {
    FUN_02336020(param_1,param_3);
    return (ulonglong)extraout_r1;
  }
  if (param_2 == 0 && param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar6 = 0;
    iVar7 = 1;
    if (-1 < (int)param_4) {
      do {
        uVar4 = uVar6;
        uVar6 = uVar4 + 1;
        bVar9 = CARRY4(param_3,param_3);
        param_3 = param_3 * 2;
        param_4 = param_4 * 2 + (uint)bVar9;
      } while (-1 < (int)param_4);
      iVar7 = uVar4 + 2;
    }
    for (; (-1 < (int)param_2 && (iVar7 != 1)); iVar7 = iVar7 + -1) {
      bVar9 = CARRY4(param_1,param_1);
      param_1 = param_1 * 2;
      param_2 = param_2 * 2 + (uint)bVar9;
    }
    iVar8 = 0;
    while( true ) {
      uVar3 = param_1 - param_3;
      uVar4 = param_2 - (param_4 + (param_3 > param_1));
      for (iVar8 = iVar8 - (uint)(param_2 <= param_4 &&
                                 (uint)(param_3 <= param_1) <= param_2 - param_4); iVar8 < 0;
          iVar8 = iVar8 * 2 + (uint)(bVar9 || CARRY4(uVar2,(uint)bVar10)) +
                  (uint)(CARRY4(uVar5,param_4) ||
                        CARRY4(uVar5 + param_4,(uint)CARRY4(uVar1,param_3)))) {
        iVar7 = iVar7 + -1;
        if (iVar7 == 0) {
          bVar9 = CARRY4(uVar3,param_3);
          uVar3 = uVar3 + param_3;
          uVar4 = uVar4 + param_4 + (uint)bVar9;
          goto LAB_02335d34;
        }
        bVar10 = CARRY4(uVar3,uVar3);
        uVar1 = uVar3 * 2;
        uVar2 = uVar4 * 2;
        bVar9 = CARRY4(uVar4,uVar4);
        uVar5 = uVar4 * 2 + (uint)bVar10;
        uVar3 = uVar1 + param_3;
        uVar4 = uVar5 + param_4 + (uint)CARRY4(uVar1,param_3);
      }
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) break;
      param_1 = uVar3 * 2;
      param_2 = uVar4 * 2 + (uint)CARRY4(uVar3,uVar3);
      iVar8 = iVar8 * 2 + (uint)(CARRY4(uVar4,uVar4) || CARRY4(uVar4 * 2,(uint)CARRY4(uVar3,uVar3)))
      ;
    }
LAB_02335d34:
    if ((int)uVar6 < 0x20) {
      return CONCAT44(uVar4 >> (uVar6 & 0xff),
                      uVar3 >> (uVar6 & 0xff) | uVar4 << (0x20 - uVar6 & 0xff));
    }
    uVar4 = uVar4 >> (uVar6 - 0x20 & 0xff);
  }
  return (ulonglong)uVar4;
}

