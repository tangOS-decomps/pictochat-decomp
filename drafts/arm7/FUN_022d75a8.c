// decomp: module=arm7 addr=0x022d75a8 name=FUN_022d75a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022d75a8 --addr 0x022d75a8 --size 0x64 --module arm7 --version 2.0/sp1


undefined4 FUN_022d75a8(ushort *param_1)

{
  FUN_022d811c((ushort *)(*DAT_022d7600 + 0x3a8),param_1);
  FUN_022d811c(DAT_022d7604,param_1);
  if ((*param_1 & 1) == 0) {
    *DAT_022d7608 = *DAT_022d7608 | 0x400;
  }
  else {
    *DAT_022d7608 = *DAT_022d7608 & 0xfbff;
  }
  return 0;
}

