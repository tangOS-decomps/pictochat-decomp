// decomp: module=arm7 addr=0x022de318 name=FUN_022de318
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x17c (Ghidra's cache says 0x178 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=57
// verify:  python tools/match.py --c <file> --func FUN_022de318 --addr 0x022de318 --size 0x17c --module arm7 --version 2.0/sp1


void FUN_022de318(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *DAT_022de490;
  FUN_022d9bf0();
  if ((*(ushort *)(param_1 + 8) & 2) == 0) {
    *(int *)(iVar3 + 0x53c) = *(int *)(iVar3 + 0x53c) + 1;
    if ((int)((uint)*(ushort *)(param_1 + 0x14) << 0x17) < 0) {
      if ((*(ushort *)(param_1 + 0x24) & 1) == 0) {
        *(int *)(iVar3 + 0x54c) = *(int *)(iVar3 + 0x54c) + 1;
      }
      else {
        *(int *)(iVar3 + 0x550) = *(int *)(iVar3 + 0x550) + 1;
      }
    }
    else if ((*(ushort *)(param_1 + 0x18) & 1) == 0) {
      *(int *)(iVar3 + 0x54c) = *(int *)(iVar3 + 0x54c) + 1;
    }
    else {
      *(int *)(iVar3 + 0x550) = *(int *)(iVar3 + 0x550) + 1;
    }
  }
  else {
    *(int *)(iVar3 + 0x540) = *(int *)(iVar3 + 0x540) + 1;
  }
  if ((int)((uint)*(ushort *)(param_1 + 0x14) << 0x11) < 0) {
    *(int *)(iVar3 + 0x554) = *(int *)(iVar3 + 0x554) + 1;
  }
  FUN_022dded8(iVar3 + 0x194,param_1 + -0x10);
  *(undefined2 *)(*DAT_022de490 + 0x42c) = 0;
  iVar1 = FUN_022da03c(*(undefined2 *)(param_1 + 2));
  if ((iVar1 != 0) && ((*(ushort *)(param_1 + 0x14) & 0x2000) == 0)) {
    FUN_022d9dc4(*(undefined2 *)(param_1 + 2));
  }
  if (param_2 != 0) {
    if (*(short *)(iVar3 + 0x19c) == 0) {
      if ((((ushort)(*(short *)(iVar3 + 0x350) - 2U) < 2) && (*(short *)(iVar3 + 0x34c) == 0x40)) &&
         (*(short *)(iVar3 + 0x352) != 0)) {
        uVar2 = FUN_022da108(*(undefined2 *)(iVar3 + 0x3cc));
        bVar4 = uVar2 == 0;
        if (bVar4) {
          uVar2 = (uint)*(ushort *)(iVar3 + 0x3d2);
        }
        if (bVar4 && uVar2 == 0) {
          FUN_022d7cf0(1);
        }
      }
    }
    else {
      FUN_022ddf10(0);
    }
  }
  return;
}

