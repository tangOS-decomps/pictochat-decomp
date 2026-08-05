// decomp: module=unk_autoload_0 addr=0x02335708 name=FUN_02335708
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3b4 (Ghidra's cache says 0x3b0 - it excludes this function's trailing literal pool), arm
// triage: noise=16 statements=374
// verify:  python tools/match.py --c <file> --func FUN_02335708 --addr 0x02335708 --size 0x3b4 --module unk_autoload_0 --version 2.0/sp1


longlong FUN_02335708(uint param_1,uint param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      uVar9 = param_2 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
      bVar10 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      param_4 = param_4 + uVar9 + (uint)bVar10;
      bVar10 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = param_2 - (uVar9 + bVar10);
    }
    uVar9 = param_2 >> 0x14;
    param_2 = param_2 << 0xb;
    uVar5 = param_1 >> 0x15;
    uVar2 = param_2 | 0x80000000 | uVar5;
    uVar6 = param_1 * 0x800;
    if (uVar9 * 0x200000 == 0 || uVar9 * 0x200000 == -0x200000) {
      uVar7 = 0x80000000;
      if (uVar9 < 0x800) {
        uVar7 = 0;
      }
      if ((uVar9 & 0xfffff7ff) != 0) {
        if (uVar6 != 0 || ((param_2 & 0x7fffffff) != 0 || uVar5 != 0)) {
          return 0x7fffffffffffffff;
        }
        iVar8 = (param_4 >> 0x14) * 0x200000;
        if ((iVar8 != 0) && (iVar8 == -0x200000)) {
          if ((param_3 & 0x1fffff) != 0 || ((param_4 & 0xfffff) != 0 || param_3 >> 0x15 != 0)) {
            return 0x7fffffffffffffff;
          }
          return 0x7fffffffffffffff;
        }
        goto LAB_02335a70;
      }
      if (uVar6 == 0 && ((param_2 & 0x7fffffff) == 0 && uVar5 == 0)) {
        iVar8 = (param_4 >> 0x14) * 0x200000;
        if (iVar8 == 0) {
          if (param_3 << 0xb == 0 && ((param_4 << 0xb & 0x7fffffff) == 0 && param_3 >> 0x15 == 0)) {
            return 0;
          }
        }
        else if (iVar8 == -0x200000) {
          if (param_3 << 0xb != 0 || ((param_4 << 0xb & 0x7fffffff) != 0 || param_3 >> 0x15 != 0)) {
            return 0x7fffffffffffffff;
          }
          goto LAB_02335a70;
        }
        return CONCAT44(param_4,param_3);
      }
      uVar9 = 1;
      uVar2 = param_2 & 0x7fffffff | uVar5;
      uVar4 = param_4 << 0xb | param_3 >> 0x15;
      iVar8 = (param_4 >> 0x14) * 0x200000;
      uVar5 = param_4 >> 0x14 & 0x7ff | uVar7 >> 0x14;
      if (iVar8 == 0 || iVar8 == -0x200000) goto LAB_02335984;
      uVar4 = uVar4 | 0x80000000;
      uVar9 = uVar7 >> 0x14 | 1;
    }
    else {
      uVar5 = param_4 >> 0x14;
      uVar4 = param_4 << 0xb | 0x80000000 | param_3 >> 0x15;
      if ((uVar5 & 0x7ff) == 0) {
LAB_02335984:
        if (uVar5 < 0x800) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x80000000;
        }
        uVar9 = uVar9 & 0xfffff7ff;
        if ((uVar5 & 0xfffff7ff) != 0) {
          if (param_3 << 0xb != 0 || (uVar4 & 0x7fffffff) != 0) {
            return 0x7fffffffffffffff;
          }
LAB_02335a70:
          return (ulonglong)(uVar7 | DAT_02335ab8) << 0x20;
        }
        if (param_3 << 0xb == 0 && (uVar4 & 0x7fffffff) == 0) {
          if (-1 < (int)uVar2) {
            uVar9 = uVar9 - 1;
          }
          return CONCAT44(uVar7 | (uVar2 & 0x7fffffff) >> 0xb | uVar9 << 0x14,
                          param_1 & 0x1fffff | uVar2 << 0x15);
        }
        uVar4 = uVar4 & 0x7fffffff;
        uVar9 = uVar9 | uVar7 >> 0x14;
        uVar5 = uVar7 >> 0x14 | 1;
      }
    }
    uVar7 = param_3 * 0x800;
    uVar5 = uVar9 - uVar5;
    if (uVar5 == 0) {
      uVar5 = uVar6 + param_3 * -0x800;
      uVar2 = uVar2 - (uVar4 + (uVar6 < uVar7));
      if (uVar2 == 0 && uVar5 == 0) {
        return 0;
      }
      uVar6 = (uVar9 & 0x800) << 0x14;
      uVar9 = uVar9 & 0xfffff7ff;
      if ((int)uVar2 < 0) {
        if (-1 < (int)uVar2) {
          uVar9 = uVar9 - 1;
        }
        goto LAB_023358a8;
      }
      uVar7 = uVar5;
      if (uVar2 == 0) {
        uVar9 = uVar9 - 0x20;
        uVar7 = 0;
        uVar2 = uVar5;
        if (-1 < (int)uVar5) goto LAB_02335850;
      }
      else {
LAB_02335850:
        uVar5 = 0x20 - LZCOUNT(uVar2);
        uVar2 = uVar2 << LZCOUNT(uVar2) | uVar7 >> (uVar5 & 0xff);
        uVar5 = 0x20 - uVar5;
        uVar7 = uVar7 << (uVar5 & 0xff);
        uVar9 = uVar9 - uVar5;
      }
      uVar5 = uVar7;
      if ((int)uVar9 < 1) {
        uVar4 = -uVar9 + 0xc;
        uVar5 = uVar2;
        if (0x1f < (int)uVar4) {
          uVar5 = 0;
          uVar4 = -uVar9 - 0x14;
          uVar7 = uVar2;
        }
        return CONCAT44(uVar6 | uVar5 >> (uVar4 & 0xff),
                        uVar7 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff));
      }
LAB_023358a8:
      return CONCAT44(uVar6 | (uVar2 & 0x7fffffff) >> 0xb | uVar9 << 0x14,
                      uVar5 >> 0xb | uVar2 << 0x15);
    }
    if ((int)uVar5 < 0x21) {
      uVar3 = uVar7 >> (uVar5 & 0xff) | uVar4 << (0x20 - uVar5 & 0xff);
      if (uVar7 << (0x20 - uVar5 & 0xff) != 0) {
        uVar3 = uVar3 | 1;
      }
      uVar5 = (uVar4 >> (uVar5 & 0xff)) + (uint)(uVar6 < uVar3);
    }
    else {
      if (0x37 < (int)uVar5) {
        uVar5 = 0x3f;
      }
      uVar3 = uVar4 >> (uVar5 - 0x20 & 0xff);
      if (uVar7 != 0 || uVar4 << (0x20 - (uVar5 - 0x20) & 0xff) != 0) {
        uVar3 = uVar3 | 1;
      }
      uVar5 = (uint)(uVar6 < uVar3);
    }
    uVar2 = uVar2 - uVar5;
    uVar6 = uVar6 - uVar3;
    if ((int)uVar2 < 0) goto LAB_023357d4;
    uVar7 = uVar9 & 0xfffff7ff;
    uVar5 = uVar6;
    if (uVar2 == 0) {
      uVar7 = uVar7 - 0x20;
      uVar5 = 0;
      uVar2 = uVar6;
      if (-1 < (int)uVar6) goto LAB_023358e8;
    }
    else {
LAB_023358e8:
      uVar6 = 0x20 - LZCOUNT(uVar2);
      uVar2 = uVar2 << LZCOUNT(uVar2) | uVar5 >> (uVar6 & 0xff);
      uVar6 = 0x20 - uVar6;
      uVar7 = uVar7 - uVar6;
      uVar5 = uVar5 << (uVar6 & 0xff);
    }
    uVar6 = uVar5;
    if ((int)uVar7 < 1) {
      uVar4 = -uVar7 + 0xc;
      uVar5 = uVar2;
      if (0x1f < (int)uVar4) {
        uVar5 = 0;
        uVar4 = -uVar7 - 0x14;
        uVar6 = uVar2;
      }
      return CONCAT44((uVar9 & 0x800) << 0x14 | uVar5 >> (uVar4 & 0xff),
                      uVar6 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff));
    }
    uVar9 = uVar7 | uVar9 & 0x800;
LAB_023357d4:
    uVar5 = uVar6 >> 0xb | uVar2 << 0x15;
    uVar9 = (uVar2 & 0x7fffffff) >> 0xb | uVar9 << 0x14;
    if ((uVar6 & 0x400) == 0) {
      return CONCAT44(uVar9,uVar5);
    }
    if ((uVar6 & 0x3ff) != 0 || (uVar6 >> 0xb & 1) != 0) {
      return CONCAT44(uVar9 + (0xfffffffe < uVar5),uVar5 + 1);
    }
    return CONCAT44(uVar9,uVar5);
  }
  param_4 = param_4 ^ 0x80000000;
  uVar6 = param_1 - param_3;
  iVar8 = param_2 - (param_4 + (param_3 > param_1));
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar10 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar8 + (uint)bVar10;
    bVar10 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = param_2 - (iVar8 + (uint)bVar10);
  }
  uVar9 = param_2 >> 0x14;
  param_2 = param_2 << 0xb;
  uVar5 = param_1 >> 0x15;
  uVar2 = param_2 | 0x80000000 | uVar5;
  uVar6 = param_1 * 0x800;
  if (uVar9 * 0x200000 == 0 || uVar9 * 0x200000 == -0x200000) {
    uVar7 = 0x80000000;
    if (uVar9 < 0x800) {
      uVar7 = 0;
    }
    if ((uVar9 & 0xfffff7ff) != 0) {
      if (uVar6 != 0 || ((param_2 & 0x7fffffff) != 0 || uVar5 != 0)) {
        return 0x7fffffffffffffff;
      }
      iVar8 = (param_4 >> 0x14) * 0x200000;
      if (((iVar8 != 0) && (iVar8 == -0x200000)) &&
         ((param_3 & 0x1fffff) != 0 || ((param_4 & 0xfffff) != 0 || param_3 >> 0x15 != 0))) {
        return 0x7fffffffffffffff;
      }
      goto LAB_023352a4;
    }
    if (uVar6 == 0 && ((param_2 & 0x7fffffff) == 0 && uVar5 == 0)) {
      iVar8 = (param_4 >> 0x14) * 0x200000;
      if ((iVar8 != 0) && (iVar8 == -0x200000)) {
        if ((param_3 & 0x1fffff) != 0 || ((param_4 & 0xfffff) != 0 || param_3 >> 0x15 != 0)) {
          return 0x7fffffffffffffff;
        }
        goto LAB_023352a4;
      }
      goto LAB_02335270;
    }
    uVar9 = 1;
    uVar2 = param_2 & 0x7fffffff | uVar5;
    uVar5 = param_4 >> 0x14;
    param_4 = param_4 << 0xb | param_3 >> 0x15;
    iVar8 = uVar5 * 0x200000;
    uVar5 = uVar5 & 0x7ff | uVar7 >> 0x14;
    if (iVar8 == 0 || iVar8 == -0x200000) goto LAB_02335158;
    param_4 = param_4 | 0x80000000;
    uVar9 = uVar7 >> 0x14 | 1;
  }
  else {
    uVar5 = param_4 >> 0x14;
    param_4 = param_4 << 0xb | 0x80000000 | param_3 >> 0x15;
    if ((uVar5 & 0x7ff) == 0) {
LAB_02335158:
      uVar4 = param_3 * 0x800;
      if (uVar5 < 0x800) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0x80000000;
      }
      uVar9 = uVar9 & 0xfffff7ff;
      if ((uVar5 & 0xfffff7ff) != 0) {
        if (uVar4 != 0 || (param_4 & 0x7fffffff) != 0) {
          return 0x7fffffffffffffff;
        }
LAB_023352a4:
        return (ulonglong)(uVar7 | DAT_023352fc) << 0x20;
      }
      if (uVar4 == 0 && (param_4 & 0x7fffffff) == 0) {
        if (-1 < (int)uVar2) {
          uVar9 = uVar9 - 1;
        }
        return CONCAT44(uVar7 | (uVar2 & 0x7fffffff) >> 0xb | uVar9 << 0x14,
                        param_1 & 0x1fffff | uVar2 << 0x15);
      }
      param_4 = param_4 & 0x7fffffff;
      if (-1 < (int)uVar2) {
        uVar5 = uVar6 + uVar4;
        bVar10 = CARRY4(uVar2 + param_4,(uint)CARRY4(uVar6,uVar4));
        uVar6 = uVar2 + param_4 + (uint)CARRY4(uVar6,uVar4);
        if (CARRY4(uVar2,param_4) || bVar10) {
          uVar9 = uVar9 + 1;
          bVar1 = (byte)uVar6;
          uVar6 = (uint)(CARRY4(uVar2,param_4) || bVar10) << 0x1f | uVar6 >> 1;
          uVar5 = (uint)(bVar1 & 1) << 0x1f | uVar5 >> 1;
        }
        if (-1 < (int)uVar6) {
          uVar9 = uVar9 - 1;
        }
        uVar2 = uVar5 >> 0xb | uVar6 << 0x15;
        uVar6 = uVar7 | (uVar6 & 0x7fffffff) >> 0xb | uVar9 << 0x14;
        if (uVar5 << 0x15 == 0) {
          return CONCAT44(uVar6,uVar2);
        }
        if (uVar5 << 0x15 == 0) {
          return CONCAT44(uVar6,uVar2);
        }
        param_3 = uVar5 >> 0xb & 1;
        if (param_3 == 0) {
          return CONCAT44(uVar6,uVar2);
        }
LAB_02335270:
        return CONCAT44(param_4,param_3);
      }
      uVar9 = uVar9 | uVar7 >> 0x14;
      uVar5 = uVar7 >> 0x14 | 1;
    }
  }
  param_3 = param_3 << 0xb;
  uVar5 = uVar9 - uVar5;
  if (uVar5 == 0) {
LAB_023350a4:
    uVar7 = uVar6 + param_3;
    uVar5 = uVar2 + param_4 + (uint)CARRY4(uVar6,param_3);
    if (!CARRY4(uVar2,param_4) && !CARRY4(uVar2 + param_4,(uint)CARRY4(uVar6,param_3)))
    goto LAB_023350cc;
  }
  else {
    if ((int)uVar5 < 0x21) {
      iVar8 = param_3 << (0x20 - uVar5 & 0xff);
      param_3 = param_3 >> (uVar5 & 0xff) | param_4 << (0x20 - uVar5 & 0xff);
      param_4 = param_4 >> (uVar5 & 0xff);
      if (iVar8 != 0) {
        param_3 = param_3 | 1;
      }
      goto LAB_023350a4;
    }
    if (0x37 < (int)uVar5) {
      uVar5 = 0x3f;
    }
    uVar4 = param_4 >> (uVar5 - 0x20 & 0xff);
    if (param_3 != 0 || param_4 << (0x20 - (uVar5 - 0x20) & 0xff) != 0) {
      uVar4 = uVar4 | 1;
    }
    uVar7 = uVar6 + uVar4;
    uVar5 = uVar2 + CARRY4(uVar6,uVar4);
    if (!CARRY4(uVar2,(uint)CARRY4(uVar6,uVar4))) goto LAB_023350cc;
  }
  uVar9 = uVar9 + 1;
  bVar1 = (byte)uVar5;
  uVar5 = uVar5 >> 1;
  uVar7 = uVar7 & 1 | (uint)(bVar1 & 1) << 0x1f | uVar7 >> 1;
  if ((uVar9 & 0x7ff) == 0x7ff) {
    if (uVar9 < 0x800) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x80000000;
    }
    return (ulonglong)(uVar6 | DAT_023352fc) << 0x20;
  }
LAB_023350cc:
  uVar6 = uVar7 >> 0xb | uVar5 << 0x15;
  uVar9 = (uVar5 & 0x7fffffff) >> 0xb | uVar9 << 0x14;
  if ((uVar7 & 0x400) == 0) {
    return CONCAT44(uVar9,uVar6);
  }
  if ((uVar7 & 0x3ff) != 0 || (uVar7 >> 0xb & 1) != 0) {
    return CONCAT44(uVar9 + (0xfffffffe < uVar6),uVar6 + 1);
  }
  return CONCAT44(uVar9,uVar6);
}

