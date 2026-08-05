// decomp: module=unk_autoload_0 addr=0x023209c4 name=FUN_023209c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_023209c4 --addr 0x023209c4 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_023209c4(void)

{
  FUN_023301a0();
  FUN_0233016c(DAT_023209e4,0x1000,1);
  if (*(int *)(DAT_023209e8 + 8) == 0) {
    *(undefined4 *)(DAT_023209e8 + 8) = 1;
  }
  return;
}

