// decomp: module=arm7 addr=0x022df0b0 name=FUN_022df0b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=16
// verify:  python tools/match.py --c <file> --func FUN_022df0b0 --addr 0x022df0b0 --size 0x74 --module arm7 --version 2.0/sp1


void FUN_022df0b0(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_022d991c(param_1 + 0x18);
  *(undefined2 *)(param_1 + 2) = uVar1;
  if (*(short *)(param_1 + 2) == 0xff) {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  *(short *)(param_1 + 4) = (short)*(undefined4 *)(*DAT_022df120 + 0x3ec);
  if ((*(ushort *)(param_1 + 0x14) & 0x4000) != 0) {
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 8;
  }
  FUN_022d9b60(param_1);
  func_0x037c5a18(*DAT_022df120 + 0x188,*DAT_022df120 + 0x1a0,param_1 + -0x10);
  return;
}

