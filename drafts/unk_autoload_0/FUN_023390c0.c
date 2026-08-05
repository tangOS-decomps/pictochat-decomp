// decomp: module=unk_autoload_0 addr=0x023390c0 name=FUN_023390c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023390c0 --addr 0x023390c0 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_023390c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = DAT_023390d8;
  pcVar3 = *(code **)(DAT_023390d8 + 0x30);
  uVar2 = *(undefined4 *)(DAT_023390d8 + 0x34);
  *(undefined4 *)(DAT_023390d8 + 0x2c) = 0;
  if (pcVar3 != (code *)0x0) {
    *(undefined4 *)(iVar1 + 0x30) = 0;
    (*pcVar3)(param_1,uVar2);
  }
  return;
}

