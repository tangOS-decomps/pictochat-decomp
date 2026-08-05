// decomp: module=arm7 addr=0x022cdca8 name=FUN_022cdca8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3a, thumb
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022cdca8 --addr 0x022cdca8 --size 0x3a --module arm7 --version 2.0/sp1


void FUN_022cdca8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  thunk_EXT_FUN_02300fa0();
  thunk_EXT_FUN_02301014(param_1,param_2);
  if (param_1 == 6) {
    thunk_EXT_FUN_02301084(param_3,param_4);
  }
  else if (param_1 == 0x86) {
    thunk_EXT_FUN_02301114(param_3,param_4);
  }
  thunk_EXT_FUN_02300fe0();
  return;
}

