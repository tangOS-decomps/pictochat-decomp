// decomp: module=unk_autoload_0 addr=0x02332e38 name=FUN_02332e38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02332e38 --addr 0x02332e38 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02332e38(byte *param_1,byte *param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    if (*param_1 != *param_2) break;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  if (*param_2 <= *param_1) {
    return 1;
  }
  return 0xffffffff;
}

