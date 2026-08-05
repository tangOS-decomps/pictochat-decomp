// decomp: module=arm7 addr=0x022ce25c name=FUN_022ce25c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022ce25c --addr 0x022ce25c --size 0x68 --module arm7 --version 2.0/sp1


void FUN_022ce25c(undefined4 param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  if (((param_3 == 0) && (iVar1 = func_0x037c9e90(DAT_022ce2bc,param_2,0), iVar1 == 0)) &&
     (*(int *)(DAT_022ce2c0 + 0x54c) != 0)) {
    puVar2 = (undefined2 *)func_0x037d14bc();
    *puVar2 = *param_2;
    puVar2[1] = 8;
    puVar2[2] = 0;
    puVar2[3] = 0;
    func_0x037d1464();
  }
  return;
}

