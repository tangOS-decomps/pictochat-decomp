// decomp: module=unk_autoload_0 addr=0x02329734 name=FUN_02329734
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02329734 --addr 0x02329734 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02329734(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_0232977c + 8) = 1;
  iVar1 = FUN_0232996c();
  if ((iVar1 != 1) &&
     ((iVar1 = FUN_0232996c(), iVar1 < 0xc || (iVar1 = FUN_0232996c(), iVar1 == 0xe)))) {
    iVar1 = FUN_0232996c();
    if ((iVar1 != 0) &&
       ((iVar1 = FUN_0232996c(), iVar1 != 0xb && (iVar1 = FUN_0232996c(), iVar1 < 0xc)))) {
      *(undefined4 *)(DAT_0232977c + 0x18) = 1;
    }
    return;
  }
  FUN_023298c0();
  return;
}

