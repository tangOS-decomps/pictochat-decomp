// decomp: module=arm7 addr=0x022d7d30 name=FUN_022d7d30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d7d30 --addr 0x022d7d30 --size 0x88 --module arm7 --version 2.0/sp1


void FUN_022d7d30(void)

{
  undefined2 *puVar1;
  
  if (*(short *)(*DAT_022d7d98 + 0x5f8) == 2) {
    FUN_022d865c(DAT_022d7d9c);
  }
  *DAT_022d7da4 = (short)DAT_022d7da0;
  func_0x037c849c();
  FUN_022d862c(0x1e,*DAT_022d7da8 | 0x3f);
  puVar1 = DAT_022d7db4;
  *DAT_022d7db0 = (short)DAT_022d7dac;
  *puVar1 = 1;
  return;
}

