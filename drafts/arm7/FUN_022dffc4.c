// decomp: module=arm7 addr=0x022dffc4 name=FUN_022dffc4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=10
// verify:  python tools/match.py --c <file> --func FUN_022dffc4 --addr 0x022dffc4 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022dffc4(int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  
  func_0x037cb774(0,param_1,0x2c,param_4,param_4);
  uVar1 = FUN_022d85b4();
  *(undefined2 *)(param_1 + 0x10) = uVar1;
  FUN_022d816c((ushort *)(param_1 + 0x18),param_2,(ushort *)(*DAT_022e000c + 0x324),
               (ushort *)(*DAT_022e000c + 0x3a8));
  return;
}

