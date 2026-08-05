// decomp: module=unk_autoload_0 addr=0x023381cc name=FUN_023381cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023381cc --addr 0x023381cc --size 0x2a --module unk_autoload_0 --version 2.0/sp1


uint FUN_023381cc(int param_1,int param_2)

{
  uint uVar1;
  
  FUN_02337980();
  uVar1 = *(uint *)(param_1 + param_2 * 4 + 0x3c);
  if (uVar1 == 0) {
    uVar1 = 0;
  }
  else if (uVar1 < 0x2000000) {
    uVar1 = param_1 + uVar1;
  }
  FUN_02337990();
  return uVar1;
}

