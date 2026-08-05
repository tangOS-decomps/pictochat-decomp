// decomp: module=arm7 addr=0x022c826c name=FUN_022c826c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x12, thumb
// triage: noise=3 statements=7
// verify:  python tools/match.py --c <file> --func FUN_022c826c --addr 0x022c826c --size 0x12 --module arm7 --version 2.0/sp1


void FUN_022c826c(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_022c8600(param_2);
  *(undefined2 *)(param_1 + 0x20) = uVar1;
  return;
}

