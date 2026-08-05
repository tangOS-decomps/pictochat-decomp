// decomp: module=unk_autoload_0 addr=0x0233905c name=FUN_0233905c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=15  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233905c --addr 0x0233905c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233905c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02339080;
  iVar2 = *(int *)(DAT_0233907c + 0x2c);
  while (iVar2 != 0) {
    iVar2 = FUN_023320e4();
    if (iVar2 == 0x12) {
      FUN_02338390();
    }
    iVar2 = *piVar1;
  }
  return;
}

