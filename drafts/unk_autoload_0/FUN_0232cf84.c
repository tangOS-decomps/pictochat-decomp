// decomp: module=unk_autoload_0 addr=0x0232cf84 name=FUN_0232cf84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc (Ghidra's cache says 0xc6 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=42
// verify:  python tools/match.py --c <file> --func FUN_0232cf84 --addr 0x0232cf84 --size 0xcc --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cf84(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,undefined2 param_5,
                undefined2 param_6,undefined2 param_7)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  sVar4 = 1;
  pvVar1 = FUN_0232c4d0();
  iVar3 = *(int *)((int)pvVar1 + 4);
  iVar2 = FUN_0232c520(2,9,10);
  if (iVar2 == 0) {
    FUN_023314cc(iVar3 + 0x188,2);
    if (*(short *)(iVar3 + 0x188) == 0) {
      FUN_023314cc(iVar3 + 0x182,2);
      sVar4 = *(short *)(iVar3 + DAT_0232d04c);
      FUN_023314cc(iVar3 + 0x86,2);
    }
    if (param_3 == 0) {
      return 6;
    }
    if (sVar4 == 0) {
      return 7;
    }
    FUN_023314cc(iVar3 + 0x7c,2);
    if (param_3 == *(int *)(iVar3 + 0x7c)) {
      return 6;
    }
    if (0x200 < param_4) {
      return 6;
    }
    if (param_4 == 0) {
      return 6;
    }
    FUN_023314e8(param_3,param_4);
    iVar2 = FUN_0232c408(0xf,7,param_3,param_4,param_5,param_6,param_7,param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
  }
  return iVar2;
}

