// decomp: module=unk_autoload_0 addr=0x02331aec name=FUN_02331aec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x7c - it excludes this function's trailing literal pool), arm
// triage: noise=48 statements=42
// verify:  python tools/match.py --c <file> --func FUN_02331aec --addr 0x02331aec --size 0x80 --module unk_autoload_0 --version 2.0/sp1


int FUN_02331aec(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 *in_r12;
  undefined4 in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  puVar1 = DAT_02331b68;
  DAT_02331b68[0x1b] = param_1;
  puVar1[1] = *in_r12;
  puVar1[2] = in_r12[1];
  puVar1[3] = in_r12[2];
  puVar1[4] = in_r12[3];
  puVar2 = (undefined4 *)(in_r12[4] & 0xfffffffe);
  puVar1[5] = unaff_r4;
  puVar1[6] = unaff_r5;
  puVar1[7] = unaff_r6;
  puVar1[8] = unaff_r7;
  puVar1[9] = unaff_r8;
  puVar1[10] = unaff_r9;
  puVar1[0xb] = unaff_r10;
  puVar1[0xc] = unaff_r11;
  puVar1[0x19] = *puVar2;
  *puVar1 = puVar2[1];
  puVar1[0xd] = puVar2[2];
  puVar1[0x10] = puVar2[3];
  puVar1[0xe] = register0x00000054;
  puVar1[0xf] = in_lr;
  return (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
}

