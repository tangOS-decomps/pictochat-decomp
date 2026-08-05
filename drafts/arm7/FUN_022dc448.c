// decomp: module=arm7 addr=0x022dc448 name=FUN_022dc448
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x108 (Ghidra's cache says 0x100 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=47
// verify:  python tools/match.py --c <file> --func FUN_022dc448 --addr 0x022dc448 --size 0x108 --module arm7 --version 2.0/sp1


undefined4 FUN_022dc448(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  piVar1 = DAT_022dc548;
  iVar4 = *(int *)(*DAT_022dc548 + 0x31c);
  *(undefined2 *)(param_2 + 2) = 1;
  piVar2 = DAT_022dc548;
  uVar5 = (uint)*(ushort *)(param_1 + 0x10);
  if ((uVar5 < *(ushort *)(*piVar1 + 0x322)) || (uVar5 == 0xffff)) {
    if ((*(ushort *)(param_1 + 0x14) < 0x40) || (*(ushort *)(param_1 + 0x14) == DAT_022dc54c)) {
      if (uVar5 == DAT_022dc54c) {
        uVar5 = 1;
        while (uVar5 < *(ushort *)(*piVar2 + 0x322)) {
          iVar6 = uVar5 * 0x1c + iVar4;
          uVar5 = uVar5 + 1;
          *(undefined2 *)(iVar6 + 0x1a) = *(undefined2 *)(param_1 + 0x12);
          if (*(short *)(iVar6 + 0x18) != 0) {
            *(undefined2 *)(iVar6 + 0x18) = *(undefined2 *)(param_1 + 0x12);
          }
        }
      }
      else if (uVar5 != 0) {
        *(undefined2 *)(uVar5 * 0x1c + iVar4 + 0x1a) = *(undefined2 *)(param_1 + 0x12);
        iVar6 = (uint)*(ushort *)(param_1 + 0x10) * 0x1c;
        if (*(short *)(iVar4 + 0x18 + iVar6) != 0) {
          *(undefined2 *)(iVar4 + 0x18 + iVar6) = *(undefined2 *)(param_1 + 0x12);
        }
      }
      if (*(short *)(param_1 + 0x14) != 0) {
        FUN_022d7e6c();
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 5;
    }
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}

