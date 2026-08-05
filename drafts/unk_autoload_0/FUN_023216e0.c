// decomp: module=unk_autoload_0 addr=0x023216e0 name=FUN_023216e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=6
// verify:  python tools/match.py --c <file> --func FUN_023216e0 --addr 0x023216e0 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_023216e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_02321a6c(*(undefined4 *)(param_1 + 0x24),param_1,*(undefined4 *)(param_1 + 0x20),
               *(undefined2 *)(param_1 + 0x1e),DAT_02321704,param_2,0,0xffffffff,param_4);
  return;
}

