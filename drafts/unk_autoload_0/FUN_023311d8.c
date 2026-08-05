// decomp: module=unk_autoload_0 addr=0x023311d8 name=FUN_023311d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=10
// verify:  python tools/match.py --c <file> --func FUN_023311d8 --addr 0x023311d8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023311d8(void)

{
  uint uVar1;
  
  if (*(int *)(DAT_023311fc + 4) == -1) {
    *(undefined4 *)(DAT_023311fc + 4) = DAT_02331200;
    uVar1 = FUN_02331204();
    *(uint *)(DAT_023311fc + 4) = uVar1 | *(uint *)(DAT_023311fc + 4);
  }
  return *(undefined4 *)(DAT_023311fc + 4);
}

