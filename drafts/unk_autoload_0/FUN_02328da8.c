// decomp: module=unk_autoload_0 addr=0x02328da8 name=FUN_02328da8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02328da8 --addr 0x02328da8 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_02328da8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = DAT_02328df4 + 0x100;
  param_1 = param_1 * 0x10;
  FUN_02336880(iVar1 + param_1,0xd0,0x10,param_4,param_4);
  FUN_02336880(DAT_02328df8,0xf0,0x10);
  FUN_02336880(iVar1 + param_1 + 10,0xf2,2);
  FUN_02336880(iVar1 + param_1,0xb0,0x10);
  FUN_02336880(DAT_02328dfc,0xb8,2);
  FUN_02336880(DAT_02328e00,0xb8,2);
  return;
}

