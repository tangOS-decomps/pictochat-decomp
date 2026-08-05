// decomp: module=unk_autoload_0 addr=0x0232a620 name=FUN_0232a620
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232a620 --addr 0x0232a620 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a620(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 == 1) {
    FUN_02329bd8(5);
    *(undefined4 *)(DAT_0232a644 + 0x48) = param_2;
    FUN_0232af28(param_1 + 0x20);
  }
  return;
}

