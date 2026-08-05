// decomp: module=unk_autoload_0 addr=0x02333288 name=FUN_02333288
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1ac (Ghidra's cache says 0x1a6 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=122
// verify:  python tools/match.py --c <file> --func FUN_02333288 --addr 0x02333288 --size 0x1ac --module unk_autoload_0 --version 2.0/sp1


char * FUN_02333288(int param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int extraout_r1;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint local_38;
  int local_34;
  int local_2c;
  char local_8;
  
  local_34 = param_6;
  uVar1 = param_3 >> 0x18;
  uVar3 = param_4 >> 8 & 0xff;
  pcVar4 = (char *)(param_2 + -1);
  local_38 = param_3 >> 8 & 0xff;
  iVar7 = 0;
  bVar2 = false;
  *pcVar4 = '\0';
  if (((param_1 == 0) && (param_6 == 0)) && ((uVar1 == 0 || (uVar3 != 0x6f)))) {
    return pcVar4;
  }
  if (uVar3 < 0x6a) {
    if (uVar3 < 0x69) {
      if (uVar3 < 0x59) {
        if (uVar3 != 0x58) goto LAB_02333338;
        goto LAB_02333330;
      }
      if (uVar3 != 100) goto LAB_02333338;
    }
    local_2c = 10;
    if (param_1 < 0) {
      if (param_1 != -0x80000000) {
        param_1 = -param_1;
      }
      bVar2 = true;
    }
  }
  else {
    if (uVar3 < 0x70) {
      if (uVar3 == 0x6f) {
        local_2c = 8;
        local_38 = 0;
      }
      goto LAB_02333338;
    }
    if ((0x78 < uVar3) || (uVar3 < 0x75)) goto LAB_02333338;
    if (uVar3 == 0x75) {
      local_2c = 10;
      local_38 = 0;
      goto LAB_02333338;
    }
    if (uVar3 != 0x78) goto LAB_02333338;
LAB_02333330:
    local_2c = 0x10;
    local_38 = 0;
  }
LAB_02333338:
  do {
    iVar8 = iVar7;
    pcVar5 = pcVar4;
    FUN_02336018(param_1,local_2c);
    param_1 = FUN_02336018(param_1,local_2c);
    cVar6 = (char)extraout_r1;
    if (extraout_r1 < 10) {
      cVar6 = cVar6 + '0';
    }
    else if (uVar3 == 0x78) {
      cVar6 = cVar6 + 'W';
    }
    else {
      cVar6 = cVar6 + '7';
    }
    pcVar4 = pcVar5 + -1;
    iVar7 = iVar8 + 1;
    *pcVar4 = cVar6;
  } while (param_1 != 0);
  if (((local_2c == 8) && (uVar1 != 0)) && (*pcVar4 != '0')) {
    pcVar4 = pcVar5 + -2;
    *pcVar4 = '0';
    iVar7 = iVar8 + 2;
  }
  local_8 = (char)param_3;
  if (local_8 == '\x02') {
    local_34 = param_5;
    if ((bVar2) || (local_38 != 0)) {
      local_34 = param_5 + -1;
    }
    if ((local_2c == 0x10) && (uVar1 != 0)) {
      local_34 = local_34 + -2;
    }
  }
  if (local_34 + (param_2 - (int)pcVar4) <= DAT_02333430) {
    for (; iVar7 < local_34; iVar7 = iVar7 + 1) {
      pcVar4 = pcVar4 + -1;
      *pcVar4 = '0';
    }
    if ((local_2c == 0x10) && (uVar1 != 0)) {
      pcVar4[-1] = (char)(param_4 >> 8);
      pcVar4 = pcVar4 + -2;
      *pcVar4 = '0';
    }
    if (bVar2) {
      pcVar4 = pcVar4 + -1;
      *pcVar4 = '-';
    }
    else if (local_38 == 1) {
      pcVar4 = pcVar4 + -1;
      *pcVar4 = '+';
    }
    else if (local_38 == 2) {
      pcVar4 = pcVar4 + -1;
      *pcVar4 = ' ';
    }
    return pcVar4;
  }
  return (char *)0x0;
}

