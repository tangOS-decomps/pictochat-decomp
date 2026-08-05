// decomp: module=arm7 addr=0x022d8d6c name=FUN_022d8d6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, arm
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8d6c --addr 0x022d8d6c --size 0x1c --module arm7 --version 2.0/sp1


uint FUN_022d8d6c(ushort *param_1)

{
  uint uVar1;
  
  if (((uint)param_1 & 1) == 0) {
    uVar1 = (uint)*param_1;
  }
  else {
    uVar1 = (int)(uint)*(ushort *)((int)param_1 + -1) >> 8;
  }
  return uVar1 & 0xff;
}

