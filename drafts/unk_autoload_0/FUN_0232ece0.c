// decomp: module=unk_autoload_0 addr=0x0232ece0 name=FUN_0232ece0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, thumb
// triage: noise=7 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232ece0 --addr 0x0232ece0 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ece0(int param_1)

{
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined1 *)(param_1 + 0x2f) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x3e) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0x7f;
  *(undefined1 *)(param_1 + 0x41) = 0x7f;
  FUN_02330584((char *)(param_1 + 0x1c));
  FUN_02330590(param_1 + 0x1c,0x7f00,1);
  return;
}

