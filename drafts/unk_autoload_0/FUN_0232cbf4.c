// decomp: module=unk_autoload_0 addr=0x0232cbf4 name=FUN_0232cbf4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, thumb
// triage: noise=5 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232cbf4 --addr 0x0232cbf4 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cbf4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = FUN_0232c520(1,2,param_3,param_4,param_4);
  if (iVar1 == 0) {
    pvVar2 = FUN_0232c4d0();
    *(undefined2 *)((int)pvVar2 + 0x150) = 0;
    *(undefined4 *)((int)pvVar2 + 0x14c) = 0;
    FUN_0232c3bc(8,param_1);
    iVar1 = FUN_0232c408(8,1,param_2);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
  }
  return iVar1;
}

