// decomp: module=unk_autoload_0 addr=0x0232b8fc name=FUN_0232b8fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=14 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232b8fc --addr 0x0232b8fc --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b8fc(void)

{
  undefined4 in_r3;
  
  FUN_0232c8c0(0xd,0,0,in_r3,in_r3);
  FUN_0232c8c0(0xe,0,0);
  FUN_0232b778(DAT_0232b94c);
  FUN_0232b778(DAT_0232b950);
  if ((code *)*DAT_0232b954 != (code *)0x0) {
    (*(code *)*DAT_0232b954)(*(undefined4 *)(DAT_0232b958 + 0x10));
    (*(code *)*DAT_0232b954)(*(undefined4 *)(DAT_0232b958 + 0xc));
    (*(code *)*DAT_0232b954)(*(undefined4 *)(DAT_0232b958 + 0x34));
    (*(code *)*DAT_0232b954)(*(undefined4 *)(DAT_0232b958 + 0x30));
  }
  return;
}

