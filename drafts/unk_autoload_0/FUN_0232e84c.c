// decomp: module=unk_autoload_0 addr=0x0232e84c name=FUN_0232e84c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232e84c --addr 0x0232e84c --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e84c(uint param_1)

{
  if ((param_1 & *DAT_0232e864) != 0) {
    return 0;
  }
  *DAT_0232e864 = param_1 | *DAT_0232e864;
  return 1;
}

