// decomp: module=arm7 addr=0x022d6ef8 name=FUN_022d6ef8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022d6ef8 --addr 0x022d6ef8 --size 0x34 --module arm7 --version 2.0/sp1


undefined4 FUN_022d6ef8(uint param_1)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_022d6f28;
  if (param_1 < 0x100) {
    *(short *)(*DAT_022d6f24 + 0x32a) = (short)param_1;
    *puVar1 = (short)param_1;
    return 0;
  }
  return 5;
}

