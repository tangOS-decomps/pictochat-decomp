// decomp: module=unk_autoload_0 addr=0x0232f9c8 name=FUN_0232f9c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c, thumb
// triage: noise=4 statements=30
// verify:  python tools/match.py --c <file> --func FUN_0232f9c8 --addr 0x0232f9c8 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_0232f9c8(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = (uint *)FUN_0232f5f0();
  if (puVar1 == (uint *)0x0) {
    return 5;
  }
  if ((param_2 & 4) == 0) {
    iVar2 = FUN_0232f74c(*puVar1 & 0xffffff);
  }
  else {
    uVar3 = *puVar1;
    if ((uVar3 >> 0x18 & 1) == 0) {
      iVar2 = FUN_0232facc(uVar3 & 0xffffff,param_3,param_4);
    }
    else {
      iVar2 = FUN_0232fb10(uVar3 & 0xffffff,param_3,param_4);
    }
    if (iVar2 == 0) {
      return 9;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar2;
  }
  return 0;
}

