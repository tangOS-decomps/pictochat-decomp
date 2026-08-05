// decomp: module=arm7 addr=0x022dee74 name=FUN_022dee74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb0 (Ghidra's cache says 0xac - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022dee74 --addr 0x022dee74 --size 0xb0 --module arm7 --version 2.0/sp1


void FUN_022dee74(ushort *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = DAT_022def20;
  if ((*param_1 & 1) == 0) {
    uVar3 = FUN_022d991c();
    if (uVar3 != 0xff) {
      FUN_022ded7c();
    }
    if ((*(short *)(*DAT_022def20 + 0x32e) == 1) && (iVar2 = FUN_022d9ffc(uVar3), iVar2 == 0x40)) {
      FUN_022d9c60(uVar3 & 0xffff,0x20);
      FUN_022deb1c();
    }
  }
  else {
    uVar3 = 1;
    if (1 < *(ushort *)(*DAT_022def20 + 0x322)) {
      for (; uVar3 < *(ushort *)(*piVar1 + 0x322); uVar3 = uVar3 + 1) {
        FUN_022ded7c(uVar3);
      }
    }
  }
  return;
}

