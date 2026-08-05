// decomp: module=arm7 addr=0x022c5504 name=FUN_022c5504
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c5504 --addr 0x022c5504 --size 0x2c --module arm7 --version 2.0/sp1


undefined4 FUN_022c5504(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_022c6d40();
  uVar1 = *(undefined4 *)(DAT_022c552c + 0x28);
  *(undefined4 *)(DAT_022c552c + 0x28) = param_1;
  FUN_022c6d54();
  return uVar1;
}

