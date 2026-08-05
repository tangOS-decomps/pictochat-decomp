// decomp: module=unk_autoload_0 addr=0x02339034 name=FUN_02339034
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02339034 --addr 0x02339034 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339034(void)

{
  FUN_02332080();
  if (*(int *)(DAT_02339058 + 0x2c) != 0) {
    FUN_02332094();
    return 0;
  }
  *(undefined4 *)(DAT_02339058 + 0x2c) = 1;
  FUN_02332094();
  return 1;
}

