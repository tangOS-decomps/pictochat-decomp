// decomp: module=arm7 addr=0x022d73dc name=FUN_022d73dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d73dc --addr 0x022d73dc --size 0x68 --module arm7 --version 2.0/sp1


undefined4 FUN_022d73dc(uint param_1)

{
  int *piVar1;
  
  piVar1 = DAT_022d743c;
  if (param_1 < 2) {
    *(ushort *)(*DAT_022d743c + 0x33a) =
         *(ushort *)(*DAT_022d743c + 0x33a) & 0xfff7 | (ushort)((param_1 << 0x1f) >> 0x1c);
    *DAT_022d7440 =
         (ushort)((ushort)(((uint)*(ushort *)(*piVar1 + 0x33a) << 0x1c) >> 0x10) ^
                 (ushort)(((uint)*(ushort *)(*piVar1 + 0x33a) << 0x1a) >> 0x10)) >> 0xf;
    return 0;
  }
  return 5;
}

