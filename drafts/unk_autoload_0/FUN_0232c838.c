// decomp: module=unk_autoload_0 addr=0x0232c838 name=FUN_0232c838
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232c838 --addr 0x0232c838 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232c838(void)

{
  undefined2 uVar1;
  
  FUN_02332080();
  if (*(int *)(DAT_0232c858 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined2 *)(*(int *)(DAT_0232c858 + 4) + 0x150);
  }
  FUN_02332094();
  return uVar1;
}

