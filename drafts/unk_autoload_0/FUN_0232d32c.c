// decomp: module=unk_autoload_0 addr=0x0232d32c name=FUN_0232d32c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232d32c --addr 0x0232d32c --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d32c(void)

{
  undefined1 auStack_c [12];
  
  FUN_02338df8(auStack_c,*(undefined2 *)(DAT_0232d368 + -5),*(undefined2 *)(DAT_0232d368 + -3),
               DAT_0232d368[-1],*DAT_0232d368,*(undefined2 *)(DAT_0232d368 + 1),
               *(undefined2 *)(DAT_0232d368 + 3),DAT_0232d368[5],DAT_0232d368[6]);
  FUN_02338cbc(auStack_c);
  return;
}

