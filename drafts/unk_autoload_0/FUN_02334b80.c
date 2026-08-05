// decomp: module=unk_autoload_0 addr=0x02334b80 name=FUN_02334b80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x23c (Ghidra's cache says 0x194 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=102
// verify:  python tools/match.py --c <file> --func FUN_02334b80 --addr 0x02334b80 --size 0x23c --module unk_autoload_0 --version 2.0/sp1


void FUN_02334b80(undefined2 *param_1,uint param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 local_58 [19];
  undefined1 auStack_32 [38];
  
  puVar3 = local_58;
  if ((int)param_2 < -0x34) {
    if (-0x36 < (int)param_2) {
      FUN_02334b20(param_1,DAT_02334d6c,0xfffffff0);
      return;
    }
    if (param_2 == 0xffffffc0) {
      FUN_02334b20(param_1,DAT_02334d68,0xffffffec);
      return;
    }
  }
  else {
    switch(param_2) {
    case 0:
      FUN_02334b20(param_1,DAT_02334d98,0);
      return;
    case 1:
      FUN_02334b20(param_1,DAT_02334d9c,0);
      return;
    case 2:
      FUN_02334b20(param_1,DAT_02334da0,0);
      return;
    case 3:
      FUN_02334b20(param_1,DAT_02334da4,0);
      return;
    case 4:
      FUN_02334b20(param_1,DAT_02334da8,1);
      return;
    case 5:
      FUN_02334b20(param_1,DAT_02334dac,1);
      return;
    case 6:
      FUN_02334b20(param_1,DAT_02334db0,1);
      return;
    case 7:
      FUN_02334b20(param_1,DAT_02334db4,2);
      return;
    case 8:
      FUN_02334b20(param_1,DAT_02334db8,2);
      return;
    case 0xffffffe0:
      FUN_02334b20(param_1,DAT_02334d70,0xfffffff6);
      return;
    case 0xfffffff0:
      FUN_02334b20(param_1,DAT_02334d74,0xfffffffb);
      return;
    case 0xfffffff8:
      FUN_02334b20(param_1,DAT_02334d78,0xfffffffd);
      return;
    case 0xfffffff9:
      FUN_02334b20(param_1,DAT_02334d7c,0xfffffffd);
      return;
    case 0xfffffffa:
      FUN_02334b20(param_1,DAT_02334d80,0xfffffffe);
      return;
    case 0xfffffffb:
      FUN_02334b20(param_1,DAT_02334d84,0xfffffffe);
      return;
    case 0xfffffffc:
      FUN_02334b20(param_1,DAT_02334d88,0xfffffffe);
      return;
    case 0xfffffffd:
      FUN_02334b20(param_1,DAT_02334d8c,0xffffffff);
      return;
    case 0xfffffffe:
      FUN_02334b20(param_1,DAT_02334d90,0xffffffff);
      return;
    case 0xffffffff:
      FUN_02334b20(param_1,DAT_02334d94,0xffffffff);
      return;
    }
  }
  FUN_02334b80(auStack_32,(int)param_2 / 2);
  FUN_02334a18(param_1,auStack_32,auStack_32);
  if ((param_2 & 1) != 0) {
    iVar2 = 0x13;
    puVar4 = param_1;
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if ((int)param_2 < 1) {
      FUN_02334b20(auStack_32,DAT_02334d94,0xffffffff);
    }
    else {
      FUN_02334b20(auStack_32,DAT_02334d9c,0);
    }
    FUN_02334a18(param_1,local_58,auStack_32);
  }
  return;
}

