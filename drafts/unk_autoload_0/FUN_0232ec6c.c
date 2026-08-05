// decomp: module=unk_autoload_0 addr=0x0232ec6c name=FUN_0232ec6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232ec6c --addr 0x0232ec6c --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ec6c(int param_1,int param_2)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x2c) != '\0')) {
    if (param_2 == 0) {
      FUN_0232ed94(param_1);
      return;
    }
    FUN_02330590(param_1 + 0x1c,0);
    FUN_0232ee98(param_1,0);
    *(undefined1 *)(param_1 + 0x2c) = 2;
  }
  return;
}

