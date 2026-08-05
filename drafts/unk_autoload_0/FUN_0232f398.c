// decomp: module=unk_autoload_0 addr=0x0232f398 name=FUN_0232f398
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_0232f398 --addr 0x0232f398 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f398(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*DAT_0232f3d0 != 0) {
    if (DAT_0232f3d0[0xb] < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1 << (DAT_0232f3d0[0xb] & 0xffU);
    }
    FUN_02337784(DAT_0232f3d0[9],DAT_0232f3d0[10],iVar2,0);
    uVar1 = FUN_02337cac();
    FUN_02337b54(1);
    FUN_02337c68(uVar1);
  }
  return;
}

