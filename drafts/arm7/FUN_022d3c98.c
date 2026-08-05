// decomp: module=arm7 addr=0x022d3c98 name=FUN_022d3c98
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x164 (Ghidra's cache says 0x13c - it excludes this function's trailing literal pool), arm
// triage: noise=9 statements=56
// verify:  python tools/match.py --c <file> --func FUN_022d3c98 --addr 0x022d3c98 --size 0x164 --module arm7 --version 2.0/sp1


void FUN_022d3c98(void)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 in_r3;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = DAT_022d3dd4;
  iVar4 = *(int *)(DAT_022d3dd4 + 0x550);
  uVar6 = (uint)*DAT_022d3dd8;
  *(uint *)(iVar4 + 0xd0) = uVar6;
  if (*(uint *)(iVar4 + 0xd4) != uVar6) {
    *(uint *)(iVar4 + 0xd4) = uVar6;
    puVar2 = DAT_022d3ddc;
    iVar5 = *(int *)(iVar5 + 0x550);
    *(int *)(iVar5 + 0xd0) = *(int *)(iVar5 + 0xd0) << 6;
    uVar1 = puVar2[1];
    if (*puVar2 < *puVar2) {
      uVar1 = puVar2[1];
    }
    uVar6 = DAT_022d3de8 &
            (DAT_022d3de4 - (uint)*DAT_022d3de0) * 0x7f +
            (CONCAT22(uVar1,*puVar2) & DAT_022d3de8) * 2 >> 1;
    if (uVar6 < *(uint *)(iVar5 + 0xd0)) {
      *(undefined4 *)(iVar5 + 0xd8) = 0;
    }
    else {
      for (iVar8 = 1; iVar8 < 0x1e; iVar8 = iVar8 + 1) {
        uVar7 = *(int *)(iVar5 + 0xd0) + 0x414b;
        *(uint *)(iVar5 + 0xd0) = uVar7;
        uVar3 = DAT_022d3dec;
        if (uVar6 < uVar7) {
          *(uint *)(iVar5 + 0xd8) = uVar7 - uVar6;
          if (uVar3 < uVar7 - uVar6) {
            *(undefined4 *)(iVar5 + 0xd8) = 0;
          }
          goto LAB_022d3d78;
        }
      }
      *(undefined4 *)(iVar5 + 0xd8) = 0;
    }
  }
LAB_022d3d78:
  if (*(uint *)(iVar4 + 0xd8) < 0x80) {
    *(undefined4 *)(iVar4 + 0x1c) = 1;
    func_0x037cb0b8(DAT_022d3df0,(int)*(short *)(iVar4 + 0x42),0x107,DAT_022d3df8,4,in_r3);
  }
  else {
    func_0x037cb0b8(DAT_022d3df0,0xd0,0x107,DAT_022d3df4,2,in_r3);
  }
  return;
}

