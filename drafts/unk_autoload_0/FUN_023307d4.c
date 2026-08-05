// decomp: module=unk_autoload_0 addr=0x023307d4 name=FUN_023307d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023307d4 --addr 0x023307d4 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


uint FUN_023307d4(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar2 = DAT_023307f4;
  uVar1 = *DAT_023307f4;
  puVar4 = (uint *)(DAT_023307f4 + 4);
  *DAT_023307f4 = 0;
  uVar3 = *puVar4;
  *puVar4 = param_1 | uVar3;
  *puVar2 = uVar1;
  return uVar3;
}

