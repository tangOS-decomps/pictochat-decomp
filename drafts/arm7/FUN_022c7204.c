// decomp: module=arm7 addr=0x022c7204 name=FUN_022c7204
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8, arm
// triage: noise=4 statements=7
// verify:  python tools/match.py --c <file> --func FUN_022c7204 --addr 0x022c7204 --size 0x8 --module arm7 --version 2.0/sp1


undefined4 FUN_022c7204(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}

