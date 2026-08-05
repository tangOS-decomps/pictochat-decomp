// decomp: module=arm7 addr=0x022d7398 name=FUN_022d7398
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, arm
// triage: noise=2 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022d7398 --addr 0x022d7398 --size 0x44 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7398(uint param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_2 < 0x40) {
      FUN_022d862c(0x13,param_1);
      FUN_022d862c(0x35,param_2);
      uVar1 = 0;
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

