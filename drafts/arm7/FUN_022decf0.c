// decomp: module=arm7 addr=0x022decf0 name=FUN_022decf0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022decf0 --addr 0x022decf0 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022decf0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_022ded70;
  iVar2 = iVar1 + 0x42c + param_1 * 0x14;
  func_0x037c9084(0x1000000);
  *DAT_022ded78 = *(undefined2 *)(DAT_022ded74 + param_1 * 2);
  if (*(short *)(iVar1 + 0x42c + param_1 * 0x14) != 0) {
    if ((*(ushort *)(*(int *)(iVar2 + 0xc) + 0x14) & 0x4000) == 0) {
      *(undefined2 *)(*(int *)(iVar2 + 0xc) + 0xc) = *(undefined2 *)(*(int *)(iVar2 + 8) + 4);
    }
    *(undefined2 *)(*(int *)(iVar2 + 0xc) + 0x2a) = *(undefined2 *)(*(int *)(iVar2 + 8) + 0x22);
  }
  func_0x037c904c();
  return;
}

