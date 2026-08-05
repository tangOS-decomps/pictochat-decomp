// decomp: module=unk_autoload_0 addr=0x0232a5f8 name=FUN_0232a5f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232a5f8 --addr 0x0232a5f8 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a5f8(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 == 1) {
    FUN_0232aabc();
    FUN_02329bd8(4);
    *(undefined4 *)(DAT_0232a61c + 0x2c) = param_1;
    FUN_0232a57c();
    FUN_0232ada8();
  }
  return;
}

