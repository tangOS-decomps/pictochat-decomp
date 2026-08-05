// decomp: module=unk_autoload_0 addr=0x02329600 name=FUN_02329600
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02329600 --addr 0x02329600 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329600(void)

{
  byte bVar1;
  
  bVar1 = DAT_02329624[1];
  FUN_02332080();
  if (bVar1 < *DAT_02329624) {
    bVar1 = bVar1 + 6;
  }
  DAT_02329624[3] = bVar1 - *DAT_02329624;
  FUN_02332094();
  return;
}

