// decomp: module=unk_autoload_0 addr=0x023382ac name=FUN_023382ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_023382ac --addr 0x023382ac --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_023382ac(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02332080();
  *(int *)(DAT_023382f0 + param_1 * 4) = param_2;
  if (param_2 == 0) {
    *(uint *)(DAT_023382f4 + 0x388) = *(uint *)(DAT_023382f4 + 0x388) & ~(1 << (param_1 & 0xff));
  }
  else {
    *(uint *)(DAT_023382f4 + 0x388) = 1 << (param_1 & 0xff) | *(uint *)(DAT_023382f4 + 0x388);
  }
  FUN_02332094(uVar1);
  return;
}

