// decomp: module=arm7 addr=0x022c9828 name=FUN_022c9828
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc, thumb
// triage: noise=8 statements=73
// verify:  python tools/match.py --c <file> --func FUN_022c9828 --addr 0x022c9828 --size 0xcc --module arm7 --version 2.0/sp1


undefined4 FUN_022c9828(int param_1,uint param_2,int param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  
  if ((int)param_2 < 0) {
    return 0;
  }
  FUN_022c7bc4();
  if (param_2 < *(uint *)(param_1 + 0x38)) {
    uVar2 = *(uint *)(param_1 + 0x3c + param_2 * 4);
    *(char *)param_4 = (char)uVar2;
    uVar2 = uVar2 >> 8;
    switch(*(undefined1 *)param_4) {
    default:
      FUN_022c7bc8();
      return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      puVar4 = (undefined2 *)(param_1 + uVar2);
      iVar3 = 5;
      do {
        param_4 = param_4 + 1;
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        *param_4 = uVar1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      break;
    case 0x10:
      if ((param_3 < (int)(uint)*(byte *)(param_1 + uVar2)) ||
         ((int)(uint)*(byte *)(param_1 + uVar2 + 1) < param_3)) {
        FUN_022c7bc8();
        return 0;
      }
      puVar4 = (undefined2 *)(param_1 + uVar2 + (param_3 - (uint)*(byte *)(param_1 + uVar2)) * 0xc);
      iVar3 = 6;
      do {
        puVar4 = puVar4 + 1;
        *param_4 = *puVar4;
        param_4 = param_4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      break;
    case 0x11:
      iVar3 = 0;
      while ((int)(uint)*(byte *)(param_1 + uVar2 + iVar3) < param_3) {
        iVar3 = iVar3 + 1;
        if (7 < iVar3) {
          FUN_022c7bc8();
          return 0;
        }
      }
      puVar4 = (undefined2 *)(param_1 + uVar2 + iVar3 * 0xc + 8);
      iVar3 = 6;
      do {
        uVar1 = *puVar4;
        puVar4 = puVar4 + 1;
        *param_4 = uVar1;
        param_4 = param_4 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_022c7bc8();
    return 1;
  }
  FUN_022c7bc8();
  return 0;
}

