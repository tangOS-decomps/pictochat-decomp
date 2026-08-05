// decomp: module=arm7 addr=0x022c29d4 name=FUN_022c29d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf0 (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=29
// verify:  python tools/match.py --c <file> --func FUN_022c29d4 --addr 0x022c29d4 --size 0xf0 --module arm7 --version 2.0/sp1


void FUN_022c29d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = DAT_022c2abc;
  piVar1 = DAT_022c2ab8;
  iVar4 = *DAT_022c2ab8;
  *DAT_022c2abc = 0x1000;
  if (*(short *)(iVar4 + 0x468) != 0) {
    if ((((*(ushort *)(*piVar1 + 0x690) & 0x10) == 0 || param_1 == 0) ||
        (puVar2[0x102] != 3 && puVar2[0x102] != 5)) || (puVar2[0x53] != 0)) {
      FUN_022c0e48(0,0x10,puVar2,iVar4 + 0x42c,param_4);
    }
    else {
      iVar5 = *(int *)(iVar4 + 0x470);
      iVar4 = 0;
      for (uVar3 = (uint)*(ushort *)(iVar5 + 2); uVar3 != 0; uVar3 = uVar3 >> 1) {
        iVar4 = iVar4 + (uVar3 & 1);
      }
      func_0x00dd43a0(iVar4 * (*(ushort *)(iVar5 + 0x24) + 10) + 0xc0 +
                      (uint)*(ushort *)(iVar5 + 10) * 4 & 0xffff,DAT_022c2ac0);
      *(short *)(*DAT_022c2ab8 + 0x400) = *(short *)(*DAT_022c2ab8 + 0x400) + 1;
    }
  }
  return;
}

