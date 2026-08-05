// decomp: module=unk_autoload_0 addr=0x02328e1c name=FUN_02328e1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02328e1c --addr 0x02328e1c --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_02328e1c(void)

{
  undefined4 in_r3;
  
  FUN_023296d8(2,PTR_LAB_023230e0_1_02328e5c,PTR_LAB_023230f8_1_02328e60,in_r3,in_r3);
  FUN_0232b9cc(PTR_LAB_023293d0_1_02328e64);
  FUN_0233746c(0,PTR_DAT_02328e68,0x4000);
  *(undefined4 *)PTR_DAT_02328e6c = 0;
  FUN_0233746c(0,PTR_DAT_02328e70,0x580);
  FUN_023314e8(PTR_DAT_02328e70,0x580);
  FUN_02329524();
  return;
}

