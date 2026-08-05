// decomp: module=unk_autoload_0 addr=0x02333434 name=FUN_02333434
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x214 (Ghidra's cache says 0x210 - it excludes this function's trailing literal pool), thumb
// triage: noise=14 statements=144
// verify:  python tools/match.py --c <file> --func FUN_02333434 --addr 0x02333434 --size 0x214 --module unk_autoload_0 --version 2.0/sp1


char * FUN_02333434(int param_1,int param_2,int param_3,uint param_4,undefined4 param_5,int param_6,
                   int param_7)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  undefined4 uVar6;
  bool bVar7;
  longlong lVar8;
  uint local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  char local_4;
  
  lVar8 = CONCAT44(param_2,param_1);
  local_3c = param_7;
  uVar1 = param_4 >> 0x18;
  pcVar3 = (char *)(param_3 + -1);
  local_40 = param_4 >> 8 & 0xff;
  bVar7 = false;
  *pcVar3 = '\0';
  local_34 = 0;
  if (((param_1 == 0 && param_2 == 0) && (param_7 == 0)) &&
     ((uVar1 == 0 || (param_5._1_1_ != 0x6f)))) {
    return pcVar3;
  }
  iVar2 = local_34;
  if (param_5._1_1_ < 0x6a) {
    if (param_5._1_1_ < 0x69) {
      if (param_5._1_1_ < 0x59) {
        lVar8 = CONCAT44(param_2,param_1);
        if (param_5._1_1_ != 0x58) goto LAB_02333510;
        goto LAB_02333506;
      }
      if (param_5._1_1_ != 100) goto LAB_02333510;
    }
    local_30 = 10;
    local_2c = 0;
    lVar8 = CONCAT44(param_2,param_1);
    if (param_2 < 0) {
      if (param_1 != 0 || param_2 != -0x80000000) {
        bVar7 = param_1 != 0;
        param_1 = -param_1;
        param_2 = -(uint)bVar7 - param_2;
      }
      bVar7 = true;
      lVar8 = CONCAT44(param_2,param_1);
    }
  }
  else {
    if (param_5._1_1_ < 0x70) {
      lVar8 = CONCAT44(param_2,param_1);
      if (param_5._1_1_ == 0x6f) {
        local_30 = 8;
        local_2c = 0;
        local_40 = 0;
        lVar8 = CONCAT44(param_2,param_1);
      }
      goto LAB_02333510;
    }
    lVar8 = CONCAT44(param_2,param_1);
    if ((0x78 < param_5._1_1_) || (lVar8 = CONCAT44(param_2,param_1), param_5._1_1_ < 0x75))
    goto LAB_02333510;
    if (param_5._1_1_ == 0x75) {
      local_30 = 10;
      local_2c = 0;
      local_40 = 0;
      lVar8 = CONCAT44(param_2,param_1);
      goto LAB_02333510;
    }
    lVar8 = CONCAT44(param_2,param_1);
    if (param_5._1_1_ != 0x78) goto LAB_02333510;
LAB_02333506:
    local_30 = 0x10;
    local_2c = 0;
    local_40 = 0;
    lVar8 = CONCAT44(param_2,param_1);
  }
LAB_02333510:
  do {
    local_34 = iVar2;
    pcVar4 = pcVar3;
    uVar6 = (undefined4)((ulonglong)lVar8 >> 0x20);
    iVar2 = FUN_02335db0((int)lVar8,uVar6,local_30,local_2c);
    lVar8 = FUN_02335da4((int)lVar8,uVar6,local_30,local_2c);
    cVar5 = (char)iVar2;
    if (iVar2 < 10) {
      cVar5 = cVar5 + '0';
    }
    else if (param_5._1_1_ == 0x78) {
      cVar5 = cVar5 + 'W';
    }
    else {
      cVar5 = cVar5 + '7';
    }
    iVar2 = local_34 + 1;
    pcVar3 = pcVar4 + -1;
    *pcVar3 = cVar5;
  } while (lVar8 != 0);
  if (((local_30 == 8 && local_2c == 0) && (uVar1 != 0)) && (*pcVar3 != '0')) {
    pcVar3 = pcVar4 + -2;
    *pcVar3 = '0';
    iVar2 = local_34 + 2;
  }
  local_34 = iVar2;
  local_4 = (char)param_4;
  if (local_4 == '\x02') {
    local_3c = param_6;
    if ((bVar7) || (local_40 != 0)) {
      local_3c = param_6 + -1;
    }
    if ((local_30 == 0x10 && local_2c == 0) && (uVar1 != 0)) {
      local_3c = local_3c + -2;
    }
  }
  if (local_3c + (param_3 - (int)pcVar3) <= DAT_02333644) {
    for (; local_34 < local_3c; local_34 = local_34 + 1) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '0';
    }
    if ((local_30 == 0x10 && local_2c == 0) && (uVar1 != 0)) {
      pcVar3[-1] = param_5._1_1_;
      pcVar3 = pcVar3 + -2;
      *pcVar3 = '0';
    }
    if (bVar7) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '-';
    }
    else if (local_40 == 1) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = '+';
    }
    else if (local_40 == 2) {
      pcVar3 = pcVar3 + -1;
      *pcVar3 = ' ';
    }
    return pcVar3;
  }
  return (char *)0x0;
}

