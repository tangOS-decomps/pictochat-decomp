// decomp: module=unk_autoload_0 addr=0x02323d28 name=FUN_02323d28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02323d28 --addr 0x02323d28 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02323d28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_023314e8(DAT_02323d38,0x2280,param_3,param_4,param_4);
  return DAT_02323d38;
}

