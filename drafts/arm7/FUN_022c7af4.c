// decomp: module=arm7 addr=0x022c7af4 name=FUN_022c7af4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c7af4 --addr 0x022c7af4 --size 0x24 --module arm7 --version 2.0/sp1


uint FUN_022c7af4(void)

{
  uint uVar1;
  
  uVar1 = DAT_022c7b10 * *DAT_022c7b0c + DAT_022c7b14;
  *DAT_022c7b0c = uVar1;
  return uVar1 >> 0x10;
}

