// decomp: module=unk_autoload_0 addr=0x02337e54 name=FUN_02337e54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337e54 --addr 0x02337e54 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337e54(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_02337e64 + param_1 * 0xc;
  *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + '\x01';
  return;
}

