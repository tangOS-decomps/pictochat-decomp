// decomp: module=arm7 addr=0x022da808 name=FUN_022da808
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x140 (Ghidra's cache says 0x13c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=63
// verify:  python tools/match.py --c <file> --func FUN_022da808 --addr 0x022da808 --size 0x140 --module arm7 --version 2.0/sp1


int FUN_022da808(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *DAT_022da944;
  *(short *)(iVar3 + 0x408) = *(short *)(param_2 + 2) + -3;
  *(undefined2 *)(param_2 + 2) = 3;
  sVar1 = *(short *)(iVar3 + 0x32e);
  iVar2 = param_1;
  if ((sVar1 != 1 && sVar1 != 3) && sVar1 != 2) {
    iVar2 = 0xb;
  }
  if ((sVar1 == 1 || sVar1 == 3) || sVar1 == 2) {
    if (*(ushort *)(*DAT_022da944 + 0x34c) < 0x20) {
      iVar2 = 1;
    }
    else if (*(ushort *)(param_1 + 0x16) < 0x21) {
      if (*(ushort *)(param_1 + 0x38) < 2) {
        iVar2 = FUN_022d8d6c(param_1 + 0x3a);
        if (iVar2 == 0) {
          iVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x4a) < 0x3e9) {
          if (*(ushort *)(param_1 + 0x4a) < 10) {
            iVar2 = 5;
          }
          else if (*(ushort *)(param_1 + 0x4c) < 0x11) {
            uVar4 = 0;
            while ((uVar4 < 0x10 && (iVar2 = FUN_022d8d6c(param_1 + 0x3a + uVar4), iVar2 != 0))) {
              iVar2 = FUN_022d84e0();
              if (iVar2 == 0) {
                return 5;
              }
              uVar4 = uVar4 + 1;
            }
            FUN_022d75a8(param_1 + 0x10);
            FUN_022d760c(*(undefined2 *)(param_1 + 0x16),param_1 + 0x18);
            *(int *)(iVar3 + 0x41c) = param_1;
            *(int *)(iVar3 + 0x420) = param_2;
            *(undefined2 *)(iVar3 + 0x404) = 0x10;
            func_0x037c5628(2,0);
            iVar2 = 0x80;
          }
          else {
            iVar2 = 5;
          }
        }
        else {
          iVar2 = 5;
        }
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 5;
    }
  }
  return iVar2;
}

