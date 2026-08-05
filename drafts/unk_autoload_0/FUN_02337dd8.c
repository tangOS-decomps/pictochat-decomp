// decomp: module=unk_autoload_0 addr=0x02337dd8 name=FUN_02337dd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=20  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337dd8 --addr 0x02337dd8 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


int * FUN_02337dd8(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_02332080();
  piVar1 = DAT_02337e04;
  piVar3 = (int *)*DAT_02337e04;
  if (piVar3 == (int *)0x0) {
    FUN_02332094();
    return (int *)0x0;
  }
  iVar2 = *piVar3;
  *DAT_02337e04 = iVar2;
  if (iVar2 == 0) {
    piVar1[4] = 0;
  }
  FUN_02332094();
  return piVar3;
}

