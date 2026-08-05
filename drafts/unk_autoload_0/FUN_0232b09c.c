// decomp: module=unk_autoload_0 addr=0x0232b09c name=FUN_0232b09c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232b09c --addr 0x0232b09c --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b09c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232981c();
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 2) == 0) {
      if (*(int *)(DAT_0232b0cc + 0x1c) != 0) {
        FUN_0232b0d0();
        return;
      }
    }
    else if (*(int *)(DAT_0232b0cc + 0x1c) != 0) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

