// decomp: module=unk_autoload_0 addr=0x02322870 name=FUN_02322870
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02322870 --addr 0x02322870 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


byte FUN_02322870(void)

{
  byte bVar1;
  
  bVar1 = *DAT_02322880 & 0xf;
  if (0xf < bVar1) {
    bVar1 = 1;
  }
  return bVar1;
}

