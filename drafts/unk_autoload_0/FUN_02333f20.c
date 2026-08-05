// decomp: module=unk_autoload_0 addr=0x02333f20 name=FUN_02333f20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5e0 (Ghidra's cache says 0x594 - it excludes this function's trailing literal pool), thumb
// triage: noise=35 statements=355
// verify:  python tools/match.py --c <file> --func FUN_02333f20 --addr 0x02333f20 --size 0x5e0 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Type propagation algorithm not settling */

int FUN_02333f20(code *param_1,undefined4 param_2,char *param_3,uint *param_4)

{
  char cVar1;
  byte bVar2;
  char *s;
  int iVar3;
  int iVar4;
  byte *s_00;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  undefined1 *puVar8;
  uint local_260;
  uint local_25c;
  undefined1 *local_258;
  uint local_250;
  uint local_24c;
  uint local_248;
  uint local_244;
  uint local_240;
  int local_23c;
  undefined1 local_238;
  char local_237 [3];
  undefined4 local_234;
  uint local_230;
  int local_22c;
  undefined1 *local_228;
  byte local_224 [511];
  undefined1 uStack_25;
  uint *local_4;
  
  local_237[0] = ' ';
  local_23c = 0;
  cVar1 = *param_3;
  local_4 = param_4;
  do {
    if (cVar1 == '\0') {
      return local_23c;
    }
    s = (char *)FUN_023345d0(param_3,0x25);
    if (s == (char *)0x0) {
      iVar3 = FUN_02334584(param_3);
      if (iVar3 == 0) {
        return local_23c + iVar3;
      }
      iVar4 = (*param_1)(param_2,param_3);
      if (iVar4 != 0) {
        return local_23c + iVar3;
      }
      return -1;
    }
    local_23c = local_23c + ((int)s - (int)param_3);
    if (((int)s - (int)param_3 != 0) && (iVar3 = (*param_1)(param_2,param_3), iVar3 == 0)) {
      return -1;
    }
    param_3 = (char *)FUN_02332ee4(s,&local_4,&local_234);
    puVar6 = local_4;
    uVar5 = local_230 >> 8 & 0xff;
    if (uVar5 < 0x62) {
      if (uVar5 < 0x61) {
        if (uVar5 < 0x48) {
          switch(uVar5) {
          case 0x41:
            goto switchD_02333fd2_caseD_41;
          case 0x42:
          case 0x43:
          case 0x44:
            goto switchD_02333fd2_caseD_42;
          case 0x45:
          case 0x46:
          case 0x47:
            goto switchD_02333fd2_caseD_45;
          default:
            if (uVar5 != 0x25) goto switchD_02333fd2_caseD_42;
            local_224[0] = 0x25;
            s_00 = local_224;
            local_258 = (undefined1 *)0x1;
            goto LAB_023343fe;
          }
        }
        if (uVar5 != 0x58) goto switchD_02333fd2_caseD_42;
        goto switchD_02334006_caseD_6f;
      }
switchD_02333fd2_caseD_41:
      if ((char)local_230 == '\t') {
        local_260 = *local_4;
        local_25c = local_4[1];
      }
      else {
        local_260 = *local_4;
        local_25c = local_4[1];
      }
      local_4 = local_4 + 2;
      s_00 = (byte *)FUN_02333648(local_260,local_25c,&stack0xffffffdc,local_234,local_230,local_22c
                                  ,local_228);
      if (s_00 == (byte *)0x0) goto switchD_02333fd2_caseD_42;
      local_258 = &uStack_25 + -(int)s_00;
      goto LAB_023343fe;
    }
    if (0x75 < uVar5) {
      if ((0x78 < uVar5) || (uVar5 != 0x78)) goto switchD_02333fd2_caseD_42;
switchD_02334006_caseD_6f:
      uVar5 = local_230 & 0xff;
      if (uVar5 == 3) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else if (uVar5 == 4) {
        local_248 = *local_4;
        local_244 = local_4[1];
        local_4 = local_4 + 2;
      }
      else if (uVar5 == 6) {
        local_248 = *local_4;
        local_244 = local_4[1];
        local_4 = local_4 + 2;
      }
      else if (uVar5 == 7) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else if (uVar5 == 8) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      if (uVar5 == 2) {
        local_240 = local_240 & 0xffff;
      }
      if (uVar5 == 1) {
        local_240 = local_240 & 0xff;
      }
      if ((uVar5 == 4) || (uVar5 == 6)) {
        s_00 = (byte *)FUN_02333434(local_248,local_244,&stack0xffffffdc,local_234,local_230,
                                    local_22c,local_228);
      }
      else {
        s_00 = (byte *)FUN_02333288(local_240,&stack0xffffffdc,local_234,local_230,local_22c,
                                    local_228);
      }
      if (s_00 == (byte *)0x0) {
switchD_02333fd2_caseD_42:
        iVar3 = FUN_02334584(s);
        if ((iVar3 != 0) && (iVar4 = (*param_1)(param_2,s,iVar3), iVar4 == 0)) {
          return -1;
        }
        return local_23c + iVar3;
      }
      local_258 = &uStack_25 + -(int)s_00;
      goto LAB_023343fe;
    }
    switch(uVar5) {
    case 100:
    case 0x69:
      uVar5 = local_230 & 0xff;
      if (uVar5 == 3) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else if (uVar5 == 4) {
        local_248 = *local_4;
        local_244 = local_4[1];
        local_4 = local_4 + 2;
      }
      else if (uVar5 == 6) {
        local_248 = *local_4;
        local_244 = local_4[1];
        local_4 = local_4 + 2;
      }
      else if (uVar5 == 7) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else if (uVar5 == 8) {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      else {
        local_240 = *local_4;
        local_4 = local_4 + 1;
      }
      if (uVar5 == 2) {
        local_240 = (uint)(short)local_240;
      }
      if (uVar5 == 1) {
        local_240 = (uint)(char)local_240;
      }
      if ((uVar5 == 4) || (uVar5 == 6)) {
        s_00 = (byte *)FUN_02333434(local_248,local_244,&stack0xffffffdc,local_234,local_230,
                                    local_22c,local_228);
      }
      else {
        s_00 = (byte *)FUN_02333288(local_240,&stack0xffffffdc,local_234,local_230,local_22c,
                                    local_228);
      }
      if (s_00 == (byte *)0x0) goto switchD_02333fd2_caseD_42;
      local_258 = &uStack_25 + -(int)s_00;
      break;
    case 0x65:
    case 0x66:
    case 0x67:
switchD_02333fd2_caseD_45:
      if ((char)local_230 == '\t') {
        local_250 = *local_4;
        local_24c = local_4[1];
      }
      else {
        local_250 = *local_4;
        local_24c = local_4[1];
      }
      local_4 = local_4 + 2;
      s_00 = (byte *)FUN_02333a38(local_250,local_24c,&stack0xffffffdc,local_234,local_230,local_22c
                                  ,local_228);
      if (s_00 == (byte *)0x0) goto switchD_02333fd2_caseD_42;
      local_258 = &uStack_25 + -(int)s_00;
      break;
    case 0x68:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x74:
      goto switchD_02333fd2_caseD_42;
    case 0x6e:
      puVar6 = local_4 + 1;
      piVar7 = (int *)*local_4;
      local_4 = puVar6;
      if ((local_230 & 0xff) < 9) {
        switch(local_230 & 0xff) {
        case 0:
          *piVar7 = local_23c;
          break;
        case 2:
          *(short *)piVar7 = (short)local_23c;
          break;
        case 3:
          *piVar7 = local_23c;
          break;
        case 4:
          *piVar7 = local_23c;
          piVar7[1] = local_23c >> 0x1f;
          break;
        case 6:
          *piVar7 = local_23c;
          piVar7[1] = local_23c >> 0x1f;
          break;
        case 7:
          *piVar7 = local_23c;
          break;
        case 8:
          *piVar7 = local_23c;
        }
      }
      goto switchD_0233435e_caseD_1;
    case 0x6f:
    case 0x75:
      goto switchD_02334006_caseD_6f;
    case 0x73:
      if ((char)local_230 == '\x05') {
        uVar5 = *local_4;
        if (*local_4 == 0) {
          uVar5 = DAT_023344f8;
        }
        local_4 = local_4 + 1;
        iVar3 = FUN_02332da4(local_224,uVar5,0x200);
        if (iVar3 < 0) goto switchD_02333fd2_caseD_42;
        s_00 = local_224;
      }
      else {
        local_4 = local_4 + 1;
        s_00 = (byte *)*puVar6;
      }
      if (s_00 == (byte *)0x0) {
        s_00 = DAT_023344fc;
      }
      if (local_234._3_1_ == '\0') {
        if (local_234._2_1_ == '\0') {
          local_258 = (undefined1 *)FUN_02334584((char *)s_00);
        }
        else {
          local_258 = local_228;
          iVar3 = FUN_02332e1c(s_00,0,local_228);
          if (iVar3 != 0) {
            local_258 = (undefined1 *)(iVar3 - (int)s_00);
          }
        }
      }
      else {
        local_258 = (undefined1 *)(uint)*s_00;
        s_00 = s_00 + 1;
        if ((local_234._2_1_ != '\0') && ((int)local_228 < (int)local_258)) {
          local_258 = local_228;
        }
      }
      break;
    default:
      if (uVar5 != 99) goto switchD_02333fd2_caseD_42;
      s_00 = local_224;
      local_4 = local_4 + 1;
      local_224[0] = (byte)*puVar6;
      local_258 = (undefined1 *)0x1;
    }
LAB_023343fe:
    puVar8 = local_258;
    if ((local_234 & 0xff) != 0) {
      if ((local_234 & 0xff) == 2) {
        local_237[0] = '0';
      }
      else {
        local_237[0] = ' ';
      }
      bVar2 = *s_00;
      if ((((bVar2 == 0x2b) || (bVar2 == 0x2d)) || (bVar2 == 0x20)) && (local_237[0] == '0')) {
        iVar3 = (*param_1)(param_2,s_00);
        if (iVar3 == 0) {
          return -1;
        }
        s_00 = s_00 + 1;
        local_258 = local_258 + -1;
      }
      if ((int)puVar8 < local_22c) {
        do {
          iVar3 = (*param_1)(param_2,local_237,1);
          if (iVar3 == 0) {
            return -1;
          }
          puVar8 = puVar8 + 1;
        } while ((int)puVar8 < local_22c);
      }
    }
    if ((local_258 != (undefined1 *)0x0) && (iVar3 = (*param_1)(param_2,s_00,local_258), iVar3 == 0)
       ) {
      return -1;
    }
    if (((char)local_234 == '\0') && ((int)puVar8 < local_22c)) {
      do {
        local_238 = 0x20;
        iVar3 = (*param_1)(param_2,&local_238,1);
        if (iVar3 == 0) {
          return -1;
        }
        puVar8 = puVar8 + 1;
      } while ((int)puVar8 < local_22c);
    }
    local_23c = local_23c + (int)puVar8;
switchD_0233435e_caseD_1:
    cVar1 = *param_3;
  } while( true );
}

