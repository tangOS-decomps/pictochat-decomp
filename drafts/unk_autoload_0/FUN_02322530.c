// decomp: module=unk_autoload_0 addr=0x02322530 name=FUN_02322530
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02322530 --addr 0x02322530 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02322530(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02322548;
  *DAT_02322548 = 0;
  puVar1[1] = 0;
  *puVar1 = 0x600;
  return;
}

