// decomp: module=unk_autoload_0 addr=0x02322cb8 name=FUN_02322cb8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02322cb8 --addr 0x02322cb8 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02322cb8(void)

{
  if (*DAT_02322ccc == -1) {
    return 1;
  }
  return 0;
}

