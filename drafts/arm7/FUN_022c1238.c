// decomp: module=arm7 addr=0x022c1238 name=FUN_022c1238
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022c1238 --addr 0x022c1238 --size 0x6c --module arm7 --version 2.0/sp1


int FUN_022c1238(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(ushort *)(param_3 + 10) == DAT_022c12a0) {
    uVar2 = FUN_022c48a4(0x1000000);
    iVar1 = FUN_022c105c(param_1,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_022c12a4(param_2,param_3);
    }
    FUN_022c486c(uVar2);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

