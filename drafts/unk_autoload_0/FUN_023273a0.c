// decomp: module=unk_autoload_0 addr=0x023273a0 name=FUN_023273a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x32 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=13
// verify:  python tools/match.py --c <file> --func FUN_023273a0 --addr 0x023273a0 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_023273a0(void)

{
  undefined4 in_r3;
  int iVar1;
  
  FUN_0233746c(0,PTR_DAT_023273d4,0x398,in_r3,in_r3);
  iVar1 = 0;
  do {
    FUN_023215d0();
    FUN_02321664();
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return;
}

