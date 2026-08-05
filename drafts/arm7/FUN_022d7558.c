// decomp: module=arm7 addr=0x022d7558 name=FUN_022d7558
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022d7558 --addr 0x022d7558 --size 0x50 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7558(uint param_1)

{
  if (param_1 < 2) {
    *(ushort *)(*DAT_022d75a0 + 0x33a) =
         *(ushort *)(*DAT_022d75a0 + 0x33a) & 0xff7f | (ushort)(byte)((param_1 << 0x1f) >> 0x18);
    if (param_1 == 1) {
      DAT_022d75a4[-1] = *DAT_022d75a4;
    }
    return 0;
  }
  return 5;
}

