// decomp: module=unk_autoload_0 addr=0x023366c0 name=FUN_023366c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=6
// verify:  python tools/match.py --c <file> --func FUN_023366c0 --addr 0x023366c0 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * FUN_023366c0(void)

{
  return (void *)(((int)(*DAT_023366e4 & 0x3c) >> 2) * 0x4000 +
                 ((*(uint *)(DAT_023366e4 + -4) & 0x7000000) >> 0x18) * 0x10000 + 0x6000000);
}

