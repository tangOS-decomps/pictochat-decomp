// decomp: module=arm7 addr=0x022d3ebc name=FUN_022d3ebc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x118 (Ghidra's cache says 0x104 - it excludes this function's trailing literal pool), arm
// triage: noise=12 statements=62
// verify:  python tools/match.py --c <file> --func FUN_022d3ebc --addr 0x022d3ebc --size 0x118 --module arm7 --version 2.0/sp1


void FUN_022d3ebc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 in_r3;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  
  iVar7 = *(int *)(DAT_022d3fc0 + 0x550);
  if (*(int *)(iVar7 + 0xc) == 1) {
    func_0x037cb0b8(DAT_022d3fc4,200,0x107,DAT_022d3fc8,1,in_r3);
    if (*(int *)(iVar7 + 0x7bc) != 0 || *(int *)(iVar7 + 0x7b8) != 0) {
      uVar11 = func_0x037caa3c();
      uVar8 = *(uint *)(iVar7 + 0x738);
      uVar5 = (uint)uVar11 | 1;
      if (*(int *)(iVar7 + 0x73c) != 0 || uVar8 != 0) {
        uVar9 = uVar5 - uVar8;
        uVar6 = *(uint *)(iVar7 + 0x7bc);
        uVar5 = (int)((ulonglong)uVar11 >> 0x20) - (*(int *)(iVar7 + 0x73c) + (uint)(uVar5 < uVar8))
        ;
        bVar10 = uVar6 <= uVar5;
        if (uVar5 == uVar6) {
          bVar10 = *(uint *)(iVar7 + 0x7b8) <= uVar9;
        }
        if (bVar10 && (uVar5 != uVar6 || uVar9 != *(uint *)(iVar7 + 0x7b8))) {
          *(undefined4 *)(iVar7 + 0x738) = 0;
          *(undefined4 *)(iVar7 + 0x73c) = 0;
          puVar3 = FUN_022ce718();
          if (puVar3 == (undefined4 *)0x0) {
            iVar7 = 0;
          }
          else {
            *puVar3 = 0x25;
            uVar2 = DAT_022d3fd0;
            uVar1 = DAT_022d3fcc;
            puVar3[1] = 0;
            puVar3[2] = uVar1;
            iVar7 = func_0x037c9e90(uVar2);
          }
          if (iVar7 != 0) {
            return;
          }
          puVar4 = (undefined2 *)func_0x037d14bc();
          *puVar4 = 0x80;
          puVar4[1] = 8;
          puVar4[2] = 0x16;
          puVar4[3] = 0x25;
          func_0x037d1464();
          return;
        }
      }
    }
    FUN_022d40d8();
  }
  return;
}

