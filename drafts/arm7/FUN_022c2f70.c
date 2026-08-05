// decomp: module=arm7 addr=0x022c2f70 name=FUN_022c2f70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c2f70 --addr 0x022c2f70 --size 0x28 --module arm7 --version 2.0/sp1


uint FUN_022c2f70(uint param_1)

{
  if (DAT_022c2f90 <= param_1) {
    param_1 = param_1 - *(ushort *)(*DAT_022c2f94 + 0x3de);
  }
  return param_1;
}

