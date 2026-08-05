// decomp: module=unk_autoload_0 addr=0x02331b6c name=FUN_02331b6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02331b6c --addr 0x02331b6c --size 0x7c --module unk_autoload_0 --version 2.0/sp1


void FUN_02331b6c(void)

{
  if (*(int *)(DAT_02331bd0 + 8) == 0) {
    return;
  }
  FUN_023317a4();
  (*(code *)*DAT_02331be0)(DAT_02331bd8,*DAT_02331bdc);
  FUN_023317b4();
  return;
}

