// decomp: module=unk_autoload_0 addr=0x02336310 name=FUN_02336310
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02336310 --addr 0x02336310 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


ushort FUN_02336310(int param_1)

{
  ushort uVar1;
  
  uVar1 = *DAT_02336330;
  if (param_1 == 0) {
    *DAT_02336330 = *DAT_02336330 & 0xfff7;
  }
  else {
    *DAT_02336330 = *DAT_02336330 | 8;
  }
  return uVar1 & 8;
}

