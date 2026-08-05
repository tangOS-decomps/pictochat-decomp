// decomp: module=unk_autoload_0 addr=0x0232a18c name=FUN_0232a18c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=25  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232a18c --addr 0x0232a18c --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a18c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0232981c();
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 2) == 0) {
      iVar1 = 0;
      FUN_02329bd8(1);
      if ((*(int *)(DAT_0232a1e0 + 0x10) != 0) &&
         (iVar2 = FUN_0232b68c((uchar *)(*(int *)(DAT_0232a1e0 + 0x30) +
                                        (uint)*(byte *)(DAT_0232a1e0 + 2) * 0x10)), 0 < iVar2)) {
        iVar1 = FUN_02329fac();
      }
      if ((*(int *)(DAT_0232a1e0 + 8) != 0) && (iVar1 == 0)) {
        FUN_0232a5f8(1);
        return;
      }
    }
    else {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

