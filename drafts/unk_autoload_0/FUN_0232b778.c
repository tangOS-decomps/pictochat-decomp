// decomp: module=unk_autoload_0 addr=0x0232b778 name=FUN_0232b778
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=8
// verify:  python tools/match.py --c <file> --func FUN_0232b778 --addr 0x0232b778 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b778(undefined4 *param_1)

{
  if ((code *)*DAT_0232b790 != (code *)0x0) {
    (*(code *)*DAT_0232b790)(*param_1);
  }
  *param_1 = 0;
  return;
}

