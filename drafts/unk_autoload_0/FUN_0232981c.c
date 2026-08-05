// decomp: module=unk_autoload_0 addr=0x0232981c name=FUN_0232981c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=21
// verify:  python tools/match.py --c <file> --func FUN_0232981c --addr 0x0232981c --size 0x3c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232981c(void)

{
  int iVar1;
  
  if (*(int *)(DAT_02329854 + 0x10) != 0) {
    return 1;
  }
  iVar1 = *(int *)(DAT_02329854 + 0x18);
  if (iVar1 == 1) {
    FUN_023298c0(0);
    return 1;
  }
  if (iVar1 == 2) {
    FUN_02329858();
    return 1;
  }
  if (iVar1 != 3) {
    return 0;
  }
  FUN_0232987c();
  return 1;
}

