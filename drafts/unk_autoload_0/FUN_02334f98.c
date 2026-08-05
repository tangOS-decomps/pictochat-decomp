// decomp: module=unk_autoload_0 addr=0x02334f98 name=FUN_02334f98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02334f98 --addr 0x02334f98 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02334f98(int param_1,uint param_2)

{
  if ((param_2 & DAT_02334fe0) == 0) {
    if (((DAT_02334fe4 & param_2) == 0) && (param_1 == 0)) {
      return 3;
    }
    return 5;
  }
  if ((param_2 & DAT_02334fe0) != DAT_02334fe0) {
    return 4;
  }
  if (((DAT_02334fe4 & param_2) == 0) && (param_1 == 0)) {
    return 2;
  }
  return 1;
}

