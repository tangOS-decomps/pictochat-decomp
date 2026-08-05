// decomp: module=arm7 addr=0x022d2ad8 name=FUN_022d2ad8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc4 (Ghidra's cache says 0xbc - it excludes this function's trailing literal pool), arm
// triage: noise=10 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022d2ad8 --addr 0x022d2ad8 --size 0xc4 --module arm7 --version 2.0/sp1


void FUN_022d2ad8(int param_1,undefined2 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_022d2b94 + 0x550);
  puVar2 = (undefined2 *)func_0x037d14bc();
  puVar2[1] = 0;
  if (param_1 == 0) {
    *puVar2 = 0xc;
    uVar1 = DAT_022d2b98;
    puVar2[4] = 0x1a;
    puVar2[6] = (short)uVar1;
    puVar2[5] = *(undefined2 *)(iVar3 + 0x188);
    func_0x037cb8b4(param_3,puVar2 + 8,6);
    puVar2[0xb] = *(undefined2 *)(iVar3 + 0x30);
    puVar2[0xc] = *(undefined2 *)(iVar3 + 0x32);
  }
  else {
    *puVar2 = 8;
    puVar2[4] = 0x1a;
    puVar2[9] = (short)DAT_022d2b98;
    puVar2[8] = param_2;
    func_0x037cb8b4(param_3,puVar2 + 5,6);
    puVar2[0x16] = *(undefined2 *)(iVar3 + 0x30);
    puVar2[0x17] = *(undefined2 *)(iVar3 + 0x32);
  }
  func_0x037d1464(puVar2);
  return;
}

