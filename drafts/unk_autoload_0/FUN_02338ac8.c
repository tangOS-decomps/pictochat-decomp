// decomp: module=unk_autoload_0 addr=0x02338ac8 name=FUN_02338ac8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02338ac8 --addr 0x02338ac8 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02338ac8(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = DAT_02338b00;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  *DAT_02338b00 = *param_1;
  puVar2[1] = uVar3;
  puVar2[2] = uVar4;
  puVar2[3] = uVar5;
  uVar1 = *(undefined2 *)((int)param_1 + 0x1a);
  *(undefined2 *)(puVar2 + -4) = *(undefined2 *)(param_1 + 6);
  *(undefined2 *)(puVar2 + 8) = uVar1;
  uVar3 = param_1[5];
  puVar2[10] = param_1[4];
  puVar2[0xb] = uVar3;
  return;
}

