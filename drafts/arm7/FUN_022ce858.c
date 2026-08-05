// decomp: module=arm7 addr=0x022ce858 name=FUN_022ce858
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022ce858 --addr 0x022ce858 --size 0x2c --module arm7 --version 2.0/sp1


void FUN_022ce858(short param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_022ce880 + 0x550);
  *(short *)(iVar1 + 0x30) = param_1;
  if (*(short *)(iVar1 + 0x188) == 0) {
    *(short *)(iVar1 + 0x38) = param_1 + 4;
  }
  else {
    *(short *)(iVar1 + 0x3a) = param_1 + 4;
  }
  return;
}

