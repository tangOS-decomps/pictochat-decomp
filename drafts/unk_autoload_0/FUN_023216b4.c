// decomp: module=unk_autoload_0 addr=0x023216b4 name=FUN_023216b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=6
// verify:  python tools/match.py --c <file> --func FUN_023216b4 --addr 0x023216b4 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_023216b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_02321a6c(*(undefined4 *)(param_1 + 0x24),param_1,param_2,param_3,DAT_023216dc,0,0,0xffffffff,
               param_4);
  return;
}

