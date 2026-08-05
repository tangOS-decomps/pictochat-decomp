// decomp: module=unk_autoload_0 addr=0x023393b0 name=FUN_023393b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=17
// verify:  python tools/match.py --c <file> --func FUN_023393b0 --addr 0x023393b0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


int FUN_023393b0(void)

{
  code *pcVar1;
  int iVar2;
  int in_r3;
  int local_8 [2];
  
  local_8[0] = in_r3;
  iVar2 = FUN_02339394(DAT_023393d0,local_8);
  pcVar1 = DAT_023393d4;
  if (iVar2 == 0) {
    *DAT_023393d8 = DAT_023393d4;
    (*pcVar1)();
    *DAT_023393d8 = DAT_023393dc;
    iVar2 = local_8[0];
  }
  return iVar2;
}

