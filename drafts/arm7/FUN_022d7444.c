// decomp: module=arm7 addr=0x022d7444 name=FUN_022d7444
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd4 (Ghidra's cache says 0xcc - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022d7444 --addr 0x022d7444 --size 0xd4 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7444(uint param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = param_1;
  if (param_1 < 2) {
    uVar1 = param_2;
  }
  if (1 < uVar1) {
    return 5;
  }
  if (param_1 == 0) {
    *(ushort *)(*DAT_022d7510 + 0x33a) =
         *(ushort *)(*DAT_022d7510 + 0x33a) & 0xffdf | (ushort)((param_2 << 0x1f) >> 0x1a);
  }
  else if (param_1 == 1) {
    iVar3 = *DAT_022d7510;
    if (*(short *)(iVar3 + 0x32e) != 1) {
      return 0xb;
    }
    *(ushort *)(iVar3 + 0x33a) = *(ushort *)(iVar3 + 0x33a) & 0xffdf;
  }
  piVar2 = DAT_022d7510;
  *(ushort *)(*DAT_022d7510 + 0x33a) =
       *(ushort *)(*DAT_022d7510 + 0x33a) & 0xffef | (ushort)((param_1 << 0x1f) >> 0x1b);
  *DAT_022d7514 =
       (ushort)((ushort)(((uint)*(ushort *)(*piVar2 + 0x33a) << 0x1c) >> 0x10) ^
               (ushort)(((uint)*(ushort *)(*piVar2 + 0x33a) << 0x1a) >> 0x10)) >> 0xf;
  return 0;
}

