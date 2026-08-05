// decomp: module=unk_autoload_0 addr=0x02322420 name=FUN_02322420
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02322420 --addr 0x02322420 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02322420(int param_1,int param_2)

{
  if (param_1 == *(int *)(DAT_02322434 + param_2 * 0x54)) {
    return 1;
  }
  return 0;
}

