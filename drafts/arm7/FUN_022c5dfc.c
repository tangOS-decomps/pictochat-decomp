// decomp: module=arm7 addr=0x022c5dfc name=FUN_022c5dfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=11
// verify:  python tools/match.py --c <file> --func FUN_022c5dfc --addr 0x022c5dfc --size 0x34 --module arm7 --version 2.0/sp1


undefined4 FUN_022c5dfc(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_022c6d40();
  puVar1 = *(undefined4 **)(DAT_022c5e2c + param_1 * 4);
  uVar2 = *puVar1;
  *puVar1 = param_2;
  FUN_022c6d54();
  return uVar2;
}

