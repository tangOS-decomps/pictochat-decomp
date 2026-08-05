// decomp: module=unk_autoload_0 addr=0x023307b4 name=FUN_023307b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023307b4 --addr 0x023307b4 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023307b4(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar2 = DAT_023307d0;
  uVar1 = *DAT_023307d0;
  puVar4 = (undefined4 *)(DAT_023307d0 + 4);
  *DAT_023307d0 = 0;
  uVar3 = *puVar4;
  *puVar4 = param_1;
  *puVar2 = uVar1;
  return uVar3;
}

