// decomp: module=unk_autoload_0 addr=0x023374b8 name=FUN_023374b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38, arm
// triage: noise=10 statements=40
// verify:  python tools/match.py --c <file> --func FUN_023374b8 --addr 0x023374b8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_023374b8(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = (int)param_2 + param_3;
  iVar10 = (int)param_2 + (param_3 & 0xffffffe0);
  for (; (int)param_2 < iVar10; param_2 = param_2 + 8) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    uVar5 = param_1[4];
    uVar6 = param_1[5];
    uVar7 = param_1[6];
    uVar8 = param_1[7];
    param_1 = param_1 + 8;
    *param_2 = uVar1;
    param_2[1] = uVar2;
    param_2[2] = uVar3;
    param_2[3] = uVar4;
    param_2[4] = uVar5;
    param_2[5] = uVar6;
    param_2[6] = uVar7;
    param_2[7] = uVar8;
  }
  for (; (int)param_2 < iVar9; param_2 = param_2 + 1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
  }
  return;
}

