// decomp: module=arm7 addr=0x022da71c name=FUN_022da71c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, arm
// triage: noise=3 statements=16
// verify:  python tools/match.py --c <file> --func FUN_022da71c --addr 0x022da71c --size 0x40 --module arm7 --version 2.0/sp1


undefined4 FUN_022da71c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(ushort *)(param_1 + 0x10) < 2) {
    func_0x037c6220(*(ushort *)(param_1 + 0x10));
    if (*(short *)(param_1 + 0x10) == 1) {
      FUN_022d81b8();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

