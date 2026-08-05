// decomp: module=unk_autoload_0 addr=0x02332408 name=FUN_02332408
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02332408 --addr 0x02332408 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02332408(code *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_02332454;
  if (param_2 != 0) {
    FUN_02330ffc(DAT_02332454 + 10,DAT_02332454[2]);
    *(code **)((int)puVar1 + DAT_02332458) = param_1;
    puVar1[1] = puVar1[1] | 8;
    FUN_02330fb4(puVar1 + 10);
    return 1;
  }
  (*param_1)(DAT_02332454);
  FUN_02332494(puVar1);
  if (*(int *)*puVar1 != 0) {
    return 0;
  }
  return 1;
}

