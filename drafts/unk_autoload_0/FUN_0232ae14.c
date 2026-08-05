// decomp: module=unk_autoload_0 addr=0x0232ae14 name=FUN_0232ae14
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=42  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ae14 --addr 0x0232ae14 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ae14(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = FUN_0232981c();
  if (iVar2 != 0) {
    FUN_0232aabc();
    return;
  }
  if (((*(short *)(param_1 + 2) != 0) || (*(short *)(param_1 + 8) != 9)) ||
     (*(int *)(DAT_0232ae84 + 0x30) == 0)) {
    if (*(short *)(param_1 + 2) == 0) {
      uVar1 = *(ushort *)(param_1 + 8);
      if (7 < uVar1) {
        if (uVar1 == 9) {
          FUN_0232ac1c(param_1);
          return;
        }
        return;
      }
      if (6 < uVar1) {
        FUN_0232abc0(param_1);
        return;
      }
      if (uVar1 < 3) {
        if (uVar1 == 0) {
          FUN_0232aadc(param_1);
          return;
        }
        if (uVar1 == 2) {
          FUN_0232ab40(param_1);
          return;
        }
        return;
      }
    }
    else {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

