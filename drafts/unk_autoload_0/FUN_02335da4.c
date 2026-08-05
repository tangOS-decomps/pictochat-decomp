// decomp: module=unk_autoload_0 addr=0x02335da4 name=FUN_02335da4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x140, arm
// triage: noise=8 statements=80
// verify:  python tools/match.py --c <file> --func FUN_02335da4 --addr 0x02335da4 --size 0x140 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x02335d44) */
/* WARNING: Removing unreachable block (ram,0x02335d48) */
/* WARNING: Removing unreachable block (ram,0x02335d4c) */
/* WARNING: Removing unreachable block (ram,0x02335d50) */
/* WARNING: Removing unreachable block (ram,0x02335d7c) */
/* WARNING: Removing unreachable block (ram,0x02335ddc) */

ulonglong FUN_02335da4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  
  if (param_4 == 0 && param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_2 == 0 && param_4 == 0) {
    uVar4 = FUN_02336020(param_1,param_3);
    return (ulonglong)uVar4;
  }
  if (param_2 == 0 && param_1 == 0) {
    return 0;
  }
  iVar7 = 1;
  iVar8 = 0;
  if (-1 < (int)param_4) {
    do {
      iVar7 = iVar8;
      bVar10 = CARRY4(param_3,param_3);
      param_3 = param_3 * 2;
      param_4 = param_4 * 2 + (uint)bVar10;
      iVar8 = iVar7 + 1;
    } while (-1 < (int)param_4);
    iVar7 = iVar7 + 2;
  }
  for (; (-1 < (int)param_2 && (iVar7 != 1)); iVar7 = iVar7 + -1) {
    bVar10 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    param_2 = param_2 * 2 + (uint)bVar10;
  }
  iVar8 = 0;
  uVar4 = 0;
  iVar9 = 0;
  while( true ) {
    uVar3 = param_1 - param_3;
    uVar5 = param_2 - (param_4 + (param_3 > param_1));
    iVar9 = iVar9 * 2 + (uint)CARRY4(uVar4,uVar4);
    for (iVar8 = iVar8 - (uint)(param_2 <= param_4 &&
                               (uint)(param_3 <= param_1) <= param_2 - param_4); uVar4 = uVar4 * 2,
        iVar8 < 0;
        iVar8 = iVar8 * 2 + (uint)(bVar10 || CARRY4(uVar2,(uint)bVar11)) +
                (uint)(CARRY4(uVar6,param_4) || CARRY4(uVar6 + param_4,(uint)CARRY4(uVar1,param_3)))
        ) {
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) goto LAB_02335d34;
      bVar11 = CARRY4(uVar3,uVar3);
      uVar1 = uVar3 * 2;
      uVar2 = uVar5 * 2;
      bVar10 = CARRY4(uVar5,uVar5);
      uVar6 = uVar5 * 2 + (uint)bVar11;
      uVar3 = uVar1 + param_3;
      uVar5 = uVar6 + param_4 + (uint)CARRY4(uVar1,param_3);
      iVar9 = iVar9 * 2 + (uint)CARRY4(uVar4,uVar4);
    }
    uVar4 = uVar4 | 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) break;
    param_1 = uVar3 * 2;
    param_2 = uVar5 * 2 + (uint)CARRY4(uVar3,uVar3);
    iVar8 = iVar8 * 2 + (uint)(CARRY4(uVar5,uVar5) || CARRY4(uVar5 * 2,(uint)CARRY4(uVar3,uVar3)));
  }
LAB_02335d34:
  return CONCAT44(iVar9,uVar4);
}

