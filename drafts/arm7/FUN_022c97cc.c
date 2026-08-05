// decomp: module=arm7 addr=0x022c97cc name=FUN_022c97cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x52, thumb
// triage: noise=2 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022c97cc --addr 0x022c97cc --size 0x52 --module arm7 --version 2.0/sp1


void FUN_022c97cc(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  case 0:
    *param_1 = *param_1 & 0xfb;
    break;
  case 1:
    *param_1 = *param_1 | 4;
    break;
  case 2:
    *param_1 = *param_1 | 4;
    FUN_022c8d88(param_1,param_2,0xffffffff);
    break;
  case 3:
    *param_1 = *param_1 | 4;
    FUN_022c8d88(param_1,param_2,0x7f);
    FUN_022c8dcc(param_1);
  }
  return;
}

