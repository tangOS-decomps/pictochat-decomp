// decomp: module=unk_autoload_0 addr=0x02322894 name=FUN_02322894
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, thumb
// triage: noise=2 statements=6
// verify:  python tools/match.py --c <file> --func FUN_02322894 --addr 0x02322894 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_02322894(int param_1,int param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_02335e0c((param_2 - param_1) * 0x10);
  return uVar1;
}

