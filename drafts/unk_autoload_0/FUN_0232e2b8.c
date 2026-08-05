// decomp: module=unk_autoload_0 addr=0x0232e2b8 name=FUN_0232e2b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1a, thumb
// triage: noise=7 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232e2b8 --addr 0x0232e2b8 --size 0x1a --module unk_autoload_0 --version 2.0/sp1


undefined2 * FUN_0232e2b8(undefined4 *param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)*param_1;
  *puVar1 = param_2;
  puVar1[1] = 0;
  *(int *)(puVar1 + 2) = param_1[1] - (int)(puVar1 + 8);
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  return puVar1;
}

