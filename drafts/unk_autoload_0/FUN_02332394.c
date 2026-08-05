// decomp: module=unk_autoload_0 addr=0x02332394 name=FUN_02332394
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02332394 --addr 0x02332394 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332394(void)

{
  undefined4 uVar1;
  undefined4 in_r3;
  
  uVar1 = DAT_023323bc;
  *DAT_023323b8 = DAT_023323bc;
  FUN_0233746c(0,uVar1,0x60,in_r3,in_r3);
  FUN_02331504(DAT_023323bc,0x60);
  FUN_023382ac(0xb,DAT_023323c0);
  return;
}

