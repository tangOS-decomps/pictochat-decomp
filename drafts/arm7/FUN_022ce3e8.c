// decomp: module=arm7 addr=0x022ce3e8 name=FUN_022ce3e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x150 (Ghidra's cache says 0x148 - it excludes this function's trailing literal pool), arm
// triage: noise=22 statements=55
// verify:  python tools/match.py --c <file> --func FUN_022ce3e8 --addr 0x022ce3e8 --size 0x150 --module arm7 --version 2.0/sp1


bool FUN_022ce3e8(int param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = *(int *)(DAT_022ce530 + 0x550);
  func_0x037cb8b4(iVar4 + 0xe0,param_2 + 0x10,6);
  *(undefined2 *)(param_2 + 0x16) = 7;
  *(undefined2 *)(param_2 + 0x18) = *(undefined2 *)(iVar4 + 500);
  *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)(iVar4 + 0x1ec);
  *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)(iVar4 + 0xe6);
  bVar5 = *(int *)(iVar4 + 0x198) != 0;
  if (bVar5) {
    *(undefined2 *)(param_2 + 0x20) = *(undefined2 *)(iVar4 + 0x196);
    *(undefined2 *)(param_2 + 0x22) = *(undefined2 *)(iVar4 + 0xc4);
    func_0x037cb8b4(iVar4 + 0x19c,param_2 + 0x24,0x50);
  }
  else {
    *(undefined2 *)(param_2 + 0x20) = 0;
    *(undefined2 *)(param_2 + 0x22) = 0;
    func_0x037cb774(0,param_2 + 0x24,0x50);
  }
  *(ushort *)(param_2 + 0x9e) = (ushort)bVar5;
  *(undefined2 *)(param_2 + 0x74) = 1;
  *(undefined2 *)(param_2 + 0x76) = 1;
  if (*(short *)(iVar4 + 0xe6) == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  *(undefined2 *)(param_2 + 0x78) = uVar2;
  *(undefined2 *)(param_2 + 0x7a) = 10;
  if (param_1 == 0x26) {
    func_0x037cb774(0,param_2 + 0x7c,0x20);
  }
  else {
    func_0x037cb774(0,param_2 + 0x7c,8);
    func_0x037cb774(DAT_022ce534,param_2 + 0x84,0x18);
  }
  *(undefined2 *)(param_2 + 0x9c) = *(undefined2 *)(iVar4 + 0x1ee);
  iVar4 = FUN_022d0440(param_2);
  sVar1 = *(short *)(iVar4 + 4);
  if (sVar1 != 0) {
    puVar3 = (undefined2 *)func_0x037d14bc(iVar4);
    *puVar3 = (short)param_1;
    puVar3[1] = 1;
    puVar3[2] = 0x200;
    puVar3[3] = sVar1;
    func_0x037d1464();
  }
  return sVar1 == 0;
}

