// decomp: module=unk_autoload_0 addr=0x02325c88 name=FUN_02325c88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02325c88 --addr 0x02325c88 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02325c88(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = DAT_02325cac;
  *DAT_02325cac =
       (param_3 - param_1) * (param_3 - param_1) + (param_4 - param_2) * (param_4 - param_2);
  do {
  } while (((uint)*(ushort *)(piVar1 + -2) & (uint)piVar1 >> 0xb) != 0);
  return *DAT_02325cb0;
}

