// decomp: module=arm7 addr=0x022c8d88 name=FUN_022c8d88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, thumb
// triage: noise=3 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022c8d88 --addr 0x022c8d88 --size 0x44 --module arm7 --version 2.0/sp1


void FUN_022c8d88(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  char *p;
  
  FUN_022c8ea8(param_1,param_2,0,param_4,param_4);
  for (p = *(char **)(param_1 + 0x3c); p != (char *)0x0; p = *(char **)(p + 0x50)) {
    iVar1 = FUN_022c8288((undefined4 *)p);
    if (iVar1 != 0) {
      if (-1 < (int)param_3) {
        FUN_022c826c(p,param_3 & 0xff);
      }
      p[0x22] = '\x01';
      FUN_022c8280(p);
    }
  }
  return;
}

