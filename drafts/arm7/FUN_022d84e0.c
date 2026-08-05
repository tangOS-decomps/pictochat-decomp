// decomp: module=arm7 addr=0x022d84e0 name=FUN_022d84e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=4  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d84e0 --addr 0x022d84e0 --size 0x20 --module arm7 --version 2.0/sp1


uint FUN_022d84e0(uint param_1)

{
  return (uint)*(ushort *)(*DAT_022d84fc + 0x32c) & 1 << (param_1 & 0xff);
}

