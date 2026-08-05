// decomp: module=unk_autoload_0 addr=0x0233088c name=FUN_0233088c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=30
// verify:  python tools/match.py --c <file> --func FUN_0233088c --addr 0x0233088c --size 0x80 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233088c(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  
  if (*DAT_023308fc == 0) {
    *DAT_023308fc = 1;
    puVar2 = DAT_02330900;
    *DAT_02330900 = 0;
    FUN_02330938(0x7e,(int)puVar2,0);
    puVar3 = DAT_02330900;
    sVar1 = *(short *)((int)DAT_02330900 + 6);
    puVar2 = DAT_02330904;
    while (DAT_02330904 = puVar2, sVar1 != 0) {
      FUN_02332d10(0x400);
      puVar2 = DAT_02330904;
      sVar1 = *(short *)((int)puVar3 + 6);
    }
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffff0000;
    FUN_02337440(0,puVar2 + 4,0x28);
    puVar4 = DAT_02330908;
    *DAT_02330908 = (ushort)((uint)DAT_02330908 >> 0xf) | *DAT_02330908;
    *puVar4 = *puVar4 | 0x80;
    FUN_0233098c(0x7e,(int)DAT_02330900,0);
    FUN_02330938(0x7f,(int)DAT_02330900,0);
  }
  return;
}

