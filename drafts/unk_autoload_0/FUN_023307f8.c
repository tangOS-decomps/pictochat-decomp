// decomp: module=unk_autoload_0 addr=0x023307f8 name=FUN_023307f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023307f8 --addr 0x023307f8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


uint FUN_023307f8(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar2 = DAT_02330818;
  uVar1 = *DAT_02330818;
  puVar4 = (uint *)(DAT_02330818 + 4);
  *DAT_02330818 = 0;
  uVar3 = *puVar4;
  *puVar4 = ~param_1 & uVar3;
  *puVar2 = uVar1;
  return uVar3;
}

