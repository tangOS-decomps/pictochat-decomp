// decomp: module=arm7 addr=0x022d72cc name=FUN_022d72cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa0 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=42
// verify:  python tools/match.py --c <file> --func FUN_022d72cc --addr 0x022d72cc --size 0xa8 --module arm7 --version 2.0/sp1


undefined4 FUN_022d72cc(uint param_1)

{
  short sVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = *DAT_022d736c;
  if (param_1 < 2) {
    uVar5 = *(ushort *)(uVar4 + 0x33a) & 0xfffffffb | (param_1 & 1) << 2;
    *(short *)(uVar4 + 0x33a) = (short)uVar5;
    if (param_1 == 0) {
      uVar3 = *(ushort *)(uVar4 + 0x3c0) & 0xffdf;
    }
    else {
      uVar3 = *(ushort *)(uVar4 + 0x3c0) | 0x20;
    }
    *(ushort *)(uVar4 + 0x3c0) = uVar3;
    sVar1 = *(short *)(uVar4 + 0x34c);
    bVar6 = sVar1 == 0x40;
    if (bVar6) {
      uVar5 = *DAT_022d736c;
      sVar1 = *(short *)(uVar5 + 0x32e);
    }
    if (bVar6 && sVar1 == 1) {
      *(undefined2 *)(*(int *)(uVar5 + 0x4ac) + 0x2e) = *(undefined2 *)(uVar4 + 0x3c0);
    }
    if (param_1 == 0) {
      *DAT_022d7370 = *DAT_022d7370 & 0xfff9;
    }
    else {
      *DAT_022d7370 = *DAT_022d7370 | 6;
    }
    FUN_022d7c08();
    uVar2 = 0;
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

