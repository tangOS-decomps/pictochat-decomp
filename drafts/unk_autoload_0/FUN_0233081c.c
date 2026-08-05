// decomp: module=unk_autoload_0 addr=0x0233081c name=FUN_0233081c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0233081c --addr 0x0233081c --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0233081c(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar2 = DAT_02330838;
  uVar1 = *DAT_02330838;
  puVar4 = (undefined4 *)(DAT_02330838 + 6);
  *DAT_02330838 = 0;
  uVar3 = *puVar4;
  *puVar4 = param_1;
  *puVar2 = uVar1;
  return uVar3;
}

