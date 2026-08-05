// decomp: module=unk_autoload_0 addr=0x0232ac60 name=FUN_0232ac60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=6 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232ac60 --addr 0x0232ac60 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ac60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short local_10 [2];
  undefined4 uStack_c;
  
  if (*(short *)(param_1 + 0x10) != 0) {
    uStack_c = param_4;
    FUN_02337584(*(undefined4 *)(param_1 + 0xc),local_10,4);
    if (((local_10[0] != 4) && (local_10[0] != 5)) && (local_10[0] == 6)) {
      FUN_0232ac90(*(undefined4 *)(param_1 + 0xc));
    }
  }
  return;
}

