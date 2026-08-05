// decomp: module=unk_autoload_0 addr=0x0232f84c name=FUN_0232f84c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x42, thumb
// triage: noise=7 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232f84c --addr 0x0232f84c --size 0x42 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232f84c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0232e710(*param_1,(param_2 + 0x1fU & 0xffffffe0) + 0x20,0x20);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_0232e188((ushort *)(param_1 + 1),(char *)0x0);
  *(int *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  *(undefined4 *)(iVar1 + 0x10) = param_4;
  *(undefined4 *)(iVar1 + 0x14) = param_5;
  FUN_0232e0ac(iVar2,iVar1);
  return iVar1 + 0x20;
}

