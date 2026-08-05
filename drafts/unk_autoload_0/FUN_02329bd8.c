// decomp: module=unk_autoload_0 addr=0x02329bd8 name=FUN_02329bd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02329bd8 --addr 0x02329bd8 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329bd8(int param_1)

{
  if ((*(int *)(DAT_02329bec + 0x14) < 0xc) || (param_1 == 0xe)) {
    *(int *)(DAT_02329bec + 0x14) = param_1;
  }
  return;
}

