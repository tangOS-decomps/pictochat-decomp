// decomp: module=arm7 addr=0x022c5bb0 name=FUN_022c5bb0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, arm
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c5bb0 --addr 0x022c5bb0 --size 0x28 --module arm7 --version 2.0/sp1


int FUN_022c5bb0(int param_1,int *param_2)

{
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 == 0) {
    param_1 = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  return param_1;
}

