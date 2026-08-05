// decomp: module=arm7 addr=0x022cfba4 name=FUN_022cfba4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x98 (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=28
// verify:  python tools/match.py --c <file> --func FUN_022cfba4 --addr 0x022cfba4 --size 0x98 --module arm7 --version 2.0/sp1


void FUN_022cfba4(void)

{
  int iVar1;
  undefined4 uVar2;
  void *msg;
  int iVar3;
  undefined2 *puVar4;
  undefined4 in_r3;
  
  iVar1 = DAT_022cfc30;
  msg = (void *)func_0x037ca460(*(undefined4 *)(DAT_022cfc2c + 0x544),
                                *(undefined4 *)(DAT_022cfc2c + 0x548),0x40,in_r3,in_r3);
  uVar2 = DAT_022cfc38;
  *(short *)((int)msg + 0xc) = (short)DAT_022cfc34;
  *(undefined2 *)((int)msg + 0xe) = 0;
  iVar3 = func_0x037c9e90(uVar2,msg);
  if (iVar3 == 0) {
    FUN_022cfa44(msg);
    if (*(int *)(iVar1 + 0x154c) != 0) {
      puVar4 = (undefined2 *)func_0x037d14bc();
      *puVar4 = 0x80;
      puVar4[1] = 8;
      puVar4[2] = 0x16;
      puVar4[3] = 0x80;
      func_0x037d1464();
    }
  }
  return;
}

