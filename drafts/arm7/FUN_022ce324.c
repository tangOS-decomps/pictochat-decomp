// decomp: module=arm7 addr=0x022ce324 name=FUN_022ce324
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc4, arm
// triage: noise=17 statements=52
// verify:  python tools/match.py --c <file> --func FUN_022ce324 --addr 0x022ce324 --size 0xc4 --module arm7 --version 2.0/sp1


void FUN_022ce324(undefined2 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  byte in_r12;
  byte bVar5;
  bool bVar6;
  
  uVar3 = param_2[2];
  *(undefined4 *)(param_1 + 2) = uVar3;
  param_1[4] = *(undefined2 *)(param_2 + 3);
  bVar6 = *(short *)((int)param_2 + 0x12) != 0;
  if (bVar6) {
    uVar3 = 2;
  }
  bVar2 = (byte)uVar3;
  if (!bVar6) {
    bVar2 = 0;
  }
  bVar6 = *(short *)((int)param_2 + 0xe) != 0;
  if (bVar6) {
    in_r12 = 1;
  }
  if (!bVar6) {
    in_r12 = 0;
  }
  if (*(short *)(param_2 + 5) == 0) {
    bVar5 = 0;
  }
  else {
    bVar5 = 4;
  }
  *(byte *)((int)param_1 + 0xb) = bVar5 | in_r12 | bVar2;
  *(char *)(param_1 + 5) = (char)*(undefined2 *)(param_2 + 1);
  *param_1 = 1;
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)((int)param_1 + 3) = 0;
  param_1[6] = *(undefined2 *)(param_2 + 0xd);
  if ((*(short *)((int)param_2 + 0x12) == 0) || (*(ushort *)((int)param_2 + 0x36) < 8)) {
    uVar1 = *(undefined2 *)((int)param_2 + 0x36);
  }
  else {
    uVar1 = 8;
  }
  param_1[7] = uVar1;
  if (*(byte *)(param_1 + 5) != 0) {
    uVar4 = *(byte *)(param_1 + 5) + 1;
    func_0x037cb8b4(*param_2,param_1 + 8,uVar4 & 0xfffffffe,uVar4,param_4);
  }
  return;
}

