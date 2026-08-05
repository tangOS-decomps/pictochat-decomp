// decomp: module=unk_autoload_0 addr=0x02337eec name=FUN_02337eec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02337eec --addr 0x02337eec --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02337eec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_023314cc(*DAT_02337f00,4,param_3,param_4,param_4);
  return *(undefined4 *)*DAT_02337f00;
}

