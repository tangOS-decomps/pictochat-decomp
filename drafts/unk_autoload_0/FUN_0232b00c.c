// decomp: module=unk_autoload_0 addr=0x0232b00c name=FUN_0232b00c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232b00c --addr 0x0232b00c --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b00c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if ((iVar1 == 0) && (iVar1 = FUN_0232cd94(DAT_0232b02c,param_1), iVar1 != 2)) {
    FUN_02329bd8(0xc);
  }
  return;
}

