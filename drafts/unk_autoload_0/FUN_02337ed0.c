// decomp: module=unk_autoload_0 addr=0x02337ed0 name=FUN_02337ed0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02337ed0 --addr 0x02337ed0 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_02337ed0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_023314cc(*DAT_02337ee8 + 8,2,param_3,param_4,param_4);
  return *(undefined2 *)(*DAT_02337ee8 + 8);
}

