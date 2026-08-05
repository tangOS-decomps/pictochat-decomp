// decomp: module=arm7 addr=0x022d37d4 name=FUN_022d37d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x124 (Ghidra's cache says 0x118 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=53
// verify:  python tools/match.py --c <file> --func FUN_022d37d4 --addr 0x022d37d4 --size 0x124 --module arm7 --version 2.0/sp1


void FUN_022d37d4(int param_1)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 auStack_210 [512];
  
  uVar1 = *(uint *)(param_1 + 0x10) & 0xffff;
  iVar7 = *(int *)(DAT_022d38ec + 0x550);
  iVar4 = FUN_022d061c(auStack_210,*(uint *)(param_1 + 4) & 0xffff,*(uint *)(param_1 + 8) & 0xffff,
                       *(uint *)(param_1 + 0xc) & 0xffff);
  sVar2 = *(short *)(iVar4 + 4);
  if (sVar2 == 0) {
    if (uVar1 == DAT_022d38f0) {
      *(undefined4 *)(iVar7 + 0x7b8) = 0;
      *(undefined4 *)(iVar7 + 0x7bc) = 0;
    }
    else {
      if (uVar1 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = (ulonglong)DAT_022d38f4 * (ulonglong)(uVar1 * 100) >> 6;
      }
      *(ulonglong *)(iVar7 + 0x7b8) = uVar3;
    }
    uVar8 = func_0x037caa3c();
    iVar4 = 0;
    do {
      iVar6 = iVar7 + iVar4 * 8;
      *(uint *)(iVar6 + 0x738) = (uint)uVar8 | 1;
      iVar4 = iVar4 + 1;
      *(int *)(iVar6 + 0x73c) = (int)((ulonglong)uVar8 >> 0x20);
    } while (iVar4 < 0x10);
    puVar5 = (undefined2 *)func_0x037d14bc();
    *puVar5 = 0x1d;
    puVar5[1] = 0;
    func_0x037d1464();
  }
  else {
    puVar5 = (undefined2 *)func_0x037d14bc();
    *puVar5 = 0x1d;
    puVar5[1] = 1;
    puVar5[2] = 0x211;
    puVar5[3] = sVar2;
    func_0x037d1464();
  }
  return;
}

