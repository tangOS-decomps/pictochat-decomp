// decomp: module=unk_autoload_0 addr=0x0232571c name=FUN_0232571c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e, thumb
// triage: noise=8 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232571c --addr 0x0232571c --size 0x3e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232571c(int param_1)

{
  int iVar1;
  
  FUN_0233746c(0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x44));
  FUN_0233746c(0,*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x44));
  FUN_0233746c(0,*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44));
  FUN_0233746c(0,*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x44));
  iVar1 = FUN_02327990();
  FUN_02325910(param_1,iVar1 + 5,1);
  return;
}

