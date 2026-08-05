// decomp: module=arm7 addr=0x022c2ac4 name=FUN_022c2ac4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10c (Ghidra's cache says 0xfc - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=38
// verify:  python tools/match.py --c <file> --func FUN_022c2ac4 --addr 0x022c2ac4 --size 0x10c --module arm7 --version 2.0/sp1


void FUN_022c2ac4(void)

{
  bool bVar1;
  short sVar2;
  int *piVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  puVar4 = DAT_022c2bc4;
  piVar3 = DAT_022c2bc0;
  iVar6 = *DAT_022c2bc0;
  *DAT_022c2bc4 = 0x80;
  if ((*(ushort *)(*piVar3 + 0x690) & 0x20) != 0) {
    if ((((2 < (puVar4[0x102] & 0xff)) && ((puVar4[0x102] & 0xff) < 6)) &&
        ((DAT_022c2bc8 & *(uint *)(iVar6 + 0x484) >> 1) <= (uint)(ushort)puVar4[300])) &&
       ((uint)(ushort)puVar4[300] <= (DAT_022c2bc8 & *(uint *)(iVar6 + 0x45c) >> 1))) {
      puVar5 = puVar4 + 0x11a;
      *puVar5 = *puVar5 | 0x80;
      *puVar5 = *puVar5 & 0xff7f;
    }
  }
  if ((*DAT_022c2bcc != 0x1440) && ((DAT_022c2bcc[0xce] & 0x42U) == 0x42)) {
    sVar2 = DAT_022c2bcc[0x15c];
    if (sVar2 != 0) {
      uVar7 = 0;
      do {
        if (sVar2 != DAT_022c2bcc[0x15c]) {
          return;
        }
        bVar1 = uVar7 < 0x3e9;
        uVar7 = uVar7 + 1;
      } while (bVar1);
      func_0x00dd48a8(0x40);
    }
  }
  return;
}

