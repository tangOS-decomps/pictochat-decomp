// decomp: module=arm7 addr=0x022d80f8 name=FUN_022d80f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d80f8 --addr 0x022d80f8 --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022d80f8(void)

{
  if ((*DAT_022d8118 & 0x8000) == 0) {
    func_0x037c8430();
  }
  return;
}

