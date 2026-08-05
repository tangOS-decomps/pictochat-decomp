// decomp: module=arm7 addr=0x022da6a0 name=FUN_022da6a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=16
// verify:  python tools/match.py --c <file> --func FUN_022da6a0 --addr 0x022da6a0 --size 0x60 --module arm7 --version 2.0/sp1


void FUN_022da6a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_022da6fc;
  iVar2 = *DAT_022da6fc;
  iVar3 = *(int *)(iVar2 + 500);
  while ((iVar3 != -1 &&
         (iVar2 = func_0x037c9e90(*(undefined4 *)(iVar2 + 0x304),iVar3,0), iVar2 != 0))) {
    func_0x037c583c(*piVar1 + 500,iVar3);
    iVar2 = *piVar1;
    iVar3 = *(int *)(iVar2 + 500);
  }
  return;
}

