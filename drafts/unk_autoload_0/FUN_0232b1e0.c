// decomp: module=unk_autoload_0 addr=0x0232b1e0 name=FUN_0232b1e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=23  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232b1e0 --addr 0x0232b1e0 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b1e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232981c();
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 2) == 0) {
      if (*(int *)(DAT_0232b21c + 0x30) != 0) {
        if (*(short *)(DAT_0232b21c + 0xc) == 0) {
          FUN_0232ae88();
          return;
        }
        if (*(short *)(DAT_0232b21c + 0xc) != 0) {
          FUN_0232b00c(0);
          return;
        }
      }
    }
    else {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

