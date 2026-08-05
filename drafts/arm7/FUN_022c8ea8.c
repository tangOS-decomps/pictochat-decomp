// decomp: module=arm7 addr=0x022c8ea8 name=FUN_022c8ea8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xdc (Ghidra's cache says 0xd4 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=52
// verify:  python tools/match.py --c <file> --func FUN_022c8ea8 --addr 0x022c8ea8 --size 0xdc --module arm7 --version 2.0/sp1


void FUN_022c8ea8(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *p;
  
  iVar4 = (int)*(short *)(DAT_022c8f7c + (uint)*(byte *)(param_2 + 5) * 2) +
          (int)*(short *)(DAT_022c8f7c + (uint)*(byte *)(param_1 + 4) * 2) +
          (int)*(short *)(DAT_022c8f7c + (uint)*(byte *)(param_1 + 5) * 2);
  iVar5 = (int)*(short *)(param_1 + 10) + (int)*(short *)(param_2 + 6);
  cVar2 = *(char *)(param_1 + 6);
  bVar1 = *(byte *)(param_1 + 7);
  sVar3 = *(short *)(param_1 + 0xc);
  iVar6 = (int)*(char *)(param_1 + 8);
  if (*(byte *)(param_1 + 1) != 0x7f) {
    iVar6 = (int)(iVar6 * (uint)*(byte *)(param_1 + 1) + 0x40) >> 7;
  }
  iVar6 = iVar6 + *(char *)(param_1 + 9);
  if (iVar4 < DAT_022c8f80) {
    iVar4 = DAT_022c8f80;
  }
  if (iVar5 < DAT_022c8f80) {
    iVar5 = DAT_022c8f80;
  }
  iVar7 = -0x80;
  if ((-0x81 < iVar6) && (iVar7 = iVar6, 0x7f < iVar6)) {
    iVar7 = 0x7f;
  }
  for (p = *(char **)(param_1 + 0x3c); p != (char *)0x0; p = *(char **)(p + 0x50)) {
    *(short *)(p + 6) = (short)iVar5;
    if (p[2] != '\x03') {
      *(short *)(p + 0xc) = (short)iVar4;
      *(short *)(p + 0xe) =
           (short)((uint)((((int)((int)cVar2 * (uint)bVar1 * 0x40) >> 7) + (int)sVar3) * 0x10000) >>
                  0x10);
      p[0xb] = (char)iVar7;
      p[4] = *(char *)(param_1 + 1);
      *(undefined2 *)(p + 0x28) = *(undefined2 *)(param_1 + 0x18);
      *(undefined2 *)(p + 0x2a) = *(undefined2 *)(param_1 + 0x1a);
      *(undefined2 *)(p + 0x2c) = *(undefined2 *)(param_1 + 0x1c);
      if ((*(int *)(p + 0x34) == 0) && (param_3 != 0)) {
        p[0x22] = '\x01';
        FUN_022c8280(p);
      }
    }
  }
  return;
}

