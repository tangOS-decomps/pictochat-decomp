// decomp: module=unk_autoload_0 addr=0x0232c85c name=FUN_0232c85c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=13  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232c85c --addr 0x0232c85c --size 0x28 --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232c85c(void)

{
  uint uVar1;
  
  FUN_02332080();
  if (*(int *)(DAT_0232c880 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(*(int *)(DAT_0232c880 + 4) + 0x14c);
  }
  FUN_02332094();
  return uVar1 & 0xffff;
}

