// decomp: module=unk_autoload_0 addr=0x02338510 name=FUN_02338510
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x246, thumb
// triage: noise=72 statements=165
// verify:  python tools/match.py --c <file> --func FUN_02338510 --addr 0x02338510 --size 0x246 --module unk_autoload_0 --version 2.0/sp1


int FUN_02338510(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  puVar4 = *(undefined4 **)(iVar1 + 0x24);
  if (param_2 < 0x23) {
    if (puVar4[param_2] == 0) {
      iVar1 = 4;
    }
    else {
      switch(param_2) {
      case 0:
        iVar1 = (*(code *)*puVar4)(iVar1,param_1,**(undefined4 **)(param_1 + 0x10),
                                   *(undefined4 **)(param_1 + 0x10) + 1);
        break;
      case 1:
        iVar1 = (*(code *)puVar4[1])
                          (iVar1,param_1,**(undefined4 **)(param_1 + 0x10),
                           *(undefined4 **)(param_1 + 0x10) + 1);
        break;
      case 2:
        iVar1 = (*(code *)puVar4[2])
                          (iVar1,param_1,**(undefined4 **)(param_1 + 0x10),
                           (*(undefined4 **)(param_1 + 0x10))[1]);
        break;
      case 3:
        iVar1 = (*(code *)puVar4[3])(iVar1,param_1,**(undefined4 **)(param_1 + 0x10));
        break;
      case 4:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[4])(iVar1,*puVar3,puVar3[1],puVar3 + 2,puVar3[3]);
        break;
      case 5:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[5])(iVar1,param_1,*puVar3,puVar3[1],puVar3 + 2);
        break;
      case 6:
        iVar1 = (*(code *)puVar4[6])
                          (iVar1,param_1,**(undefined4 **)(param_1 + 0x10),
                           (*(undefined4 **)(param_1 + 0x10))[1]);
        break;
      case 7:
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[7])
                          (iVar1,param_1,*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 8),iVar2
                          );
        break;
      case 8:
        iVar1 = (*(code *)puVar4[8])(iVar1,param_1);
        break;
      case 9:
        (*(code *)puVar4[9])();
        return 0;
      case 10:
        (*(code *)puVar4[10])();
        return 0;
      case 0xb:
        (*(code *)puVar4[0xb])();
        return 0;
      case 0xc:
        (*(code *)puVar4[0xc])();
        return 0;
      case 0xd:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0xd])(iVar1,param_1,*puVar3,puVar3[1],puVar3[2]);
        break;
      case 0xe:
        iVar1 = (*(code *)puVar4[0xe])
                          (iVar1,param_1,*(int *)(param_1 + 0x10),
                           *(undefined4 *)(*(int *)(param_1 + 0x10) + 4));
        break;
      case 0xf:
        iVar1 = (*(code *)puVar4[0xf])(iVar1,param_1,*(undefined4 *)(param_1 + 0x10));
        break;
      case 0x10:
        iVar1 = (*(code *)puVar4[0x10])(iVar1,param_1,*(undefined4 *)(param_1 + 0x10));
        break;
      case 0x11:
        (*(code *)puVar4[0x11])();
        return 0;
      case 0x12:
        (*(code *)puVar4[0x12])();
        return 0;
      case 0x13:
        iVar1 = (*(code *)puVar4[0x13])(iVar1,*(undefined4 *)(param_1 + 0x10));
        break;
      case 0x14:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x14])(iVar1,*puVar3,puVar3[1],puVar3[2]);
        break;
      case 0x15:
        iVar1 = (*(code *)puVar4[0x15])
                          (iVar1,**(undefined4 **)(param_1 + 0x10),
                           (*(undefined4 **)(param_1 + 0x10))[1]);
        break;
      case 0x16:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x16])(iVar1,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        break;
      case 0x17:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x17])(iVar1,*puVar3,puVar3[1],puVar3[2]);
        break;
      case 0x18:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x18])(iVar1,*puVar3,puVar3[1],puVar3[2]);
        break;
      case 0x19:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x19])(iVar1,*puVar3,puVar3[1],puVar3[2]);
        break;
      case 0x1a:
        iVar1 = (*(code *)puVar4[0x1a])
                          (iVar1,**(undefined4 **)(param_1 + 0x10),
                           (*(undefined4 **)(param_1 + 0x10))[1]);
        break;
      case 0x1b:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x1b])(iVar1,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        break;
      case 0x1c:
        iVar1 = (*(code *)puVar4[0x1c])(iVar1,**(undefined4 **)(param_1 + 0x10));
        break;
      default:
        iVar1 = 4;
        break;
      case 0x1e:
        iVar1 = (*(code *)puVar4[0x1e])(iVar1,param_1);
        break;
      case 0x1f:
        iVar1 = (*(code *)puVar4[0x1f])(iVar1,param_1,**(undefined4 **)(param_1 + 0x10));
        break;
      case 0x20:
        puVar3 = *(undefined4 **)(param_1 + 0x10);
        iVar1 = (*(code *)puVar4[0x20])(iVar1,param_1,*puVar3,puVar3[1],puVar3[2],param_4);
        break;
      case 0x21:
        iVar1 = (*(code *)puVar4[0x21])(iVar1,param_1);
        break;
      case 0x22:
        iVar1 = (*(code *)puVar4[0x22])
                          (iVar1,param_1,**(undefined4 **)(param_1 + 0x10),
                           (*(undefined4 **)(param_1 + 0x10))[1]);
      }
    }
  }
  else {
    iVar1 = 4;
  }
  iVar2 = FUN_0233844c(param_2);
  if (iVar2 == 0) {
    if ((*(uint *)(param_1 + 0xc) & 4) == 0) {
      if (iVar1 != 0x100) {
        FUN_0233846c(param_1,iVar1);
      }
    }
    else {
      iVar1 = FUN_023384d0(param_1,iVar1);
    }
  }
  return iVar1;
}

