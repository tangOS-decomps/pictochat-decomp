// decomp: module=arm7 addr=0x022c111c name=FUN_022c111c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x94 - it excludes this function's trailing literal pool), arm
// triage: noise=17 statements=27
// verify:  python tools/match.py --c <file> --func FUN_022c111c --addr 0x022c111c --size 0x9c --module arm7 --version 2.0/sp1


int FUN_022c111c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int unaff_r4;
  
  iVar1 = *DAT_022c11b0;
  if (param_2 == 0) {
    unaff_r4 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x17c) == 0) {
      unaff_r4 = FUN_022c5c80(*(undefined4 *)(iVar1 + 0x180),*(undefined4 *)(iVar1 + 0x184),
                              param_2 + 0xc,param_2,param_4);
    }
    else if (*(int *)(iVar1 + 0x17c) == 1) {
      unaff_r4 = (**(code **)(iVar1 + 0x180))(param_2 + 0xc);
    }
    if (unaff_r4 == 0) {
      unaff_r4 = 0;
    }
    else {
      *(short *)(unaff_r4 + 10) = (short)DAT_022c11b4;
      *(undefined2 *)(unaff_r4 + 8) = 0;
      FUN_022c12a4(param_1,unaff_r4);
    }
  }
  return unaff_r4;
}

