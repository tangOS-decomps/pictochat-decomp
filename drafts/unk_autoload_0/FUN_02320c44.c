// decomp: module=unk_autoload_0 addr=0x02320c44 name=FUN_02320c44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02320c44 --addr 0x02320c44 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320c44(void)

{
  undefined4 in_r3;
  
  if (*(int *)(PTR_DAT_02320c68 + 0x60) != 0) {
    FUN_023368c0(PTR_DAT_02320c6c,0,0x400,in_r3,in_r3);
    FUN_02336900(PTR_DAT_02320c70,0,0x400);
  }
  return;
}

