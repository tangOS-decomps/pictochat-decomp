// decomp: module=arm7 addr=0x022c2fd0 name=FUN_022c2fd0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c2fd0 --addr 0x022c2fd0 --size 0x4c --module arm7 --version 2.0/sp1


void FUN_022c2fd0(void)

{
  if (*(short *)(*DAT_022c3018 + 1000) != 0) {
    func_0x00ddadb4();
  }
  if ((int)((uint)*(ushort *)(*DAT_022c3018 + 0x33a) << 0x19) < 0) {
    func_0x00dd7770();
  }
  return;
}

