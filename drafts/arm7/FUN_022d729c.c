// decomp: module=arm7 addr=0x022d729c name=FUN_022d729c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022d729c --addr 0x022d729c --size 0x30 --module arm7 --version 2.0/sp1


undefined4 FUN_022d729c(undefined2 *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  
  uVar1 = 0;
  puVar2 = (undefined2 *)(*DAT_022d72c8 + 900);
  do {
    uVar1 = uVar1 + 1;
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x10);
  return 0;
}

