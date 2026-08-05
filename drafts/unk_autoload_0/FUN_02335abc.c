// decomp: module=unk_autoload_0 addr=0x02335abc name=FUN_02335abc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c, arm
// triage: noise=2 statements=29
// verify:  python tools/match.py --c <file> --func FUN_02335abc --addr 0x02335abc --size 0x9c --module unk_autoload_0 --version 2.0/sp1


bool FUN_02335abc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  byte in_Q;
  
  if (((0xffdfffff < param_2 * 2) && ((param_2 * 2 != 0xffe00000 || (param_1 != 0)))) ||
     ((0xffdfffff < param_4 * 2 && (((param_4 & 0x7fffffff) != 0x7ff00000 || (param_3 != 0)))))) {
    return false;
  }
  if (-1 < (int)(param_4 | param_2)) {
    bVar2 = param_4 <= param_2;
    if (param_2 == param_4) {
      bVar2 = param_3 <= param_1;
    }
    return !bVar2;
  }
  bVar2 = param_1 == 0;
  bVar1 = ((param_4 | param_2) & 0x7fffffff) == 0;
  if (((bVar2 && bVar1) && param_3 == 0) &&
     (param_1 = 0, (((byte)(((bVar2 && bVar1) && param_3 == 0) << 3 | in_Q) & 0x1f) >> 3 & 1) != 0))
  {
    return false;
  }
  bVar2 = param_2 <= param_4;
  if (param_4 == param_2) {
    bVar2 = param_1 <= param_3;
  }
  return !bVar2;
}

