// decomp: module=arm7 addr=0x022d914c name=FUN_022d914c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_022d914c --addr 0x022d914c --size 0xa0 --module arm7 --version 2.0/sp1


void FUN_022d914c(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_022d91e4;
  *(ushort *)(*DAT_022d91e4 + 0x33e) = *(ushort *)(*DAT_022d91e4 + 0x33e) | 0x8000;
  iVar1 = DAT_022d91e8;
  if (*(short *)(*piVar2 + 0x34c) != 0) {
    func_0x037c6220();
    piVar2 = DAT_022d91e4;
    if (*(short *)(*DAT_022d91e4 + 0x404) != 0) {
      *(undefined2 *)(*DAT_022d91e4 + 0x404) = 0;
      *(undefined2 *)(*(int *)(*piVar2 + 0x420) + 4) = 6;
      FUN_022dbb30();
    }
    FUN_022d7d30();
    iVar1 = DAT_022d91e8;
  }
  do {
    iVar3 = func_0x037c56e0(3);
  } while (iVar3 != iVar1);
  func_0x037c5628(3,0x17);
  return;
}

