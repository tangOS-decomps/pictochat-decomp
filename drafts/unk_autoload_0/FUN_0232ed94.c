// decomp: module=unk_autoload_0 addr=0x0232ed94 name=FUN_0232ed94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232ed94 --addr 0x0232ed94 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_0232ed94(int p)

{
  if (*(char *)(p + 0x2c) == '\x02') {
    FUN_02337710((uint)*(byte *)(p + 0x3c),DAT_0232edc0);
  }
  FUN_023376cc((uint)*(byte *)(p + 0x3c));
  FUN_0232ee10(p);
  return;
}

