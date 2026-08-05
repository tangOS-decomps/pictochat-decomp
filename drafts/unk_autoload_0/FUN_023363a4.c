// decomp: module=unk_autoload_0 addr=0x023363a4 name=FUN_023363a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_023363a4 --addr 0x023363a4 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_023363a4(ushort param_1,uint param_2,int param_3)

{
  *DAT_023363e4 = param_1;
  if (*DAT_023363e8 == 0) {
    param_1 = 0;
  }
  _DAT_04000000 = param_3 * 8 | (uint)param_1 << 0x10 | _DAT_04000000 & DAT_023363ec | param_2;
  if (*DAT_023363e4 == 0) {
    *DAT_023363e8 = 0;
  }
  return;
}

