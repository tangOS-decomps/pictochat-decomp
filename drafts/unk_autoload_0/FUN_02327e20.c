// decomp: module=unk_autoload_0 addr=0x02327e20 name=FUN_02327e20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=32
// verify:  python tools/match.py --c <file> --func FUN_02327e20 --addr 0x02327e20 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02327e20(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (param_2 == 0) {
    uVar6 = 0;
    uVar5 = 6;
    uVar4 = 7;
  }
  else {
    uVar6 = 6;
    uVar5 = 7;
    uVar4 = 0;
  }
  iVar1 = FUN_023212e0();
  if ((iVar1 != 0) && (*(int *)(PTR_DAT_02327e78 + 0x20) != -1)) {
    uVar2 = FUN_023212f8();
    uVar3 = FUN_02321304();
    iVar1 = FUN_0232e004(PTR_DAT_02327e7c,uVar2,uVar3);
    if (param_1 == iVar1) {
      return uVar5;
    }
    if (*(int *)(PTR_DAT_02327e78 + 0x20) == param_1) {
      return uVar4;
    }
  }
  return uVar6;
}

