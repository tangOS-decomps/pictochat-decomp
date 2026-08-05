// decomp: module=unk_autoload_0 addr=0x0232b6b0 name=FUN_0232b6b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28, thumb
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232b6b0 --addr 0x0232b6b0 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b6b0(uchar *param_1)

{
  FUN_0232b6a4(param_1);
  param_1[1] = '\0';
  FUN_0233746c(0,*(undefined4 *)(param_1 + 4),(uint)param_1[2] * 0xe0);
  FUN_023314e8(*(undefined4 *)(param_1 + 4),(uint)param_1[2] * 0xe0);
  return;
}

