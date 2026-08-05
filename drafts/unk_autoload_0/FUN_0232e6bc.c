// decomp: module=unk_autoload_0 addr=0x0232e6bc name=FUN_0232e6bc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe, thumb
// triage: noise=3 statements=6
// verify:  python tools/match.py --c <file> --func FUN_0232e6bc --addr 0x0232e6bc --size 0xe --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e6bc(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

