// decomp: module=unk_autoload_0 addr=0x0232fbd8 name=FUN_0232fbd8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3a, thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232fbd8 --addr 0x0232fbd8 --size 0x3a --module unk_autoload_0 --version 2.0/sp1


void FUN_0232fbd8(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int a;
  int iVar2;
  
  if (param_2 != 0) {
    uVar1 = FUN_02332080();
    a = FUN_0232f53c(param_2);
    iVar2 = FUN_0232f74c(param_3);
    if (param_1 == iVar2) {
      FUN_0232f76c(param_3,0);
    }
    FUN_0232f53c(a);
    FUN_02332094(uVar1);
  }
  return;
}

