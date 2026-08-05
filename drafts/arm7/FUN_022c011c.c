// decomp: module=arm7 addr=0x022c011c name=FUN_022c011c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x118 (Ghidra's cache says 0xf8 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=56
// verify:  python tools/match.py --c <file> --func FUN_022c011c --addr 0x022c011c --size 0x118 --module arm7 --version 2.0/sp1


void FUN_022c011c(void)

{
  undefined4 *puVar1;
  ushort *puVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  
  iVar5 = DAT_022c0218;
  if ((*DAT_022c0214 & 0x80000000) != 0) {
    *(undefined2 *)(DAT_022c0218 + 8) = *DAT_022c021c;
    *(byte *)(iVar5 + 9) = *DAT_022c0220 | (byte)((*DAT_022c0224 & 0x80) >> 1);
  }
  puVar1 = DAT_022c0228;
  iVar5 = DAT_022c0218;
  *DAT_022c0228 = *(undefined4 *)(DAT_022c0218 + 4);
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(iVar5 + 8);
  puVar2 = DAT_022c022c;
  uVar4 = 0;
  puVar6 = DAT_022c022c + -0x200000;
  do {
    *puVar2 = (ushort)uVar4;
    if (uVar4 != *puVar6) {
      iVar5 = 0;
      goto LAB_022c01a8;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 2);
  uVar3 = 1;
  goto LAB_022c01f8;
  while (iVar5 = iVar5 + 1, iVar5 != 2) {
LAB_022c01a8:
    *puVar2 = (ushort)iVar5;
    if (iVar5 != *(int *)(puVar2 + -0x400000)) {
      iVar5 = 0;
      goto LAB_022c01d4;
    }
  }
  uVar3 = 2;
  goto LAB_022c01f8;
  while (iVar5 = iVar5 + 1, iVar5 != 2) {
LAB_022c01d4:
    *puVar2 = (ushort)iVar5;
    if (iVar5 != *(int *)(puVar2 + 0x5800000)) {
      uVar3 = 4;
      goto LAB_022c01f8;
    }
  }
  uVar3 = 8;
LAB_022c01f8:
  if ((*DAT_022c0230 & 0xa000) == 0x8000) {
    uVar3 = uVar3 | 0x8000;
  }
  *puVar2 = uVar3;
  return;
}

