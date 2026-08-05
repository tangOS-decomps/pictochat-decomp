// decomp: module=unk_autoload_0 addr=0x02337958 name=FUN_02337958
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337958 --addr 0x02337958 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337958(void)

{
  if (*DAT_02337978 == 0) {
    *DAT_02337978 = 1;
    FUN_02331368(DAT_0233797c);
    FUN_023379a0();
    FUN_02337e38();
  }
  return;
}

