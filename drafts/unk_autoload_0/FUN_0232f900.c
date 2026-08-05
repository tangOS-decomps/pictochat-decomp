// decomp: module=unk_autoload_0 addr=0x0232f900 name=FUN_0232f900
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xc4 - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=52
// verify:  python tools/match.py --c <file> --func FUN_0232f900 --addr 0x0232f900 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232f900(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  undefined4 uStack_18;
  
  uStack_18 = param_4;
  puVar1 = (undefined4 *)FUN_0232f5a4();
  if (puVar1 == (undefined4 *)0x0) {
    return 4;
  }
  if ((param_2 & 2) == 0) {
    iVar2 = FUN_0232f74c(*puVar1);
  }
  else {
    iVar2 = FUN_0232fa88(*puVar1,param_3,param_4);
    if (iVar2 == 0) {
      return 8;
    }
  }
  iVar5 = 0;
  do {
    if (*(ushort *)(puVar1 + 1) != DAT_0232f9c4) {
      puVar3 = (uint *)FUN_0232f5f0();
      if (puVar3 == (uint *)0x0) {
        return 5;
      }
      iVar4 = FUN_0232f9c8(*(undefined2 *)(puVar1 + 1),param_2,param_3,param_4,&local_1c);
      if (iVar4 != 0) {
        return iVar4;
      }
      if ((((*puVar3 >> 0x18 & 1) != 0) && ((param_2 & 4) != 0)) &&
         (iVar4 = FUN_0232fd24(local_1c,iVar2,iVar5,*puVar3 & 0xffffff,param_3), iVar4 == 0)) {
        return 9;
      }
      if ((iVar2 != 0) && (local_1c != 0)) {
        FUN_02337fa0(iVar2,iVar5);
      }
    }
    iVar5 = iVar5 + 1;
    puVar1 = (undefined4 *)((int)puVar1 + 2);
    if (3 < iVar5) {
      if (param_5 != (int *)0x0) {
        *param_5 = iVar2;
      }
      return 0;
    }
  } while( true );
}

