// decomp: module=unk_autoload_0 addr=0x02325c2c name=FUN_02325c2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02325c2c --addr 0x02325c2c --size 0x1e --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02325c2c(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + 3 >> 2;
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  }
  return 0;
}

