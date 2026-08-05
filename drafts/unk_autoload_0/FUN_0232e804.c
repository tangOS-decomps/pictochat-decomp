// decomp: module=unk_autoload_0 addr=0x0232e804 name=FUN_0232e804
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232e804 --addr 0x0232e804 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e804(uint param_1)

{
  if (param_1 == 0) {
    return 1;
  }
  if ((*(uint *)(DAT_0232e82c + 8) & param_1) != 0) {
    return 0;
  }
  FUN_02337818(param_1,0);
  *(uint *)(DAT_0232e82c + 8) = *(uint *)(DAT_0232e82c + 8) | param_1;
  return 1;
}

