// decomp: module=unk_autoload_0 addr=0x0232a0b8 name=FUN_0232a0b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232a0b8 --addr 0x0232a0b8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a0b8(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if (iVar1 == 0) {
    FUN_02329e9c();
    iVar1 = FUN_0232cc64(DAT_0232a0e0,*(undefined4 *)(DAT_0232a0dc + 0x18));
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

