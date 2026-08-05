// decomp: module=unk_autoload_0 addr=0x0232e614 name=FUN_0232e614
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232e614 --addr 0x0232e614 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e614(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0232e1f4(param_1,DAT_0232e63c,param_1 + 0x30,param_2,param_3);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}

