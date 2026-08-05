// decomp: module=arm7 addr=0x022c9948 name=FUN_022c9948
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd2, thumb
// triage: noise=5 statements=60
// verify:  python tools/match.py --c <file> --func FUN_022c9948 --addr 0x022c9948 --size 0xd2 --module arm7 --version 2.0/sp1


bool FUN_022c9948(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 char *param_6)

{
  char *base;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  char cVar4;
  
  cVar4 = param_6[10];
  uVar3 = param_4;
  if (cVar4 == -1) {
    uVar3 = 0xffffffff;
    cVar4 = '\0';
  }
  switch(*param_6) {
  default:
    iVar1 = 0;
    break;
  case '\x01':
  case '\x04':
    if (*param_6 == '\x01') {
      base = *(char **)(param_5 + (uint)*(ushort *)(param_6 + 4) * 8 + 0x18);
      if (base == (char *)0x0) {
        pvVar2 = (void *)0x0;
      }
      else if ((uint)*(ushort *)(param_6 + 2) < *(uint *)(base + 0x38)) {
        pvVar2 = FUN_022c9918(base,(uint)*(ushort *)(param_6 + 2));
      }
      else {
        pvVar2 = (void *)0x0;
      }
    }
    else {
      pvVar2 = (void *)((uint)*(ushort *)(param_6 + 4) * 0x10000 | (uint)*(ushort *)(param_6 + 2));
    }
    if (pvVar2 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_022c8150(param_1,pvVar2,(int)pvVar2 + 0xc,uVar3,param_2,param_3,param_4);
    }
    break;
  case '\x02':
    iVar1 = FUN_022c8178(param_1,*(undefined2 *)(param_6 + 2),uVar3);
    break;
  case '\x03':
    iVar1 = FUN_022c81a8(param_1,uVar3);
  }
  if (iVar1 != 0) {
    *(char *)(param_1 + 8) = (char)param_2;
    *(char *)(param_1 + 5) = param_6[6];
    *(char *)(param_1 + 9) = (char)param_3;
    FUN_022c8238(param_1,param_6[7]);
    FUN_022c8254(param_1,param_6[8]);
    FUN_022c8268(param_1,param_6[9]);
    FUN_022c826c(param_1,cVar4);
    *(char *)(param_1 + 10) = param_6[0xb] + -0x40;
  }
  return iVar1 != 0;
}

