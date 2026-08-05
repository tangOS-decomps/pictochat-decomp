// decomp: module=unk_autoload_0 addr=0x02337d30 name=FUN_02337d30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337d30 --addr 0x02337d30 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


int FUN_02337d30(void)

{
  int *piVar1;
  int iVar2;
  
  FUN_02332080();
  iVar2 = 0;
  for (piVar1 = *(int **)(DAT_02337d50 + 8); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    iVar2 = iVar2 + 1;
  }
  FUN_02332094();
  return iVar2;
}

