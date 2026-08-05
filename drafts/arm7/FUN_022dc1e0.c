// decomp: module=arm7 addr=0x022dc1e0 name=FUN_022dc1e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022dc1e0 --addr 0x022dc1e0 --size 0x40 --module arm7 --version 2.0/sp1


undefined4 FUN_022dc1e0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = DAT_022dc21c;
  uVar2 = 1;
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(short *)(*piVar1 + 0x34c) == 0x10) {
    uVar2 = FUN_022d6e98(param_1 + 0x10);
  }
  return uVar2;
}

