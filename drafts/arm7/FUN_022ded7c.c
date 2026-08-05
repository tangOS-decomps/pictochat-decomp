// decomp: module=arm7 addr=0x022ded7c name=FUN_022ded7c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf8 (Ghidra's cache says 0xf4 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=45
// verify:  python tools/match.py --c <file> --func FUN_022ded7c --addr 0x022ded7c --size 0xf8 --module arm7 --version 2.0/sp1


void FUN_022ded7c(uint param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  bVar1 = false;
  iVar2 = FUN_022da108();
  if (iVar2 != 0) {
    uVar6 = 0;
    do {
      iVar2 = *(int *)(*DAT_022dee70 + uVar6 * 0xc + 0x194);
      if (iVar2 != -1) {
        do {
          iVar3 = func_0x037c5b10(iVar2);
          iVar5 = iVar2 + 0x10;
          if (*(ushort *)(iVar2 + 0x12) == param_1) {
            iVar4 = iVar3;
            if (uVar6 != 1) {
              iVar4 = *(int *)(uVar6 * 0x14 + *DAT_022dee70 + 0x438);
            }
            if (uVar6 != 1 && iVar5 != iVar4) {
              *(undefined2 *)(iVar2 + 0x18) = 2;
              FUN_022d9bf0(iVar5);
              FUN_022dded8(*DAT_022dee70 + 0x194 + uVar6 * 0xc,iVar2);
              if (!bVar1) {
                bVar1 = true;
              }
            }
            else {
              FUN_022d9bf0(iVar5);
              *(undefined2 *)(iVar2 + 0x12) = 0;
              FUN_022d9b60(iVar5);
            }
          }
          iVar2 = iVar3;
        } while (iVar3 != -1);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
  }
  return;
}

