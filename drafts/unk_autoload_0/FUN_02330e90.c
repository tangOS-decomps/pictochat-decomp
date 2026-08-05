// decomp: module=unk_autoload_0 addr=0x02330e90 name=FUN_02330e90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x32 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02330e90 --addr 0x02330e90 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02330e90(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(DAT_02330ec4 + 0x14) != 0) {
    FUN_023310dc(param_1,DAT_02330ec8,*(int *)(DAT_02330ec4 + 0x14),param_4,param_4);
    param_1[1] = param_2;
    *param_1 = *param_1 | 0x80;
    param_1[0x19] = 1;
    FUN_02331194(param_1);
    return;
  }
  FUN_02330ecc(param_2);
  return;
}

