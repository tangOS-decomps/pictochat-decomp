// decomp: module=arm7 addr=0x022d3dfc name=FUN_022d3dfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xac - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022d3dfc --addr 0x022d3dfc --size 0xc0 --module arm7 --version 2.0/sp1


void FUN_022d3dfc(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *DAT_022d3ea8;
  iVar3 = *(int *)(DAT_022d3eac + 0x550);
  if (((0xcf < uVar1) && (uVar1 < 0xd2)) && (0x7e < *(uint *)(iVar3 + 0xd8))) {
    for (iVar4 = 1; (iVar4 < 7 && (iVar4 * 0x3f + 0x7fU <= *(uint *)(iVar3 + 0xd8)));
        iVar4 = iVar4 + 1) {
    }
    *DAT_022d3ea8 = uVar1 + (1 - (short)iVar4);
    *(int *)(iVar3 + 0xd8) = *(int *)(iVar3 + 0xd8) + iVar4 * -0x3f;
  }
  uVar2 = DAT_022d3eb0;
  if (0x7e < *(uint *)(iVar3 + 0xd8)) {
    *(undefined4 *)(iVar3 + 0x1c) = 0;
  }
  func_0x037cb0b8(DAT_022d3eb4,(int)*(short *)(iVar3 + 0x42),uVar2,DAT_022d3eb8,4);
  return;
}

