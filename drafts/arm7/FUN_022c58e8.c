// decomp: module=arm7 addr=0x022c58e8 name=FUN_022c58e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=19
// verify:  python tools/match.py --c <file> --func FUN_022c58e8 --addr 0x022c58e8 --size 0x60 --module arm7 --version 2.0/sp1


void FUN_022c58e8(void *param_1)

{
  undefined4 uVar1;
  void *o;
  int iVar2;
  
  uVar1 = FUN_022c6d40();
  o = *(void **)(DAT_022c5944 + 4);
  if (*(void **)((int)param_1 + 8) == o) {
    iVar2 = *(int *)((int)param_1 + 0xc) + -1;
    *(int *)((int)param_1 + 0xc) = iVar2;
    if (iVar2 == 0) {
      FUN_022c59a4(o,param_1);
      *(undefined4 *)((int)param_1 + 8) = 0;
      FUN_022c52c8(param_1);
    }
  }
  FUN_022c6d54(uVar1);
  return;
}

