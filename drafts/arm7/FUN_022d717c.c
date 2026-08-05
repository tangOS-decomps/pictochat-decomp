// decomp: module=arm7 addr=0x022d717c name=FUN_022d717c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022d717c --addr 0x022d717c --size 0x38 --module arm7 --version 2.0/sp1


undefined4 FUN_022d717c(uint param_1)

{
  if (param_1 < 2) {
    *(ushort *)(*DAT_022d71b0 + 0x33a) =
         *(ushort *)(*DAT_022d71b0 + 0x33a) & 0xfffd | (ushort)((param_1 << 0x1f) >> 0x1e);
    return 0;
  }
  return 5;
}

