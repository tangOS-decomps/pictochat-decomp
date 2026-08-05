// decomp: module=arm7 addr=0x022c0e48 name=FUN_022c0e48
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8 (Ghidra's cache says 0xb0 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022c0e48 --addr 0x022c0e48 --size 0xb8 --module arm7 --version 2.0/sp1


void FUN_022c0e48(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *DAT_022c0ef8;
  FUN_022c48a4(DAT_022c0efc);
  iVar2 = iVar4 + 0xbc + param_2 * 8;
  if (*(short *)(iVar2 + 2) == 0) {
    *(undefined2 *)(iVar2 + 2) = 1;
    *(undefined2 *)(iVar4 + 0xbc + param_2 * 8) = 0xffff;
    uVar3 = (uint)*(ushort *)(iVar4 + param_1 * 2 + 8);
    uVar1 = (undefined2)param_2;
    if (uVar3 == 0xffff) {
      *(undefined2 *)(iVar4 + param_1 * 2) = uVar1;
    }
    else {
      *(undefined2 *)(iVar4 + uVar3 * 8 + 0xbc) = uVar1;
    }
    *(undefined2 *)(iVar4 + param_1 * 2 + 8) = uVar1;
    if (param_1 < (int)(uint)*(ushort *)(iVar4 + 0x10)) {
      *(short *)(iVar4 + 0x10) = (short)param_1;
    }
  }
  FUN_022c486c();
  if ((param_1 != 3) && (*(short *)(iVar4 + 0x12) == 3)) {
    FUN_022c56b0(*(undefined4 *)(*DAT_022c0ef8 + 0x308),0,0);
  }
  return;
}

