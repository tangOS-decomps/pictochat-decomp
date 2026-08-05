// decomp: module=arm7 addr=0x022dded8 name=FUN_022dded8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38, arm
// triage: noise=7 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022dded8 --addr 0x022dded8 --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022dded8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + (uint)*(ushort *)(param_2 + 0xe) * 2;
  *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined2 *)(iVar1 + 0x12) = 2;
  *(undefined2 *)(iVar1 + 0x14) = 0;
  *(undefined2 *)(iVar1 + 0x16) = *(undefined2 *)(param_2 + 0x18);
  func_0x037c5de8();
  return;
}

