// decomp: module=arm7 addr=0x022d24f4 name=FUN_022d24f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, arm
// triage: noise=9 statements=20
// verify:  python tools/match.py --c <file> --func FUN_022d24f4 --addr 0x022d24f4 --size 0x58 --module arm7 --version 2.0/sp1


void FUN_022d24f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined2 local_10 [2];
  undefined4 local_c;
  
  uVar3 = *(undefined4 *)(param_1 + 4);
  local_c = param_4;
  iVar1 = FUN_022d254c(param_1,0,local_10);
  if (iVar1 == 1) {
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = 0xd;
    puVar2[1] = 0;
    puVar2[4] = (short)uVar3;
    puVar2[5] = local_10[0];
    func_0x037d1464();
  }
  return;
}

