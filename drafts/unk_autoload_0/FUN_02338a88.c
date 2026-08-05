// decomp: module=unk_autoload_0 addr=0x02338a88 name=FUN_02338a88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02338a88 --addr 0x02338a88 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338a88(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar3 = DAT_02338ac4;
  uVar4 = DAT_02338ac4[1];
  uVar5 = DAT_02338ac4[2];
  uVar6 = DAT_02338ac4[3];
  *param_1 = *DAT_02338ac4;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  param_1[3] = uVar6;
  uVar1 = *(ushort *)(puVar3 + -4);
  uVar4 = puVar3[0xb];
  param_1[4] = puVar3[10];
  param_1[5] = uVar4;
  uVar2 = *(ushort *)(puVar3 + 8);
  *(ushort *)(param_1 + 6) = uVar1 & 3;
  *(ushort *)((int)param_1 + 0x1a) = uVar2 & 1;
  return;
}

