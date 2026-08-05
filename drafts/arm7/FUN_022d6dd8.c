// decomp: module=arm7 addr=0x022d6dd8 name=FUN_022d6dd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, arm
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d6dd8 --addr 0x022d6dd8 --size 0x40 --module arm7 --version 2.0/sp1


void FUN_022d6dd8(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((short)param_1[2] != 0) {
    while (iVar1 != -1) {
      iVar1 = *(int *)(iVar1 + 4);
      func_0x037c5998(param_1);
    }
  }
  return;
}

