// decomp: module=arm7 addr=0x022deb90 name=FUN_022deb90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022deb90 --addr 0x022deb90 --size 0x54 --module arm7 --version 2.0/sp1


void FUN_022deb90(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *DAT_022debdc;
  uVar1 = func_0x037c9084(0x1000000);
  *DAT_022debe0 = 2;
  if (*(short *)(iVar2 + 0x468) != 0) {
    func_0x037c7d3c();
  }
  func_0x037c904c(uVar1);
  return;
}

