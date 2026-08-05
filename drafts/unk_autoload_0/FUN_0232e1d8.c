// decomp: module=unk_autoload_0 addr=0x0232e1d8 name=FUN_0232e1d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232e1d8 --addr 0x0232e1d8 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e1d8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0232e1f0;
  iVar1 = FUN_0232e198(DAT_0232e1f0,param_1);
  if (iVar1 != 0) {
    iVar2 = iVar1 + 0xc;
  }
  return iVar2;
}

