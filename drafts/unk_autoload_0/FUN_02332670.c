// decomp: module=unk_autoload_0 addr=0x02332670 name=FUN_02332670
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02332670 --addr 0x02332670 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332670(void)

{
  undefined4 *puVar1;
  
  FUN_023381f8();
  puVar1 = DAT_02332690;
  *DAT_02332690 = 0;
  puVar1[1] = 0;
  FUN_023382ac(0xe,DAT_02332694);
  DAT_02332690[2] = 0;
  return;
}

