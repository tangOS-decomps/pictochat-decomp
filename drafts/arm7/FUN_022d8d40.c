// decomp: module=arm7 addr=0x022d8d40 name=FUN_022d8d40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, arm
// triage: noise=0 statements=10  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022d8d40 --addr 0x022d8d40 --size 0x2c --module arm7 --version 2.0/sp1


void FUN_022d8d40(ushort *param_1,ushort param_2)

{
  if (((uint)param_1 & 1) == 0) {
    *param_1 = *param_1 & 0xff00 | param_2 & 0xff;
  }
  else {
    *(ushort *)((int)param_1 + -1) = *(ushort *)((int)param_1 + -1) & 0xff | param_2 << 8;
  }
  return;
}

