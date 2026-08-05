// decomp: module=unk_autoload_0 addr=0x0232acd8 name=FUN_0232acd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_0232acd8 --addr 0x0232acd8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232acd8(void)

{
  int iVar1;
  
  FUN_0232b9e4();
  FUN_0232a648(0,0);
  if (*(int *)(DAT_0232ad08 + 0x30) == 0) {
    iVar1 = FUN_0232996c();
    if (iVar1 == 6) {
      *(undefined4 *)(DAT_0232ad08 + 0x14) = 1;
    }
    FUN_02329b2c(DAT_0232ad0c,0);
  }
  return;
}

