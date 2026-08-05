// decomp: module=unk_autoload_0 addr=0x02321db4 name=FUN_02321db4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02321db4 --addr 0x02321db4 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321db4(void)

{
  undefined4 uVar1;
  
  *DAT_02321dec = *DAT_02321dec & 0x43 | 0x810;
  uVar1 = FUN_023215c8();
  FUN_0233746c(DAT_02321df0,uVar1,0x600);
  uVar1 = FUN_023215c8();
  FUN_023314e8(uVar1,0x600);
  FUN_02321568(8);
  return;
}

