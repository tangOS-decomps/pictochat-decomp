// decomp: module=arm7 addr=0x022d9f7c name=FUN_022d9f7c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x7c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022d9f7c --addr 0x022d9f7c --size 0x80 --module arm7 --version 2.0/sp1


void FUN_022d9f7c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *DAT_022d9ff8;
  FUN_022da1e4();
  uVar1 = FUN_022da0e8(param_1);
  if (uVar1 != 0) {
    *(undefined2 *)(param_1 * 0x1c + *(int *)(*DAT_022d9ff8 + 0x31c) + 2) = 0;
    *(ushort *)(iVar2 + 0x53a) = *(ushort *)(iVar2 + 0x53a) & ~(ushort)(1 << (uVar1 & 0xff));
    *(short *)(iVar2 + 0x538) = *(short *)(iVar2 + 0x538) + -1;
    if (*(short *)(iVar2 + 0x538) == 0) {
      FUN_022d7ed0();
    }
  }
  return;
}

