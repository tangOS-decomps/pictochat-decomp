// decomp: module=unk_autoload_0 addr=0x0232e27c name=FUN_0232e27c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, thumb
// triage: noise=0 statements=20  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e27c --addr 0x0232e27c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e27c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 8);
  iVar1 = *(int *)(param_2 + 0xc);
  if (iVar2 == 0) {
    *param_1 = iVar1;
  }
  else {
    *(int *)(iVar2 + 0xc) = iVar1;
  }
  if (iVar1 == 0) {
    param_1[1] = iVar2;
  }
  else {
    *(int *)(iVar1 + 8) = iVar2;
  }
  return iVar2;
}

