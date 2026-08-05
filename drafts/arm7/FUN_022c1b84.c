// decomp: module=arm7 addr=0x022c1b84 name=FUN_022c1b84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd4 (Ghidra's cache says 0xcc - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=48  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c1b84 --addr 0x022c1b84 --size 0xd4 --module arm7 --version 2.0/sp1


void FUN_022c1b84(void)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = DAT_022c1c50;
  while( true ) {
    uVar1 = *puVar2 & puVar2[1];
    if (uVar1 == 0) break;
    if ((uVar1 & 0x80) != 0) {
      FUN_022c2ac4();
    }
    if ((uVar1 & 0x40) != 0) {
      FUN_022c2bd0();
    }
    if ((uVar1 & 0x8000) != 0) {
      FUN_022c1c58();
    }
    if ((uVar1 & 0x4000) != 0) {
      FUN_022c1ce4();
    }
    if ((uVar1 & 0x2000) != 0) {
      FUN_022c1f88();
    }
    if ((uVar1 & 0x800) != 0) {
      func_0x00dd506c();
    }
    if ((uVar1 & 8) != 0) {
      FUN_022c2024();
    }
    if ((uVar1 & 4) != 0) {
      FUN_022c2134();
    }
    if ((uVar1 & 1) != 0) {
      FUN_022c2518();
    }
    if ((uVar1 & 0x30) != 0) {
      FUN_022c1ff4();
    }
    if ((uVar1 & 2) != 0) {
      FUN_022c22b0();
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_022c29d4(1);
    }
  }
  *DAT_022c1c54 = *DAT_022c1c54 | 0x1000000;
  return;
}

