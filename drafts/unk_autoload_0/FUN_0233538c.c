// decomp: module=unk_autoload_0 addr=0x0233538c name=FUN_0233538c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x364 (Ghidra's cache says 0x360 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=191
// verify:  python tools/match.py --c <file> --func FUN_0233538c --addr 0x0233538c --size 0x364 --module unk_autoload_0 --version 2.0/sp1


ulonglong FUN_0233538c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  uVar12 = param_2 ^ param_4;
  uVar13 = uVar12 & 0x80000000;
  uVar9 = param_2 >> 0x14;
  param_2 = param_2 << 0xb;
  uVar4 = param_1 >> 0x15;
  uVar5 = param_2 | uVar4;
  param_1 = param_1 << 0xb;
  uVar6 = param_1;
  if (uVar9 * 0x200000 == 0 || uVar9 * 0x200000 == -0x200000) {
    if ((uVar9 & 0xfffff7ff) != 0) {
      if (param_1 != 0 || ((param_2 & 0x7fffffff) != 0 || uVar4 != 0)) {
        return 0x7fffffffffffffff;
      }
      iVar10 = (param_4 >> 0x14) * 0x200000;
      if (iVar10 == 0) {
        if ((param_4 << 0xb == 0 && param_3 >> 0x15 == 0) && param_3 << 0xb == 0) {
          return 0x7fffffffffffffff;
        }
      }
      else if ((iVar10 == -0x200000) &&
              (param_3 << 0xb != 0 || ((param_4 << 0xb & 0x7fffffff) != 0 || param_3 >> 0x15 != 0)))
      {
        return 0x7fffffffffffffff;
      }
      goto LAB_02335668;
    }
    if (param_1 == 0 && ((param_2 & 0x7fffffff) == 0 && uVar4 == 0)) {
      iVar10 = (param_4 >> 0x14) * 0x200000;
      if ((iVar10 != 0) && (iVar10 == -0x200000)) {
        if ((param_3 & 0x1fffff) != 0 || ((param_4 & 0xfffff) != 0 || param_3 >> 0x15 != 0)) {
          return 0x7fffffffffffffff;
        }
        return 0x7fffffffffffffff;
      }
      goto LAB_023356dc;
    }
    uVar9 = 1;
    if (uVar5 == 0) {
      uVar9 = 0xffffffe1;
      uVar6 = 0;
      uVar5 = param_1;
      if (-1 < (int)param_1) goto LAB_02335514;
    }
    else {
LAB_02335514:
      uVar4 = 0x20 - LZCOUNT(uVar5);
      param_1 = uVar5 << LZCOUNT(uVar5) | uVar6 >> (uVar4 & 0xff);
      uVar4 = 0x20 - uVar4;
      uVar6 = uVar6 << (uVar4 & 0xff);
      uVar9 = uVar9 - uVar4;
    }
    uVar7 = param_4 << 0xb | param_3 >> 0x15;
    uVar4 = param_3 << 0xb;
    iVar10 = (param_4 >> 0x14) * 0x200000;
    if (iVar10 != 0 && iVar10 != -0x200000) {
      param_3 = uVar7 | 0x80000000;
      uVar8 = param_4 >> 0x14 & 0xfffff7ff;
      goto LAB_023353e0;
    }
  }
  else {
    uVar9 = uVar9 & 0xfffff7ff;
    uVar7 = param_4 << 0xb | param_3 >> 0x15;
    uVar4 = param_3 << 0xb;
    iVar10 = (param_4 >> 0x14) * 0x200000;
    param_1 = uVar5 | 0x80000000;
    if (iVar10 != 0 && iVar10 != -0x200000) {
      param_3 = uVar7 | 0x80000000;
      uVar8 = param_4 >> 0x14 & 0xfffff7ff;
      goto LAB_023353e0;
    }
  }
  param_3 = param_3 << 0xb;
  if ((param_4 >> 0x14 & 0xfffff7ff) != 0) {
    if (param_3 != 0 || (uVar7 & 0x7fffffff) != 0) {
      return 0x7fffffffffffffff;
    }
LAB_02335668:
    return (ulonglong)(uVar13 | DAT_023356ec) << 0x20;
  }
  if (param_3 == 0 && (uVar7 & 0x7fffffff) == 0) {
LAB_023356dc:
    return ((ulonglong)uVar12 & 0x80000000) << 0x20;
  }
  uVar8 = 1;
  uVar4 = param_3;
  if (uVar7 == 0) {
    uVar8 = 0xffffffe1;
    uVar4 = 0;
    uVar7 = param_3;
    if ((int)param_3 < 0) goto LAB_023353e0;
  }
  uVar5 = 0x20 - LZCOUNT(uVar7);
  param_3 = uVar7 << LZCOUNT(uVar7) | uVar4 >> (uVar5 & 0xff);
  uVar5 = 0x20 - uVar5;
  uVar4 = uVar4 << (uVar5 & 0xff);
  uVar8 = uVar8 - uVar5;
LAB_023353e0:
  iVar10 = uVar8 + uVar9;
  lVar2 = (ulonglong)param_3 * (ulonglong)uVar6 + ((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x20);
  uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar1 = (ulonglong)uVar4 * (ulonglong)param_1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar3 = (ulonglong)param_3 * (ulonglong)param_1 +
          (ulonglong)
          CONCAT14(CARRY4(uVar9,uVar5) ||
                   CARRY4(uVar9 + uVar5,(uint)CARRY4((uint)lVar1,(uint)lVar2)),
                   (int)((ulonglong)(lVar2 + lVar1) >> 0x20));
  uVar9 = (uint)lVar3;
  uVar5 = (uint)((ulonglong)lVar3 >> 0x20);
  if ((int)(lVar2 + lVar1) != 0 || (int)((ulonglong)uVar4 * (ulonglong)uVar6) != 0) {
    uVar9 = uVar9 | 1;
  }
  if (-1 < lVar3) {
    iVar10 = iVar10 + -1;
    bVar14 = CARRY4(uVar9,uVar9);
    uVar9 = uVar9 * 2;
    uVar5 = uVar5 * 2 + (uint)bVar14;
  }
  iVar11 = iVar10 + -0x3fe;
  if ((iVar11 < 0) || (iVar11 == 0)) {
    if (iVar11 == -0x34) {
      return CONCAT44(uVar12,(uint)(uVar9 != 0 || (uVar5 & 0x7fffffff) != 0)) & 0x80000000ffffffff;
    }
    if (iVar10 + -0x3ca < 0) {
      return ((ulonglong)uVar12 & 0x80000000) << 0x20;
    }
    uVar12 = iVar10 - 0x3ca;
    uVar4 = uVar9;
    uVar6 = uVar5;
    if (0x1f < (int)uVar12) {
      uVar4 = 0;
      uVar12 = iVar10 - 0x3ea;
      uVar6 = uVar9;
    }
    uVar6 = uVar6 << (uVar12 & 0xff) | uVar4 >> (0x20 - uVar12 & 0xff);
    if (uVar4 << (uVar12 & 0xff) != 0) {
      uVar6 = uVar6 | 1;
    }
    uVar12 = -iVar11 + 0xc;
    uVar4 = uVar5;
    if (0x1f < (int)uVar12) {
      uVar4 = 0;
      uVar12 = -iVar11 - 0x14;
      uVar9 = uVar5;
    }
    uVar9 = uVar9 >> (uVar12 & 0xff) | uVar4 << (0x20 - uVar12 & 0xff);
    uVar13 = uVar13 | uVar4 >> (uVar12 & 0xff);
    if (uVar6 == 0) {
      return CONCAT44(uVar13,uVar9);
    }
    if ((uVar6 & 0x80000000) == 0) {
      return CONCAT44(uVar13,uVar9);
    }
    if ((uVar6 & 0x7fffffff) == 0 && (uVar9 & 1) == 0) {
      return CONCAT44(uVar13,uVar9);
    }
    return CONCAT44(uVar13 + (0xfffffffe < uVar9),uVar9 + 1);
  }
  if (iVar11 * 0x100000 + 0x100000 < 0) {
    return (ulonglong)(uVar13 | DAT_023356ec) << 0x20;
  }
  uVar4 = uVar9 >> 0xb | uVar5 << 0x15;
  uVar6 = uVar13 | (uVar5 & 0x7fffffff) >> 0xb | iVar11 * 0x100000;
  if (uVar9 << 0x15 == 0) {
    return CONCAT44(uVar6,uVar4);
  }
  if ((uVar9 << 0x15 & 0x80000000) == 0) {
    return CONCAT44(uVar6,uVar4);
  }
  if ((uVar9 & 0x3ff) == 0 && (uVar9 >> 0xb & 1) == 0) {
    return CONCAT44(uVar6,uVar4);
  }
  return CONCAT44(uVar6 + (0xfffffffe < uVar4),uVar4 + 1);
}

