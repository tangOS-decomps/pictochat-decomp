// decomp: module=arm7 addr=0x022c2f98 name=FUN_022c2f98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c2f98 --addr 0x022c2f98 --size 0x38 --module arm7 --version 2.0/sp1


uint FUN_022c2f98(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *DAT_022c2fcc;
  uVar2 = func_0x00dd5080(iVar1 + 0x47c);
  uVar3 = func_0x00dd5080(iVar1 + 0x490);
  return uVar2 | uVar3;
}

