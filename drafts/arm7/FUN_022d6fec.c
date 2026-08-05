// decomp: module=arm7 addr=0x022d6fec name=FUN_022d6fec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022d6fec --addr 0x022d6fec --size 0x34 --module arm7 --version 2.0/sp1


undefined4 FUN_022d6fec(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 3) {
    *(short *)(*DAT_022d701c + 0x330) = (short)param_1;
    FUN_022d7c08();
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

