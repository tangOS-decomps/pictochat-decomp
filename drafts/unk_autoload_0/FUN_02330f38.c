// decomp: module=unk_autoload_0 addr=0x02330f38 name=FUN_02330f38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02330f38 --addr 0x02330f38 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330f38(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_02332080();
  iVar2 = **(int **)(DAT_02330f68 + 8);
  if (param_1 != 0) {
    *(int *)(iVar2 + 0x78) = param_1;
    FUN_02330b0c(param_1,iVar2);
  }
  *(undefined4 *)(iVar2 + 100) = 0;
  FUN_02330c4c();
  FUN_02332094(uVar1);
  return;
}

