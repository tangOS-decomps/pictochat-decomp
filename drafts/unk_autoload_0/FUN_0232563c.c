// decomp: module=unk_autoload_0 addr=0x0232563c name=FUN_0232563c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18, thumb
// triage: noise=4 statements=6
// verify:  python tools/match.py --c <file> --func FUN_0232563c --addr 0x0232563c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232563c(int param_1)

{
  FUN_023314e8(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44));
  FUN_02336c60(*(undefined4 *)(param_1 + 0x40),0,*(undefined4 *)(param_1 + 0x44));
  return;
}

