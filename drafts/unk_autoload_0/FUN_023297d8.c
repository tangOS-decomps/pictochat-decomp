// decomp: module=unk_autoload_0 addr=0x023297d8 name=FUN_023297d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2a, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023297d8 --addr 0x023297d8 --size 0x2a --module unk_autoload_0 --version 2.0/sp1


void FUN_023297d8(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 != 0xb) {
    FUN_0232a428();
    FUN_023298d8(1);
    iVar1 = FUN_0232996c();
    if (iVar1 != 0) {
      FUN_0232987c();
      do {
        iVar1 = FUN_0232996c();
      } while (iVar1 != 0xb);
    }
  }
  return;
}

