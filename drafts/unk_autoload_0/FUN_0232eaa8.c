// decomp: module=unk_autoload_0 addr=0x0232eaa8 name=FUN_0232eaa8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x118 (Ghidra's cache says 0x108 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=52
// verify:  python tools/match.py --c <file> --func FUN_0232eaa8 --addr 0x0232eaa8 --size 0x118 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232eaa8(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int b;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint b_00;
  
  uVar5 = FUN_02337eb4();
  iVar6 = FUN_0232e178(DAT_0232ebb0,0);
  iVar4 = DAT_0232ebb4;
  while (b = iVar6, b != 0) {
    iVar6 = FUN_0232e178(DAT_0232ebb0,b);
    if ((*(char *)(b + 0x2d) == '\0') &&
       (iVar7 = FUN_02337ccc(*(undefined4 *)(b + 0x30)), iVar7 != 0)) {
      *(undefined1 *)(b + 0x2d) = 1;
    }
    if ((*(char *)(b + 0x2d) == '\0') || ((uVar5 & 1 << (uint)*(byte *)(b + 0x3c)) != 0)) {
      FUN_023305c8((int *)(b + 0x1c));
      sVar1 = *(short *)(iVar4 + (uint)*(byte *)(b + 0x41) * 2);
      sVar2 = *(short *)(iVar4 + (uint)*(byte *)(b + 0x40) * 2);
      sVar3 = *(short *)(iVar4 + (uint)*(byte *)(*(int *)(b + 4) + 0x20) * 2);
      iVar7 = FUN_023305a8(b + 0x1c);
      uVar8 = (int)*(short *)(iVar4 + (iVar7 >> 8) * 2) + (int)sVar3 + (int)sVar2 + (int)sVar1;
      b_00 = DAT_0232ebb8;
      if (((int)DAT_0232ebb8 <= (int)uVar8) &&
         (b_00 = uVar8, (int)(DAT_0232ebb8 >> 0x11) < (int)uVar8)) {
        b_00 = DAT_0232ebbc;
      }
      if (b_00 != (int)*(short *)(b + 0x3e)) {
        FUN_02337710((uint)*(byte *)(b + 0x3c),b_00);
        *(short *)(b + 0x3e) = (short)b_00;
      }
      if ((*(char *)(b + 0x2c) == '\x02') && (iVar7 = FUN_023305d8((int *)(b + 0x1c)), iVar7 != 0))
      {
        FUN_0232ed94(b);
      }
      if (*(char *)(b + 0x2f) != '\0') {
        FUN_023376fc((uint)*(byte *)(b + 0x3c));
        *(undefined1 *)(b + 0x2f) = 0;
      }
    }
    else {
      FUN_0232ee10(b);
    }
  }
  return;
}

