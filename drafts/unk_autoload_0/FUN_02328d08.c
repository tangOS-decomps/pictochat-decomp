// decomp: module=unk_autoload_0 addr=0x02328d08 name=FUN_02328d08
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02328d08 --addr 0x02328d08 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_02328d08(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  
  puVar1 = DAT_02328d54;
  if (param_1 != 0) {
    *DAT_02328d54 = *DAT_02328d54 & DAT_02328d58 | 0x8000;
    FUN_02328d60(0x1f,1,puVar1,param_4,param_4);
    FUN_02328d80(0x1f,0);
    FUN_02336444(DAT_02328d5c,0x3f,0xfffffff9);
    return;
  }
  FUN_02328d60(0x1f,1,param_3,param_4,param_4);
  FUN_02328d80(0x1f,1);
  *DAT_02328d5c = 0;
  return;
}

