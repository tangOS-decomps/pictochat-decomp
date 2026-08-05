// decomp: module=arm7 addr=0x022c8dcc name=FUN_022c8dcc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_022c8dcc --addr 0x022c8dcc --size 0x1e --module arm7 --version 2.0/sp1


void FUN_022c8dcc(int param_1)

{
  undefined4 *p;
  
  for (p = *(undefined4 **)(param_1 + 0x3c); p != (undefined4 *)0x0; p = (undefined4 *)p[0x14]) {
    FUN_022c83d0(p);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}

