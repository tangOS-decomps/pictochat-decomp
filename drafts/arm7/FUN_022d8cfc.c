// decomp: module=arm7 addr=0x022d8cfc name=FUN_022d8cfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022d8cfc --addr 0x022d8cfc --size 0x44 --module arm7 --version 2.0/sp1


void FUN_022d8cfc(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  func_0x037cb78c(param_2,param_1,0x24);
  if (param_4 != 0) {
    func_0x037cb78c(param_3,param_1 + 0x28,param_4 + 1U & 0xfffffffe);
  }
  return;
}

