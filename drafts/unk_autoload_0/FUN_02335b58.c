// decomp: module=unk_autoload_0 addr=0x02335b58 name=FUN_02335b58
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c, arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02335b58 --addr 0x02335b58 --size 0x8c --module unk_autoload_0 --version 2.0/sp1


bool FUN_02335b58(int param_1,uint param_2,int param_3,uint param_4)

{
  if (((0xffdfffff < param_2 * 2) && ((param_2 * 2 != 0xffe00000 || (param_1 != 0)))) ||
     ((0xffdfffff < param_4 * 2 && (((param_4 & 0x7fffffff) != 0x7ff00000 || (param_3 != 0)))))) {
    return false;
  }
  if (-1 < (int)(param_4 | param_2)) {
    return param_2 == param_4 && param_1 == param_3;
  }
  if ((param_1 == 0 && ((param_4 | param_2) & 0x7fffffff) == 0) && param_3 == 0) {
    return true;
  }
  return param_4 == param_2 && param_3 == param_1;
}

