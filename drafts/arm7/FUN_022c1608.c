// decomp: module=arm7 addr=0x022c1608 name=FUN_022c1608
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x84 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022c1608 --addr 0x022c1608 --size 0x88 --module arm7 --version 2.0/sp1


void FUN_022c1608(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *DAT_022c168c;
  if (*(short *)(iVar1 + 0x1fc) == 0) {
    iVar1 = FUN_022c56b0(*(undefined4 *)(iVar1 + 0x304),param_2,0,iVar1,param_4);
    if (iVar1 == 0) {
      FUN_022c1238(param_1,*DAT_022c168c + 500,param_2);
    }
    else {
      FUN_022c105c(param_1,param_2);
    }
  }
  else {
    FUN_022c1238(param_1,iVar1 + 500,param_2);
    FUN_022c0e48(2,0x13);
  }
  return;
}

