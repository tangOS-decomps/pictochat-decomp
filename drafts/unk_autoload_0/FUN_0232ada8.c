// decomp: module=unk_autoload_0 addr=0x0232ada8 name=FUN_0232ada8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232ada8 --addr 0x0232ada8 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ada8(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if ((iVar1 == 0) &&
     (iVar1 = FUN_0232cb34(DAT_0232adcc,*(undefined4 *)(DAT_0232adc8 + 0x50)), iVar1 != 2)) {
    FUN_02329bd8(0xc);
  }
  return;
}

