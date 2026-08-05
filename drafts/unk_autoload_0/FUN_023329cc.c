// decomp: module=unk_autoload_0 addr=0x023329cc name=FUN_023329cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=22
// verify:  python tools/match.py --c <file> --func FUN_023329cc --addr 0x023329cc --size 0x78 --module unk_autoload_0 --version 2.0/sp1


void FUN_023329cc(void)

{
  int iVar1;
  
  if (*(int *)(DAT_02332a30 + 8) == 0) {
    *(undefined4 *)(DAT_02332a30 + 8) = 1;
    FUN_02332788();
    *(undefined4 *)(DAT_02332a30 + 0xc) = 0;
    FUN_023381f8();
    do {
      iVar1 = FUN_023382f8(0xd,1);
    } while (iVar1 == 0);
    FUN_023382ac(0xd,DAT_02332a34);
    FUN_02332a44();
    FUN_023382ac(0xd,0);
    FUN_023382ac(0xd,DAT_02332a38);
    *(undefined4 *)(DAT_02332a30 + 0x18) = 0;
    FUN_02332c04(DAT_02332a3c);
    FUN_023382ac(0x11,DAT_02332a40);
    FUN_02332964(0);
  }
  return;
}

