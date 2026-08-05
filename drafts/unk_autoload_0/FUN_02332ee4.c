// decomp: module=unk_autoload_0 addr=0x02332ee4 name=FUN_02332ee4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x362, thumb
// triage: noise=53 statements=294
// verify:  python tools/match.py --c <file> --func FUN_02332ee4 --addr 0x02332ee4 --size 0x362 --module unk_autoload_0 --version 2.0/sp1


char * FUN_02332ee4(int param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  ushort uVar5;
  uint *puVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  
  uVar2 = local_1c;
  local_20 = 1;
  local_1c = local_1c & 0xffffff00;
  uVar3 = local_1c;
  local_18 = 0;
  local_14 = 0;
  iVar7 = (int)*(char *)(param_1 + 1);
  pcVar8 = (char *)(param_1 + 1);
  local_1c._2_2_ = SUB42(uVar2,2);
  if (iVar7 == 0x25) {
    local_1c = (uint)CONCAT21(local_1c._2_2_,*(char *)(param_1 + 1)) << 8;
    *param_3 = 1;
    param_3[1] = local_1c;
    param_3[2] = 0;
    param_3[3] = 0;
    return (char *)(param_1 + 2);
  }
  do {
    bVar1 = true;
    if (iVar7 < 0x2c) {
      if (iVar7 < 0x2b) {
        if ((0x23 < iVar7) || (iVar7 < 0x20)) goto LAB_02332f6e;
        if (iVar7 == 0x20) {
          if (local_20._1_1_ != '\x01') {
            local_20._0_2_ = CONCAT11(2,(char)local_20);
          }
        }
        else {
          if (iVar7 != 0x23) goto LAB_02332f6e;
          local_20 = CONCAT13(1,(undefined3)local_20);
        }
      }
      else {
        local_20._0_2_ = CONCAT11(1,(char)local_20);
      }
    }
    else if ((iVar7 < 0x31) && (0x2c < iVar7)) {
      if (iVar7 == 0x2d) {
        local_20 = (uint)local_20._1_3_ << 8;
      }
      else {
        if (iVar7 != 0x30) goto LAB_02332f6e;
        if ((char)local_20 != '\0') {
          local_20 = CONCAT31(local_20._1_3_,2);
        }
      }
    }
    else {
LAB_02332f6e:
      bVar1 = false;
    }
    if (!bVar1) break;
    pcVar8 = pcVar8 + 1;
    iVar7 = (int)*pcVar8;
  } while( true );
  if (iVar7 == 0x2a) {
    puVar6 = (uint *)*param_2;
    *param_2 = (int)(puVar6 + 1);
    local_18 = *puVar6;
    if ((int)local_18 < 0) {
      local_20 = local_20 & 0xffffff00;
      local_18 = -local_18;
    }
    pcVar8 = pcVar8 + 1;
    iVar7 = (int)*pcVar8;
  }
  else {
    while( true ) {
      if ((iVar7 < 0) || (0x7f < iVar7)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(ushort *)(DAT_02333234 + iVar7 * 2) & 8;
      }
      if (uVar5 == 0) break;
      local_18 = iVar7 + -0x30 + local_18 * 10;
      pcVar8 = pcVar8 + 1;
      iVar7 = (int)*pcVar8;
    }
  }
  if (DAT_02333238 < (int)local_18) {
    local_1c = CONCAT22(local_1c._2_2_,0xff00);
    *param_3 = local_20;
    param_3[1] = local_1c;
    param_3[2] = local_18;
    param_3[3] = 0;
    return pcVar8 + 1;
  }
  pcVar9 = pcVar8;
  if (iVar7 == 0x2e) {
    pcVar9 = pcVar8 + 1;
    local_20._0_3_ = CONCAT12(1,(ushort)local_20);
    iVar7 = (int)*pcVar9;
    if (iVar7 == 0x2a) {
      puVar6 = (uint *)*param_2;
      *param_2 = (int)(puVar6 + 1);
      local_14 = *puVar6;
      if ((int)local_14 < 0) {
        local_20 = CONCAT13(local_20._3_1_,(uint3)(ushort)local_20);
      }
      pcVar9 = pcVar8 + 2;
      iVar7 = (int)*pcVar9;
    }
    else {
      while( true ) {
        if ((iVar7 < 0) || (0x7f < iVar7)) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(ushort *)(DAT_02333234 + iVar7 * 2) & 8;
        }
        if (uVar5 == 0) break;
        local_14 = iVar7 + -0x30 + local_14 * 10;
        pcVar9 = pcVar9 + 1;
        iVar7 = (int)*pcVar9;
      }
    }
  }
  bVar1 = true;
  local_1c._1_3_ = SUB43(uVar2,1);
  if (iVar7 < 0x6d) {
    if (iVar7 < 0x68) {
      if (iVar7 != 0x4c) goto LAB_023330d0;
      local_1c = CONCAT31(local_1c._1_3_,9);
    }
    else if (iVar7 == 0x68) {
      local_1c = CONCAT31(local_1c._1_3_,2);
      if (pcVar9[1] == 'h') {
        local_1c = CONCAT31(local_1c._1_3_,1);
        pcVar9 = pcVar9 + 1;
        iVar7 = (int)*pcVar9;
      }
    }
    else if (iVar7 == 0x6a) {
      local_1c = CONCAT31(local_1c._1_3_,6);
    }
    else {
      if (iVar7 != 0x6c) goto LAB_023330d0;
      local_1c = CONCAT31(local_1c._1_3_,3);
      if (pcVar9[1] == 'l') {
        local_1c = CONCAT31(local_1c._1_3_,4);
        pcVar9 = pcVar9 + 1;
        iVar7 = (int)*pcVar9;
      }
    }
  }
  else if (iVar7 < 0x75) {
    if (iVar7 == 0x74) {
      local_1c = CONCAT31(local_1c._1_3_,8);
    }
    else {
LAB_023330d0:
      bVar1 = false;
      local_1c = uVar3;
    }
  }
  else {
    if (iVar7 != 0x7a) goto LAB_023330d0;
    local_1c = CONCAT31(local_1c._1_3_,7);
  }
  if (bVar1) {
    pcVar9 = pcVar9 + 1;
    iVar7 = (int)*pcVar9;
  }
  uVar4 = local_1c._2_2_;
  local_1c._0_2_ = CONCAT11((char)iVar7,(char)local_1c);
  if (iVar7 < 0x62) {
    if (0x60 < iVar7) {
      if (local_20._2_1_ == '\0') {
        local_14 = 0xd;
      }
      if ((((char)local_1c == '\x02') || ((char)local_1c == '\x06')) ||
         (((char)local_1c == '\a' ||
          ((((char)local_1c == '\b' || ((char)local_1c == '\x04')) || ((char)local_1c == '\x01')))))
         ) {
        local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
      }
      goto LAB_02333276;
    }
    if (iVar7 < 0x48) {
      if (-1 < iVar7 + -0x41) {
                    /* WARNING: Could not recover jumptable at 0x023330fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pcVar8 = (char *)(*(code *)(*(short *)(&DAT_023330fc + (iVar7 + -0x41) * 2) + 0x23330fe))();
        return pcVar8;
      }
    }
    else if (iVar7 == 0x58) goto switchD_0233312c_caseD_64;
  }
  else {
    if (99 < iVar7) {
      switch(iVar7) {
      case 100:
      case 0x69:
      case 0x6f:
      case 0x75:
      case 0x78:
switchD_0233312c_caseD_64:
        if ((char)local_1c == '\t') {
          local_1c = CONCAT22(uVar4,0xff09);
        }
        else if (local_20._2_1_ == '\0') {
          local_14 = 1;
        }
        else if ((char)local_20 == '\x02') {
          local_20 = CONCAT31(local_20._1_3_,1);
        }
        break;
      case 0x66:
        if (((((char)local_1c == '\x02') || ((char)local_1c == '\x06')) || ((char)local_1c == '\a'))
           || (((char)local_1c == '\b' || ((char)local_1c == '\x04')))) {
          local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
          local_1c = CONCAT22(uVar4,(undefined2)local_1c);
        }
        else if (local_20._2_1_ == '\0') {
          local_14 = 6;
        }
        break;
      case 0x67:
        if (local_14 == 0) {
          local_14 = 1;
        }
      case 0x65:
        if ((((char)local_1c == '\x02') || ((char)local_1c == '\x06')) ||
           (((char)local_1c == '\a' ||
            ((((char)local_1c == '\b' || ((char)local_1c == '\x04')) || ((char)local_1c == '\x01')))
            ))) {
          local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
          local_1c = CONCAT22(uVar4,(undefined2)local_1c);
        }
        else if (local_20._2_1_ == '\0') {
          local_14 = 6;
        }
        break;
      default:
        goto switchD_0233312c_caseD_68;
      case 0x6e:
        if ((char)local_1c == '\t') {
          local_1c = CONCAT22(uVar4,0xff09);
        }
        break;
      case 0x70:
        local_1c = CONCAT22(uVar4,0x7800);
        local_20 = CONCAT13(1,(undefined3)local_20);
        local_1c = CONCAT31(local_1c._1_3_,3);
        local_14 = 8;
        break;
      case 0x73:
        if ((char)local_1c == '\x03') {
          local_1c = CONCAT31(local_1c._1_3_,5);
        }
        else if ((char)local_1c != '\0') {
          local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
          local_1c = CONCAT22(uVar4,(undefined2)local_1c);
        }
      }
      goto LAB_02333276;
    }
    if (iVar7 == 99) {
      if ((char)local_1c == '\x03') {
        local_1c = CONCAT31(local_1c._1_3_,5);
      }
      else if ((local_20._2_1_ != '\0') || ((char)local_1c != '\0')) {
        local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
        local_1c = CONCAT22(uVar4,(undefined2)local_1c);
      }
      goto LAB_02333276;
    }
  }
switchD_0233312c_caseD_68:
  local_1c._0_2_ = CONCAT11(0xff,(char)local_1c);
  local_1c = CONCAT22(uVar4,(undefined2)local_1c);
LAB_02333276:
  *param_3 = local_20;
  param_3[1] = local_1c;
  param_3[2] = local_18;
  param_3[3] = local_14;
  return pcVar9 + 1;
}

