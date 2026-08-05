// decomp: module=arm7 addr=0x022c67e8 name=FUN_022c67e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=38
// verify:  python tools/match.py --c <file> --func FUN_022c67e8 --addr 0x022c67e8 --size 0xa4 --module arm7 --version 2.0/sp1


void FUN_022c67e8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_022c6888;
  iVar2 = *(int *)(DAT_022c6888 + 0xc);
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = *(int *)(DAT_022c6888 + 0x10);
      *(int *)(param_1 + 0x14) = iVar2;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(int *)(iVar1 + 0x10) = param_1;
      if (iVar2 == 0) {
        *(int *)(iVar1 + 0xc) = param_1;
        FUN_022c69f8();
      }
      else {
        *(int *)(iVar2 + 0x18) = param_1;
      }
      return;
    }
    if ((*(uint *)(param_1 + 0xc) <= *(uint *)(iVar2 + 0xc)) &&
       ((*(uint *)(iVar2 + 0xc) != *(uint *)(param_1 + 0xc) ||
        (*(short *)(param_1 + 0x10) < *(short *)(iVar2 + 0x10))))) break;
    iVar2 = *(int *)(iVar2 + 0x18);
  }
  iVar1 = *(int *)(iVar2 + 0x14);
  *(int *)(param_1 + 0x14) = iVar1;
  *(int *)(param_1 + 0x18) = iVar2;
  *(int *)(iVar2 + 0x14) = param_1;
  if (iVar1 == 0) {
    *(int *)(DAT_022c6888 + 0xc) = param_1;
    FUN_022c69f8();
    return;
  }
  *(int *)(iVar1 + 0x18) = param_1;
  return;
}

