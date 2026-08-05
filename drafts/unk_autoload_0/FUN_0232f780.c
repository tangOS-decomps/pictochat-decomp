// decomp: module=unk_autoload_0 addr=0x0232f780 name=FUN_0232f780
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4a, thumb
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_0232f780 --addr 0x0232f780 --size 0x4a --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232f780(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int a;
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 3U & 0xfffffffc;
  if ((uint)(param_1 + param_2) < uVar3) {
    return 0;
  }
  uVar2 = (param_1 + param_2) - uVar3;
  if (uVar2 < 0x10) {
    return 0;
  }
  a = FUN_0232e6e8(uVar3 + 0x10,uVar2 - 0x10,0,param_4,param_4);
  if (a == 0) {
    return 0;
  }
  iVar1 = FUN_0232f89c(uVar3,a);
  if (iVar1 == 0) {
    thunk_FUN_0232e250(a);
    return 0;
  }
  return uVar3;
}

