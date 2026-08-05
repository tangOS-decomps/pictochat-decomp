// decomp: module=unk_autoload_0 addr=0x0233731c name=FUN_0233731c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0233731c --addr 0x0233731c --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_0233731c(int param_1)

{
  undefined4 *puVar1;
  
  FUN_02332080();
  puVar1 = DAT_02337350;
  do {
  } while ((*(uint *)(param_1 * 0xc + DAT_0233734c) & 0x80000000) != 0);
  if (param_1 == 0) {
    *DAT_02337350 = 0;
    puVar1[1] = 0;
    puVar1[2] = DAT_02337354;
  }
  FUN_02332094();
  return;
}

