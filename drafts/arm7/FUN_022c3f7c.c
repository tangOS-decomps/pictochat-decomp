// decomp: module=arm7 addr=0x022c3f7c name=FUN_022c3f7c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x174, arm
// triage: noise=8 statements=80
// verify:  python tools/match.py --c <file> --func FUN_022c3f7c --addr 0x022c3f7c --size 0x174 --module arm7 --version 2.0/sp1


/* WARNING: Removing unreachable block (ram,0x022c3f1c) */
/* WARNING: Removing unreachable block (ram,0x022c3f20) */
/* WARNING: Removing unreachable block (ram,0x022c3f24) */
/* WARNING: Removing unreachable block (ram,0x022c3f28) */
/* WARNING: Removing unreachable block (ram,0x022c3f54) */
/* WARNING: Removing unreachable block (ram,0x022c3fb4) */

ulonglong FUN_022c3f7c(uint param_1,uint param_2,uint param_3,uint param_4)

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
    uVar4 = FUN_022c4228(param_1,param_3);
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
      if (iVar7 == 0) goto LAB_022c3f0c;
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
LAB_022c3f0c:
  return CONCAT44(iVar9,uVar4);
}

