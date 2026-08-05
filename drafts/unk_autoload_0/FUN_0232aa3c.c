// decomp: module=unk_autoload_0 addr=0x0232aa3c name=FUN_0232aa3c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232aa3c --addr 0x0232aa3c --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232aa3c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232981c();
  if ((((iVar1 == 0) && (iVar1 = FUN_0232ad80(), iVar1 == 0)) &&
      ((iVar1 = FUN_0232996c(), iVar1 == 7 || (((iVar1 == 6 || (iVar1 == 10)) || (iVar1 == 9))))))
     && (*(short *)(param_1 + 4) == 0x15)) {
    if ((*(short *)(DAT_0232aa88 + 0xc) != 0) && (*(ushort *)(DAT_0232aa88 + 0xc) < 0x10)) {
      FUN_0232ad10(param_1);
      return;
    }
    FUN_0232ac60(param_1);
  }
  return;
}

