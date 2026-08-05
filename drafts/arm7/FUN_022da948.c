// decomp: module=arm7 addr=0x022da948 name=FUN_022da948
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1b8 (Ghidra's cache says 0x1b0 - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=102
// verify:  python tools/match.py --c <file> --func FUN_022da948 --addr 0x022da948 --size 0x1b8 --module arm7 --version 2.0/sp1


undefined4 FUN_022da948(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *DAT_022daaf8;
  *(undefined2 *)(param_2 + 2) = 5;
  if (*(short *)(iVar4 + 0x32e) == 3 || *(short *)(iVar4 + 0x32e) == 2) {
    if (*(ushort *)(iVar4 + 0x34c) < 0x20) {
      uVar2 = 1;
    }
    else {
      func_0x037c62c0(0x20);
      if ((*(ushort *)(param_1 + 0x18) & 1) == 0) {
        if (*(ushort *)(param_1 + 0x1e) == 0) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x1e) < 0x21) {
          if (*(ushort *)(param_1 + 0x46) < 10) {
            uVar2 = 5;
          }
          else if (*(ushort *)(param_1 + 0x46) < 0x3e9) {
            if (*(ushort *)(param_1 + 0x48) < 0x100) {
              if ((*(ushort *)(param_1 + 0x4a) & DAT_022daafc) == 0) {
                iVar3 = FUN_022d84e0((uint)*(ushort *)(param_1 + 0x4a));
                if (iVar3 == 0) {
                  uVar2 = 5;
                }
                else {
                  uVar1 = *(ushort *)(param_1 + 0x42);
                  if ((uVar1 & 0xf000) == 0) {
                    if ((*(ushort *)(param_1 + 0x44) & 0xf000) == 0) {
                      if (uVar1 == 0) {
                        uVar2 = 5;
                      }
                      else if (*(ushort *)(param_1 + 0x44) == 0 && uVar1 == 0) {
                        uVar2 = 5;
                      }
                      else if (*(ushort *)(param_1 + 0x10) < 0x7d1) {
                        iVar3 = FUN_022e2d50(0);
                        if (iVar3 == 0) {
                          if ((*(ushort *)(param_1 + 0x40) & 0x20) == 0) {
                            FUN_022d72cc(0);
                          }
                          else {
                            FUN_022d72cc(1);
                          }
                          FUN_022d75a8(param_1 + 0x18);
                          FUN_022d760c(*(undefined2 *)(param_1 + 0x1e),param_1 + 0x20);
                          FUN_022d771c(*(undefined2 *)(param_1 + 0x46));
                          FUN_022d793c(*(undefined2 *)(param_1 + 0x4a),0);
                          FUN_022d7bc8(param_1 + 0x42);
                          *(int *)(iVar4 + 0x41c) = param_1;
                          *(int *)(iVar4 + 0x420) = param_2;
                          *(undefined2 *)(iVar4 + 0x404) = 0x20;
                          func_0x037c5628(2,1);
                          uVar2 = 0x80;
                        }
                        else {
                          uVar2 = 0xe;
                        }
                      }
                      else {
                        uVar2 = 5;
                      }
                    }
                    else {
                      uVar2 = 5;
                    }
                  }
                  else {
                    uVar2 = 5;
                  }
                }
              }
              else {
                uVar2 = 5;
              }
            }
            else {
              uVar2 = 5;
            }
          }
          else {
            uVar2 = 5;
          }
        }
        else {
          uVar2 = 5;
        }
      }
      else {
        uVar2 = 5;
      }
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

