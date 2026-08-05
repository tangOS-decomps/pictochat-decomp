// decomp: module=arm7 addr=0x022d7144 name=FUN_022d7144
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d7144 --addr 0x022d7144 --size 0x38 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7144(uint param_1)

{
  if (param_1 < 2) {
    *(ushort *)(*DAT_022d7178 + 0x33a) =
         *(ushort *)(*DAT_022d7178 + 0x33a) & 0xfffe | (ushort)param_1 & 1;
    return 0;
  }
  return 5;
}

