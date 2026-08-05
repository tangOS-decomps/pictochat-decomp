// decomp: module=unk_autoload_0 addr=0x023300a0 name=FUN_023300a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_023300a0 --addr 0x023300a0 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_023300a0(undefined4 *param_1)

{
  if ((int)(param_1[0x46] << 0x1f) < 0) {
    FUN_023300ec();
    (*(code *)param_1[0x5c])(param_1);
    FUN_02330108(DAT_023300e0,param_1);
    if (*(int *)(DAT_023300e4 + 4) != 0) {
      FUN_02330108(*(int *)(DAT_023300e4 + 4) + DAT_023300e8,param_1);
    }
    FUN_02330004(param_1);
  }
  return;
}

