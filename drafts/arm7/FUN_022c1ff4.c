// decomp: module=arm7 addr=0x022c1ff4 name=FUN_022c1ff4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c1ff4 --addr 0x022c1ff4 --size 0x30 --module arm7 --version 2.0/sp1


void FUN_022c1ff4(void)

{
  undefined2 *puVar1;
  
  func_0x00dd3a08();
  puVar1 = DAT_022c201c + -0xce;
  *DAT_022c201c = (short)DAT_022c2020;
  *puVar1 = 0x30;
  return;
}

