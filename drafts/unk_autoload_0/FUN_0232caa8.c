// decomp: module=unk_autoload_0 addr=0x0232caa8 name=FUN_0232caa8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e, thumb
// triage: noise=5 statements=18
// verify:  python tools/match.py --c <file> --func FUN_0232caa8 --addr 0x0232caa8 --size 0x3e --module unk_autoload_0 --version 2.0/sp1


int FUN_0232caa8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = param_4;
  iVar1 = FUN_0232c210(param_1,param_3);
  if (iVar1 == 0) {
    FUN_0232c3bc(0,param_2);
    FUN_0232c884();
    puVar2 = FUN_0232c4d0();
    iVar1 = FUN_0232c408(0,4,*puVar2,puVar2[1],puVar2[4],param_4,uVar3);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

