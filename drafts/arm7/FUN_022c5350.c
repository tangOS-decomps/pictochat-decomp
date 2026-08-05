// decomp: module=arm7 addr=0x022c5350 name=FUN_022c5350
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, arm
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c5350 --addr 0x022c5350 --size 0x2c --module arm7 --version 2.0/sp1


void FUN_022c5350(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_022c6d40();
  *(undefined4 *)(param_1 + 0x48) = 1;
  FUN_022c4e28();
  FUN_022c6d54(uVar1);
  return;
}

