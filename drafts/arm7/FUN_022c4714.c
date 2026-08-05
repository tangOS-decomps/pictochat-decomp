// decomp: module=arm7 addr=0x022c4714 name=FUN_022c4714
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022c4714 --addr 0x022c4714 --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022c4714(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_022c4730;
  DAT_022c4730[1] = 0;
  puVar2 = DAT_022c4734;
  *puVar1 = 0;
  *puVar2 = 0;
  return;
}

