// decomp: module=unk_autoload_0 addr=0x0232a57c name=FUN_0232a57c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), thumb
// triage: noise=19 statements=28
// verify:  python tools/match.py --c <file> --func FUN_0232a57c --addr 0x0232a57c --size 0x7c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a57c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  short extraout_r1;
  
  puVar1 = DAT_0232a5f0;
  DAT_0232a5f0[3] = 1;
  FUN_0232a51c(DAT_0232a5f4,puVar1[3] & 0xff,param_3,param_4,param_4);
  puVar1 = DAT_0232a5f0;
  DAT_0232a5f0[2] = 8;
  FUN_0233746c(0,*(undefined4 *)(puVar1 + 0x28),0x40);
  puVar1 = DAT_0232a5f0;
  *(undefined4 *)(*(int *)(DAT_0232a5f0 + 0x28) + 8) = 0;
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0xe) = 1;
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0x10) = 0xf;
  uVar2 = FUN_0232a4c8();
  FUN_02336018(uVar2,10);
  puVar1 = DAT_0232a5f0;
  *(short *)(*(int *)(DAT_0232a5f0 + 0x28) + 0x18) = extraout_r1 + 100;
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0x34) = 0xc0;
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0x36) = 0xc0;
  puVar1[4] = puVar1[4] + 1;
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0xc) = puVar1[4];
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 0x32) = *puVar1;
  **(undefined4 **)(puVar1 + 0x28) = *(undefined4 *)(puVar1 + 0x1a);
  *(undefined2 *)(*(int *)(puVar1 + 0x28) + 4) = puVar1[2];
  return;
}

