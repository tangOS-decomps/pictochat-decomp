// decomp: module=arm7 addr=0x022c9764 name=FUN_022c9764
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c9764 --addr 0x022c9764 --size 0x34 --module arm7 --version 2.0/sp1


int FUN_022c9764(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *DAT_022c9794;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_2 < 0x10) {
    return iVar1 + 0x20 + (uint)*(byte *)(param_1 + 1) * 0x24 + param_2 * 2;
  }
  return iVar1 + 0x260 + (param_2 + -0x10) * 2;
}

