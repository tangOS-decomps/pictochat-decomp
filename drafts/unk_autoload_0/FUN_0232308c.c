// decomp: module=unk_autoload_0 addr=0x0232308c name=FUN_0232308c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=10
// verify:  python tools/match.py --c <file> --func FUN_0232308c --addr 0x0232308c --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232308c(void)

{
  undefined4 uVar1;
  undefined4 in_r3;
  
  if (*(int *)(PTR_DAT_023230a8 + 4) == 0) {
    uVar1 = FUN_0232e5a0(PTR_DAT_023230ac,0x17c000,0,in_r3,in_r3);
    *(undefined4 *)(PTR_DAT_023230a8 + 4) = uVar1;
  }
  return;
}

