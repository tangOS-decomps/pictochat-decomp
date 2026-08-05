// decomp: module=arm7 addr=0x022d3be8 name=FUN_022d3be8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022d3be8 --addr 0x022d3be8 --size 0xb0 --module arm7 --version 2.0/sp1


void FUN_022d3be8(void)

{
  int *piVar1;
  undefined4 in_r3;
  int iVar2;
  
  piVar1 = DAT_022d3c8c;
  iVar2 = *(int *)(DAT_022d3c88 + 0x550);
  if (*(short *)(iVar2 + 0xe6) == 1) {
    if (*DAT_022d3c8c != 0) {
      func_0x037cb258();
    }
    func_0x037cb0b8(DAT_022d3c8c,0xcb,0x107,DAT_022d3c90,3,in_r3);
  }
  else if (*(short *)(iVar2 + 0xe6) == 2) {
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    if (*piVar1 != 0) {
      func_0x037cb258();
    }
    func_0x037cb0b8(DAT_022d3c8c,200,0x107,DAT_022d3c94,1,in_r3);
    *(undefined4 *)(iVar2 + 0xd8) = 0;
  }
  return;
}

