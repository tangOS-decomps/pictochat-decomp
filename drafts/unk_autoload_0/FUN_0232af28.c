// decomp: module=unk_autoload_0 addr=0x0232af28 name=FUN_0232af28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232af28 --addr 0x0232af28 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232af28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_02329c00();
  if (iVar1 == 0) {
    iVar1 = FUN_0232cd10(DAT_0232af54,param_1,0,1,0,param_4);
    if (iVar1 != 2) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

