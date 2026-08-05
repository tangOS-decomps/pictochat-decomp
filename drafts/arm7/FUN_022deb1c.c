// decomp: module=arm7 addr=0x022deb1c name=FUN_022deb1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022deb1c --addr 0x022deb1c --size 0x74 --module arm7 --version 2.0/sp1


void FUN_022deb1c(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_022deb88;
  uVar1 = func_0x037c9084(0x1000000);
  if (-1 < (int)((uint)*(ushort *)(*DAT_022deb88 + 0x33a) << 0x18)) {
    FUN_022d80f8(0);
  }
  *DAT_022deb8c = 0xc0;
  *(undefined2 *)(iVar2 + 0x47c) = 0;
  *(undefined2 *)(iVar2 + 0x490) = 0;
  func_0x037c904c(uVar1);
  return;
}

