// decomp: module=unk_autoload_0 addr=0x0232ade8 name=FUN_0232ade8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_0232ade8 --addr 0x0232ade8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ade8(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if (iVar1 == 0) {
    *(undefined4 *)(DAT_0232ae0c + 0x58) = 0;
    iVar1 = DAT_0232ae10;
    FUN_0232cc30(DAT_0232ae10);
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

