// decomp: module=unk_autoload_0 addr=0x023323c4 name=FUN_023323c4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=20
// verify:  python tools/match.py --c <file> --func FUN_023323c4 --addr 0x023323c4 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_023323c4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  
  uVar1 = FUN_02332080();
  piVar3 = (int *)*DAT_02332400;
  piVar2 = DAT_02332404;
  while (piVar3 != (int *)0x0) {
    if ((code *)piVar3[2] != (code *)0x0) {
      (*(code *)piVar3[2])(piVar3[1],param_1,param_2);
    }
    if ((int *)*piVar2 == piVar3) {
      piVar2 = (int *)*piVar2;
    }
    piVar3 = (int *)*piVar2;
  }
  FUN_02332094(uVar1);
  return;
}

