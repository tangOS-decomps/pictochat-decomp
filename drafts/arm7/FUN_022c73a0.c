// decomp: module=arm7 addr=0x022c73a0 name=FUN_022c73a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022c73a0 --addr 0x022c73a0 --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022c73a0(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = thunk_EXT_FUN_037fe7d0();
  *(int *)(DAT_022c73e8 + param_1 * 4) = param_2;
  if (param_2 == 0) {
    *(uint *)(DAT_022c73ec + 0x38c) = *(uint *)(DAT_022c73ec + 0x38c) & ~(1 << (param_1 & 0xff));
  }
  else {
    *(uint *)(DAT_022c73ec + 0x38c) = 1 << (param_1 & 0xff) | *(uint *)(DAT_022c73ec + 0x38c);
  }
  thunk_EXT_FUN_037fe7e4(uVar1);
  return;
}

