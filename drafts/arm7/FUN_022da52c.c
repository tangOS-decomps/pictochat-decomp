// decomp: module=arm7 addr=0x022da52c name=FUN_022da52c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022da52c --addr 0x022da52c --size 0x88 --module arm7 --version 2.0/sp1


void FUN_022da52c(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = *DAT_022da5ac;
  iVar4 = *(int *)(iVar3 + 0x31c);
  uVar1 = *(ushort *)(iVar3 + 0x322);
  for (uVar5 = 1; uVar5 < uVar1; uVar5 = uVar5 + 1) {
    func_0x037cb774(0,uVar5 * 0x1c + iVar4,0x1a);
  }
  *(undefined2 *)(iVar3 + 0x52c) = 1;
  *(undefined2 *)(iVar3 + 0x52e) = 0;
  uVar2 = DAT_022da5b0;
  *(undefined2 *)(iVar3 + 0x530) = 1;
  *(short *)(iVar3 + 0x532) = (short)uVar2;
  *(undefined2 *)(iVar3 + 0x538) = 0;
  *(undefined2 *)(iVar3 + 0x534) = 0;
  *(undefined2 *)(iVar3 + 0x53a) = 1;
  return;
}

