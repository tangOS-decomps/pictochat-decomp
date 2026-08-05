// decomp: module=arm7 addr=0x022d7518 name=FUN_022d7518
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d7518 --addr 0x022d7518 --size 0x40 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7518(uint param_1)

{
  if (param_1 < 2) {
    *(ushort *)(*DAT_022d7554 + 0x33a) =
         *(ushort *)(*DAT_022d7554 + 0x33a) & 0xffbf | (ushort)((param_1 << 0x1f) >> 0x19);
    return 0;
  }
  return 5;
}

