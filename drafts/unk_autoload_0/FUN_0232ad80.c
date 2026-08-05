// decomp: module=unk_autoload_0 addr=0x0232ad80 name=FUN_0232ad80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232ad80 --addr 0x0232ad80 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232ad80(void)

{
  if (*(int *)(DAT_0232ada4 + 0x40) != 0) {
    return 1;
  }
  if (*(int *)(DAT_0232ada4 + 0x30) != 0) {
    *(undefined4 *)(DAT_0232ada4 + 0x40) = 1;
    FUN_0232b1c0();
    return 1;
  }
  return 0;
}

