// decomp: module=unk_autoload_0 addr=0x023381ac name=FUN_023381ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20, thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_023381ac --addr 0x023381ac --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_023381ac(int param_1,int param_2,undefined4 param_3)

{
  FUN_02337980();
  *(undefined4 *)(param_1 + 0x3c + param_2 * 4) = param_3;
  FUN_023314e8(param_1 + 0x3c + param_2 * 4,4);
  FUN_02337990();
  return;
}

