// decomp: module=arm7 addr=0x022da75c name=FUN_022da75c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xac (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022da75c --addr 0x022da75c --size 0xac --module arm7 --version 2.0/sp1


undefined4 FUN_022da75c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_2 + 2) = 9;
  if (*(ushort *)(param_1 + 0x10) < 2) {
    if (*(ushort *)(param_1 + 0x12) < 2) {
      if (*(ushort *)(param_1 + 0x14) < 2) {
        FUN_022d7c88(*(ushort *)(param_1 + 0x10));
        if (*(short *)(param_1 + 0x10) == 1) {
          if (*(short *)(param_1 + 0x12) == 1) {
            FUN_022d7d1c(DAT_022da800);
          }
          else {
            FUN_022d7d1c(0);
          }
          *(undefined2 *)(*DAT_022da804 + 0x358) = *(undefined2 *)(param_1 + 0x14);
        }
        else {
          FUN_022d7d1c(0x8000);
          FUN_022d7cf0(2);
        }
        uVar1 = 0;
      }
      else {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

