// decomp: module=arm7 addr=0x022c8e0c name=FUN_022c8e0c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022c8e0c --addr 0x022c8e0c --size 0x3c --module arm7 --version 2.0/sp1


void FUN_022c8e0c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_022c8dec();
  if (iVar1 != 0) {
    FUN_022c8d88(iVar1,param_1,0xffffffff);
    FUN_022c8dcc(iVar1);
    iVar1 = (uint)*(byte *)(param_1 + 8 + param_2) * 0x40;
    *(byte *)(DAT_022c8e44 + iVar1) = *(byte *)(DAT_022c8e44 + iVar1) & 0xfe;
    *(undefined1 *)(param_1 + 8 + param_2) = 0xff;
  }
  return;
}

