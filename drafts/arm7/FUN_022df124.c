// decomp: module=arm7 addr=0x022df124 name=FUN_022df124
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94 (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022df124 --addr 0x022df124 --size 0x94 --module arm7 --version 2.0/sp1


void FUN_022df124(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = *DAT_022df1ac;
  *(short *)(iVar3 + 0x456) = *(short *)(iVar3 + 0x456) + 1;
  if (*(short *)(iVar3 + 0x454) == 0) {
    *(undefined2 *)(iVar3 + 0x454) = 1;
    **(undefined2 **)(iVar3 + 0x45c) = 0;
    *(undefined2 *)(*(int *)(iVar3 + 0x45c) + 4) = 0;
    uVar2 = FUN_022d85b4();
    uVar1 = DAT_022df1b0;
    *(undefined2 *)(*(int *)(iVar3 + 0x45c) + 8) = uVar2;
    *DAT_022df1b4 = (ushort)(((*(uint *)(iVar3 + 0x45c) & uVar1) << 0xf) >> 0x10) | 0x8000;
  }
  else {
    *(undefined2 *)(*(int *)(iVar3 + 0x45c) + 4) = 0;
  }
  return;
}

