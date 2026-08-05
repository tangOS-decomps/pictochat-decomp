// decomp: module=unk_autoload_0 addr=0x0232b0d0 name=FUN_0232b0d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232b0d0 --addr 0x0232b0d0 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b0d0(void)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if (iVar1 == 0) {
    FUN_0232b9e4();
    FUN_0232c0c4();
    iVar1 = DAT_0232b11c;
    *(undefined4 *)(DAT_0232b11c + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    iVar1 = FUN_0232cf20(DAT_0232b120,*(undefined4 *)(iVar1 + 0x18),*(undefined2 *)(iVar1 + 2),
                         *(undefined4 *)(iVar1 + 0x28),*(undefined2 *)(iVar1 + 10),4,4,1,1,1,0);
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

