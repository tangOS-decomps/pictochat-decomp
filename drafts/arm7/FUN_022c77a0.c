// decomp: module=arm7 addr=0x022c77a0 name=FUN_022c77a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c77a0 --addr 0x022c77a0 --size 0x28 --module arm7 --version 2.0/sp1


void FUN_022c77a0(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 * 0x10 + DAT_022c77c0) & DAT_022c77c4;
  if ((param_2 & 1) != 0) {
    uVar1 = uVar1 | 0x8000;
  }
  *(uint *)(param_1 * 0x10 + DAT_022c77c0) = uVar1;
  return;
}

