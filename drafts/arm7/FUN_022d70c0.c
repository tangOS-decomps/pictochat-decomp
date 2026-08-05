// decomp: module=arm7 addr=0x022d70c0 name=FUN_022d70c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022d70c0 --addr 0x022d70c0 --size 0x24 --module arm7 --version 2.0/sp1


undefined4 FUN_022d70c0(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    *(short *)(*DAT_022d70e0 + 0x336) = (short)param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

