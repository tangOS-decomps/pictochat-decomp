// decomp: module=unk_autoload_0 addr=0x0232e6cc name=FUN_0232e6cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a, thumb
// triage: noise=4 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232e6cc --addr 0x0232e6cc --size 0x1a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e6cc(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_1 + 0x1c);
  }
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  return;
}

