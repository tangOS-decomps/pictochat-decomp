// decomp: module=arm7 addr=0x022d6e98 name=FUN_022d6e98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d6e98 --addr 0x022d6e98 --size 0x60 --module arm7 --version 2.0/sp1


undefined4 FUN_022d6e98(ushort *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 & 1) == 0) {
    FUN_022d811c((ushort *)(*DAT_022d6ef0 + 0x324),param_1);
    FUN_022d811c(DAT_022d6ef4,param_1);
    uVar1 = 0;
    *(uint *)(*DAT_022d6ef0 + 0x340) = *(uint *)(*DAT_022d6ef0 + 0x340) | 2;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

