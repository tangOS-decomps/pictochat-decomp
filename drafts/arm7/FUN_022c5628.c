// decomp: module=arm7 addr=0x022c5628 name=FUN_022c5628
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34, arm
// triage: noise=33 statements=39
// verify:  python tools/match.py --c <file> --func FUN_022c5628 --addr 0x022c5628 --size 0x34 --module arm7 --version 2.0/sp1


undefined4 FUN_022c5628(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int unaff_r4;
  int unaff_r5;
  int unaff_r6;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  int unaff_r10;
  int unaff_r11;
  int in_r12;
  int in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  iVar1 = (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  *param_1 = iVar1;
  param_1[0x11] = (int)register0x00000054;
  param_1[1] = 1;
  param_1[2] = (int)(param_1 + 1);
  param_1[3] = iVar1;
  param_1[4] = param_4;
  param_1[5] = unaff_r4;
  param_1[6] = unaff_r5;
  param_1[7] = unaff_r6;
  param_1[8] = unaff_r7;
  param_1[9] = unaff_r8;
  param_1[10] = unaff_r9;
  param_1[0xb] = unaff_r10;
  param_1[0xc] = unaff_r11;
  param_1[0xd] = in_r12;
  param_1[0xe] = (int)register0x00000054;
  param_1[0xf] = in_lr;
  param_1[0x10] = (int)FUN_022c565c;
  return 0;
}

