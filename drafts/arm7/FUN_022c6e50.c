// decomp: module=arm7 addr=0x022c6e50 name=FUN_022c6e50
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022c6e50 --addr 0x022c6e50 --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022c6e50(void)

{
  short *psVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  uVar2 = DAT_022c6e84;
  psVar1 = DAT_022c6e80;
  if (*DAT_022c6e80 == 0) {
    *DAT_022c6e80 = 1;
    thunk_EXT_FUN_037fee30(0xc,uVar2,psVar1,1,in_r3);
  }
  return;
}

