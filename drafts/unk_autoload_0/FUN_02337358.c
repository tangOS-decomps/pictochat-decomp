// decomp: module=unk_autoload_0 addr=0x02337358 name=FUN_02337358
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=25
// verify:  python tools/match.py --c <file> --func FUN_02337358 --addr 0x02337358 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337358(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  uVar2 = FUN_02332080();
  piVar1 = DAT_02337398;
  iVar3 = param_1 * 0xc;
  DAT_02337398[param_1 * 3] = DAT_0233739c & DAT_02337398[param_1 * 3];
  piVar1[param_1 * 3] = DAT_023373a0 & piVar1[param_1 * 3];
  iVar4 = piVar1[param_1 * 3];
  piVar5 = piVar1;
  if (param_1 == 0) {
    iVar4 = 0;
    piVar5 = piVar1 + -2;
    *piVar5 = 0;
    iVar3 = DAT_023373a4;
    piVar1[-1] = 0;
    *piVar1 = iVar3;
  }
  FUN_02332094(uVar2,iVar3,iVar4,piVar5,param_4);
  return;
}

