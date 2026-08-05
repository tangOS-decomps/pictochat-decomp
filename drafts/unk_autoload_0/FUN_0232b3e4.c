// decomp: module=unk_autoload_0 addr=0x0232b3e4 name=FUN_0232b3e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232b3e4 --addr 0x0232b3e4 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b3e4(byte *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_02331ffc(*param_1 + 0x80);
  if ((code *)*DAT_0232b40c != (code *)0x0) {
    (*(code *)*DAT_0232b40c)(*(undefined4 *)(param_1 + 4));
    (*(code *)*DAT_0232b40c)(*(undefined4 *)(param_1 + 8));
  }
  return;
}

