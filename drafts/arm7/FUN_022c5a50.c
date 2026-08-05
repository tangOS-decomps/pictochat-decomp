// decomp: module=arm7 addr=0x022c5a50 name=FUN_022c5a50
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, arm
// triage: noise=3 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c5a50 --addr 0x022c5a50 --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022c5a50(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_022c5ab4();
  *(undefined4 *)(param_1 * 4 + 0x2fffdc4) = uVar1;
  uVar1 = FUN_022c5b30(param_1);
  *(undefined4 *)(param_1 * 4 + 0x2fffda0) = uVar1;
  return;
}

