// decomp: module=unk_autoload_0 addr=0x02332884 name=FUN_02332884
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02332884 --addr 0x02332884 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332884(int *param_1)

{
  ushort *puVar1;
  
  puVar1 = DAT_023328b4;
  *param_1 = (int)(*DAT_023328b4 & 0xc) >> 2;
  param_1[1] = (int)(*puVar1 & 0x10) >> 4;
  *puVar1 = *puVar1 & 0xfff3 | 0xc;
  *puVar1 = *puVar1 & 0xffef;
  return;
}

