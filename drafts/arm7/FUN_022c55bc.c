// decomp: module=arm7 addr=0x022c55bc name=FUN_022c55bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c, arm
// triage: noise=2 statements=34
// verify:  python tools/match.py --c <file> --func FUN_022c55bc --addr 0x022c55bc --size 0x6c --module arm7 --version 2.0/sp1


void FUN_022c55bc(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_1[0x10] = param_2 + 4U;
  param_1[0x11] = param_3;
  uVar2 = param_3 - 0x40;
  if ((uVar2 & 4) != 0) {
    uVar2 = param_3 - 0x44;
  }
  param_1[0xe] = uVar2;
  if ((param_2 + 4U & 1) == 0) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0x3f;
  }
  *param_1 = uVar1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 0;
  return;
}

