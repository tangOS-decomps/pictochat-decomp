// decomp: module=unk_autoload_0 addr=0x02322940 name=FUN_02322940
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02322940 --addr 0x02322940 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322940(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02322960;
  *DAT_02322960 = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[1] = 0;
  FUN_02339ac0(0,DAT_02322964,param_3,param_4,param_4);
  FUN_02339ac0(1,DAT_02322964);
  return;
}

