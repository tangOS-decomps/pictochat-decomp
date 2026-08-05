// decomp: module=unk_autoload_0 addr=0x0232d6f8 name=FUN_0232d6f8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e4 (Ghidra's cache says 0x2a0 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=195
// verify:  python tools/match.py --c <file> --func FUN_0232d6f8 --addr 0x0232d6f8 --size 0x2e4 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232d6f8(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  longlong lVar12;
  longlong lVar13;
  undefined8 uVar14;
  undefined4 local_54;
  undefined4 local_50;
  
  lVar12 = CONCAT44(local_54,local_50);
  bVar2 = false;
  uVar6 = DAT_0232d9b8 | (uint)DAT_0232d9b4 >> 0x18;
  uVar1 = (uint)DAT_0232d9b4 & 0xffffff;
  uVar7 = DAT_0232d9bc | ((uint)DAT_0232d9b4 & 0xff) << 8;
  uVar8 = param_2 >> 0x10 & 0xff;
  uVar9 = uVar8 | DAT_0232d9c0;
  uVar10 = param_2 & 0xffff | 0x10000;
  uVar8 = uVar8 | DAT_0232d9c4;
  uVar4 = DAT_0232d9c8 | param_4 & 0xffff;
  do {
    do {
      while (!bVar2) {
        psVar3 = DAT_0232d9cc;
        psVar3[2] = 0;
        psVar3[3] = 0;
        switch(param_1) {
        case 1:
          iVar5 = FUN_0233831c(4,uVar8,0);
          if (iVar5 < 0) {
            bVar2 = false;
          }
          else {
            iVar5 = FUN_0233831c(4,uVar10,0);
            if (iVar5 < 0) {
              bVar2 = false;
            }
            else {
              iVar5 = FUN_0233831c(4,param_3 >> 0x10 | 0x20000,0);
              if (iVar5 < 0) {
                bVar2 = false;
              }
              else {
                iVar5 = FUN_0233831c(4,param_3 & 0xffff | 0x30000,0);
                if (iVar5 < 0) {
                  bVar2 = false;
                }
                else {
                  iVar5 = FUN_0233831c(4,param_4 >> 0x10 | 0x40000,0);
                  if (iVar5 < 0) {
                    bVar2 = false;
                  }
                  else {
                    iVar5 = FUN_0233831c(4,uVar4,0);
                    if (iVar5 < 0) {
                      bVar2 = false;
                    }
                    else {
                      bVar2 = true;
                    }
                  }
                }
              }
            }
          }
          break;
        case 2:
          iVar5 = FUN_0233831c(4,DAT_0232d9d0,0);
          if (iVar5 < 0) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          break;
        case 3:
          iVar5 = FUN_0233831c(4,uVar9,0);
          if (iVar5 < 0) {
            bVar2 = false;
          }
          else {
            iVar5 = FUN_0233831c(4,uVar10,0);
            if (iVar5 < 0) {
              bVar2 = false;
            }
            else {
              iVar5 = FUN_0233831c(4,param_3 | 0x20000,0);
              if (iVar5 < 0) {
                bVar2 = false;
              }
              else {
                iVar5 = FUN_0233831c(4,param_4 >> 0x10 | 0x30000,0);
                if (iVar5 < 0) {
                  bVar2 = false;
                }
                else {
                  iVar5 = FUN_0233831c(4,param_4 & 0xffff | 0x1040000,0);
                  if (iVar5 < 0) {
                    bVar2 = false;
                  }
                  else {
                    bVar2 = true;
                  }
                }
              }
            }
          }
          lVar12 = FUN_02331ca8();
          break;
        case 4:
        case 5:
          iVar5 = FUN_0233831c(4,uVar6,0);
          if (iVar5 < 0) {
            bVar2 = false;
          }
          else {
            iVar5 = FUN_0233831c(4,uVar1 >> 8 | 0x10000,0);
            if (iVar5 < 0) {
              bVar2 = false;
            }
            else {
              iVar5 = FUN_0233831c(4,uVar7,0);
              if (iVar5 < 0) {
                bVar2 = false;
              }
              else {
                bVar2 = true;
              }
            }
          }
          break;
        case 6:
          iVar5 = FUN_0233831c(4,DAT_0232d9d4,0);
          if (iVar5 < 0) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
        }
      }
    } while (*(int *)(DAT_0232d9cc + 2) != 1);
    bVar2 = false;
    if (*DAT_0232d9cc != 0) {
      return 0;
    }
    switch(param_1) {
    case 1:
      return 1;
    case 2:
      param_1 = 4;
      break;
    case 3:
      param_1 = 5;
      break;
    case 4:
    case 5:
      FUN_023314cc(DAT_0232d9b4,1);
      if (param_1 != 4) {
        if ((*DAT_0232d9b4 & 1) == 0) {
          return 1;
        }
        if ((*DAT_0232d9b4 & 0x20) == 0) {
          lVar13 = FUN_02331ca8();
          uVar14 = FUN_02335dec((int)(lVar13 - lVar12),(int)((ulonglong)(lVar13 - lVar12) >> 0x20),
                                0x40,0);
          uVar14 = FUN_02335da4((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),DAT_0232d9d8,0);
          iVar5 = (int)((ulonglong)uVar14 >> 0x20);
          bVar11 = (uint)uVar14 < 0xfa1;
          if ((uint)-iVar5 < (uint)bVar11) {
            FUN_02332d10(0x4000,-(uint)!bVar11 - iVar5);
            break;
          }
        }
        param_1 = 6;
        break;
      }
      if ((*DAT_0232d9b4 & 2) == 0) {
        return 0;
      }
      param_1 = 3;
      break;
    case 6:
      return 0;
    }
  } while( true );
}

