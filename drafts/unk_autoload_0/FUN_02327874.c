// decomp: module=unk_autoload_0 addr=0x02327874 name=FUN_02327874
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02327874 --addr 0x02327874 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_02327874(void)

{
  FUN_02322db4();
  FUN_023374f0(PTR_DAT_02327898,0,0x1a);
  FUN_0233746c(0,PTR_DAT_0232789c,0x14);
  FUN_0232e980((int *)PTR_DAT_0232789c);
  return;
}

