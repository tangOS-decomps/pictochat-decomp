// decomp: module=arm7 addr=0x022c8290 name=FUN_022c8290
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x140 (Ghidra's cache says 0x12c - it excludes this function's trailing literal pool), thumb
// triage: noise=26 statements=88
// verify:  python tools/match.py --c <file> --func FUN_022c8290 --addr 0x022c8290 --size 0x140 --module arm7 --version 2.0/sp1


int FUN_022c8290(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  param_1 = param_1 & ~DAT_022c83bc[1];
  if (param_3 == 0) {
    param_1 = param_1 & ~*DAT_022c83bc;
  }
  iVar6 = 0;
  iVar4 = 0;
  do {
    iVar2 = iVar4;
    if (((1 << (uint)*(byte *)(DAT_022c83c0 + iVar6) & param_1) != 0) &&
       (iVar3 = DAT_022c83c4 + (uint)*(byte *)(DAT_022c83c0 + iVar6) * 0x54, iVar2 = iVar3,
       iVar4 != 0)) {
      iVar2 = iVar4;
      if (*(byte *)(iVar3 + 0x22) <= *(byte *)(iVar4 + 0x22)) {
        if (*(byte *)(iVar3 + 0x22) == *(byte *)(iVar4 + 0x22)) {
          iVar2 = (int)((*(ushort *)(iVar4 + 0x24) & 0xff) * 0x10) >>
                  *(sbyte *)(DAT_022c83c8 + ((int)(uint)*(ushort *)(iVar4 + 0x24) >> 8));
          iVar5 = (int)((*(ushort *)(iVar3 + 0x24) & 0xff) << 4) >>
                  *(sbyte *)(DAT_022c83c8 + ((int)(uint)*(ushort *)(iVar3 + 0x24) >> 8));
          if (iVar2 == iVar5) {
            iVar5 = 0;
          }
          else if (iVar2 < iVar5) {
            iVar5 = 1;
          }
          else {
            iVar5 = -1;
          }
          iVar2 = iVar4;
          if (-1 < iVar5) goto LAB_022c831a;
        }
        iVar2 = iVar3;
      }
    }
LAB_022c831a:
    iVar6 = iVar6 + 1;
    iVar4 = iVar2;
    if (0xf < iVar6) {
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else if (param_2 < (int)(uint)*(byte *)(iVar2 + 0x22)) {
        iVar2 = 0;
      }
      else {
        if (*(int *)(iVar2 + 0x48) != 0) {
          FUN_022c4438(iVar2,0,*(undefined4 *)(iVar2 + 0x4c));
        }
        *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 7 | 0x10;
        *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 0xfe;
        *(undefined4 *)(iVar2 + 0x50) = 0;
        *(undefined4 *)(iVar2 + 0x48) = param_4;
        *(undefined4 *)(iVar2 + 0x4c) = param_5;
        *(undefined4 *)(iVar2 + 0x34) = 0;
        *(char *)(iVar2 + 0x22) = (char)param_2;
        *(undefined2 *)(iVar2 + 0x24) = 0x7f;
        *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 0xfd;
        *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) | 4;
        *(undefined1 *)(iVar2 + 8) = 0x3c;
        *(undefined1 *)(iVar2 + 5) = 0x3c;
        *(undefined1 *)(iVar2 + 9) = 0x7f;
        *(undefined1 *)(iVar2 + 10) = 0;
        *(undefined2 *)(iVar2 + 0xc) = 0;
        *(undefined2 *)(iVar2 + 6) = 0;
        *(undefined2 *)(iVar2 + 0xe) = 0;
        *(undefined1 *)(iVar2 + 0xb) = 0;
        *(undefined1 *)(iVar2 + 4) = 0x7f;
        *(undefined2 *)(iVar2 + 0x32) = 0;
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined1 *)(iVar2 + 0x1c) = 0;
        uVar1 = (undefined2)DAT_022c83cc;
        *(undefined2 *)(iVar2 + 0x1e) = uVar1;
        *(undefined1 *)(iVar2 + 0x1d) = 0x7f;
        *(undefined2 *)(iVar2 + 0x20) = uVar1;
        FUN_022c857c(iVar2 + 0x28);
      }
      return iVar2;
    }
  } while( true );
}

