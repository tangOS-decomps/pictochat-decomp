// decomp: module=unk_autoload_0 addr=0x023346ec name=FUN_023346ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=4
// verify:  python tools/match.py --c <file> --func FUN_023346ec --addr 0x023346ec --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_023346ec(undefined4 param_1,uint param_2)

{
  return CONCAT44(DAT_02334700 & param_2,param_1);
}

