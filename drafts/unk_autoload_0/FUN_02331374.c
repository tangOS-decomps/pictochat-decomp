// decomp: module=unk_autoload_0 addr=0x02331374 name=FUN_02331374
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02331374 --addr 0x02331374 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331374(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_02332080();
  iVar2 = *(int *)(DAT_023313c4 + 4);
  do {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = iVar2;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      FUN_0233142c(iVar2,param_1);
LAB_023313bc:
      FUN_02332094(uVar1);
      return;
    }
    if (*(int *)(param_1 + 8) == iVar2) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      goto LAB_023313bc;
    }
    *(int *)(iVar2 + 0x84) = param_1;
    FUN_02330f38(param_1);
    *(undefined4 *)(iVar2 + 0x84) = 0;
  } while( true );
}

