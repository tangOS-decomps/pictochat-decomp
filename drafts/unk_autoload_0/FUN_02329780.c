// decomp: module=unk_autoload_0 addr=0x02329780 name=FUN_02329780
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x52 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02329780 --addr 0x02329780 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329780(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_023297d4 + 8) = 0;
  iVar1 = FUN_0232996c();
  if ((iVar1 != 1) &&
     ((iVar1 = FUN_0232996c(), iVar1 < 0xc || (iVar1 = FUN_0232996c(), iVar1 == 0xe)))) {
    iVar1 = FUN_0232996c();
    if (iVar1 == 0xb) {
      FUN_023298a0();
      FUN_02329bd8(0);
      return;
    }
    iVar1 = FUN_0232996c();
    if ((iVar1 != 0) && (iVar1 = FUN_0232996c(), iVar1 < 0xc)) {
      *(undefined4 *)(DAT_023297d4 + 0x18) = 2;
    }
    return;
  }
  FUN_02329858();
  return;
}

