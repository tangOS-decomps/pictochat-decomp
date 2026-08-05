// decomp: module=arm7 addr=0x022d86ec name=FUN_022d86ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x70 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d86ec --addr 0x022d86ec --size 0x70 --module arm7 --version 2.0/sp1


void FUN_022d86ec(void)

{
  int iVar1;
  
  iVar1 = *DAT_022d8758;
  func_0x037cb774(0,iVar1 + 0x5f8,0x10);
  FUN_022e2e4c(0x40,1,iVar1 + 0x5f8);
  FUN_022e2e4c(0x41,1,iVar1 + 0x5fa);
  FUN_022e2e4c(0x42,1,iVar1 + 0x5fc);
  FUN_022e2e4c(0x43,1,iVar1 + 0x5fe);
  return;
}

