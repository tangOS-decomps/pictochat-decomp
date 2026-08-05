// decomp: module=unk_autoload_0 addr=0x0232414c name=FUN_0232414c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x174 (Ghidra's cache says 0x16a - it excludes this function's trailing literal pool), thumb
// triage: noise=23 statements=85
// verify:  python tools/match.py --c <file> --func FUN_0232414c --addr 0x0232414c --size 0x174 --module unk_autoload_0 --version 2.0/sp1


ushort * FUN_0232414c(uint param_1,ushort *param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_r6;
  int unaff_r7;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  FUN_02320978(0x28);
  if ((param_1 & 0x40) == 0) {
    if ((param_1 & 0x80) == 0) {
      if ((param_1 & 0x20) == 0) {
        if ((param_1 & 0x10) != 0) {
          local_24 = 8;
          local_28 = 8;
          local_1c = *(int *)(PTR_DAT_023242b8 + 4) + (*param_2 & 0xff) + (param_2[1] & 0xff);
          local_20 = local_1c + 0x50;
          unaff_r6 = *(int *)(PTR_DAT_023242b8 + 8) +
                     ((uint)(*param_2 >> 8) * 2 + (uint)(param_2[1] >> 8)) / 2;
          unaff_r7 = unaff_r6 + 0x10;
        }
      }
      else {
        local_24 = -8;
        local_28 = 8;
        local_1c = *(int *)(PTR_DAT_023242b8 + 4) + (*param_2 & 0xff);
        local_20 = local_1c + -0x50;
        unaff_r6 = *(int *)(PTR_DAT_023242b8 + 8) +
                   ((uint)(*param_2 >> 8) * 2 + (uint)(param_2[1] >> 8)) / 2;
        unaff_r7 = unaff_r6 + 0x10;
      }
    }
    else {
      local_24 = 8;
      local_28 = 8;
      local_1c = *(int *)(PTR_DAT_023242b8 + 4) + ((*param_2 & 0xff) * 2 + (param_2[1] & 0xff)) / 2;
      unaff_r6 = *(int *)(PTR_DAT_023242b8 + 8) + (uint)(*param_2 >> 8) + (uint)(param_2[1] >> 8);
      local_20 = local_1c + 0x10;
      unaff_r7 = unaff_r6 + 0x50;
    }
  }
  else {
    local_24 = -8;
    local_28 = -8;
    local_1c = *(int *)(PTR_DAT_023242b8 + 4) + ((*param_2 & 0xff) * 2 + (param_2[1] & 0xff)) / 2;
    local_20 = local_1c + -0x10;
    unaff_r6 = *(int *)(PTR_DAT_023242b8 + 8) + (uint)(*param_2 >> 8);
    unaff_r7 = unaff_r6 + -0x50;
  }
  do {
    iVar4 = local_1c;
    if (unaff_r6 == unaff_r7) {
      return param_2;
    }
    for (; iVar4 != local_20; iVar4 = iVar4 + local_24) {
      if (iVar4 - *(int *)(PTR_DAT_023242b8 + 4) < 0) {
        iVar2 = iVar4 + 200;
      }
      else {
        iVar2 = iVar4;
        if (200 < iVar4 - *(int *)(PTR_DAT_023242b8 + 4)) {
          iVar2 = iVar4 + -200;
        }
      }
      if (unaff_r6 - *(int *)(PTR_DAT_023242b8 + 8) < 0) {
        iVar3 = unaff_r6 + 0x6a;
      }
      else {
        iVar3 = unaff_r6;
        if (0x6a < unaff_r6 - *(int *)(PTR_DAT_023242b8 + 8)) {
          iVar3 = unaff_r6 + -0x6a;
        }
      }
      puVar1 = (ushort *)FUN_0232310c(PTR_DAT_023242bc,iVar2,iVar3);
      if ((puVar1 != (ushort *)0x0) && (puVar1 != param_2)) {
        return puVar1;
      }
    }
    unaff_r6 = unaff_r6 + local_28;
  } while( true );
}

