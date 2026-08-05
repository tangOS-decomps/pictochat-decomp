// decomp: module=unk_autoload_0 addr=0x02332df4 name=FUN_02332df4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a, thumb
// triage: noise=3 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02332df4 --addr 0x02332df4 --size 0x1a --module unk_autoload_0 --version 2.0/sp1


void FUN_02332df4(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}

