// decomp: module=arm7 addr=0x022d9dc4 name=FUN_022d9dc4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d9dc4 --addr 0x022d9dc4 --size 0x40 --module arm7 --version 2.0/sp1


void FUN_022d9dc4(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_022d9ffc();
  if (iVar1 == 0x40) {
    *(ushort *)(*DAT_022d9e00 + 0x530) =
         *(ushort *)(*DAT_022d9e00 + 0x530) & ~(ushort)(1 << (param_1 & 0xff));
  }
  return;
}

