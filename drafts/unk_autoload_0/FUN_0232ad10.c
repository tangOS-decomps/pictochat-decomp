// decomp: module=unk_autoload_0 addr=0x0232ad10 name=FUN_0232ad10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x32, thumb
// triage: noise=6 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232ad10 --addr 0x0232ad10 --size 0x32 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ad10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short local_10 [2];
  undefined4 uStack_c;
  
  if (*(short *)(param_1 + 0x10) != 0) {
    uStack_c = param_4;
    FUN_02337584(*(undefined4 *)(param_1 + 0xc),local_10,4);
    if (local_10[0] == 4) {
      FUN_0232ad44(*(undefined4 *)(param_1 + 0xc));
    }
    else if (local_10[0] != 5) {
      return;
    }
  }
  return;
}

