// decomp: module=unk_autoload_0 addr=0x0232bccc name=FUN_0232bccc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232bccc --addr 0x0232bccc --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bccc(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_0232981c();
  if (((iVar2 == 0) && (*(short *)(param_1 + 2) == 0)) &&
     (sVar1 = *(short *)(param_1 + 4), sVar1 != 7)) {
    if (sVar1 == 9) {
      FUN_0232bc84(param_1);
    }
    else if (sVar1 == 0x15) {
      FUN_0232bb9c(param_1);
      return;
    }
  }
  return;
}

