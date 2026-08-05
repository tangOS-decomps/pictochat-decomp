// decomp: module=arm7 addr=0x022d0a2c name=FUN_022d0a2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), arm
// triage: noise=18 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022d0a2c --addr 0x022d0a2c --size 0xa0 --module arm7 --version 2.0/sp1


void FUN_022d0a2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined2 local_10;
  undefined2 local_e;
  undefined4 local_c;
  
  iVar1 = DAT_022d0ac8;
  puVar4 = *(undefined4 **)(param_1 + 4);
  *(undefined4 **)(DAT_022d0ac8 + 0x54c) = puVar4;
  uVar3 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(iVar1 + 0x550) = uVar3;
  *puVar4 = uVar3;
  puVar4[2] = *(undefined4 *)(param_1 + 0xc);
  local_c = param_4;
  FUN_022d5e9c(*(undefined4 *)(param_1 + 0x10));
  iVar1 = FUN_022d6158(&local_e,&local_10);
  if (iVar1 == 0) {
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = 0;
    puVar2[1] = 1;
    puVar2[2] = local_e;
    puVar2[3] = local_10;
    func_0x037d1464();
  }
  else {
    *(undefined2 *)*puVar4 = 2;
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = 0;
    puVar2[1] = 0;
    func_0x037d1464();
  }
  return;
}

