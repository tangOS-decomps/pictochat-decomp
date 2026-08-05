// decomp: module=unk_autoload_0 addr=0x02329978 name=FUN_02329978
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02329978 --addr 0x02329978 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329978(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_023314cc(*(undefined4 *)(*(int *)(DAT_02329990 + 4) + 4),2000,param_3,param_4,param_4);
  return *(undefined4 *)(*(int *)(DAT_02329990 + 4) + 4);
}

