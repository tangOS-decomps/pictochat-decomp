// decomp: module=unk_autoload_0 addr=0x0232aabc name=FUN_0232aabc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232aabc --addr 0x0232aabc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232aabc(void)

{
  if (*(int *)(DAT_0232aad4 + 0x54) != 0) {
    FUN_02331ef0(DAT_0232aad8);
    *(undefined4 *)(DAT_0232aad4 + 0x54) = 0;
  }
  return;
}

