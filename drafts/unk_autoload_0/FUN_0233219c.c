// decomp: module=unk_autoload_0 addr=0x0233219c name=FUN_0233219c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_0233219c --addr 0x0233219c --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233219c(byte *param_1)

{
  int iVar1;
  
  iVar1 = DAT_023321f0;
  *param_1 = (byte)*(undefined2 *)(DAT_023321f0 + 100) & 7;
  param_1[1] = *(byte *)(iVar1 + 2) & 0xf;
  param_1[2] = *(byte *)(iVar1 + 3);
  param_1[3] = *(byte *)(iVar1 + 4);
  *(ushort *)(param_1 + 0x1a) = (ushort)*(byte *)(iVar1 + 0x1a);
  *(ushort *)(param_1 + 0x52) = (ushort)*(byte *)(iVar1 + 0x50);
  FUN_02337424(iVar1 + 6,param_1 + 4,0x14);
  FUN_02337424(DAT_023321f0 + 0x1c,param_1 + 0x1c,0x34);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  return;
}

