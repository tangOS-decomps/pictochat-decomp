// decomp: module=unk_autoload_0 addr=0x023228a4 name=FUN_023228a4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x88 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=32
// verify:  python tools/match.py --c <file> --func FUN_023228a4 --addr 0x023228a4 --size 0x9c --module unk_autoload_0 --version 2.0/sp1


void FUN_023228a4(void)

{
  short sVar1;
  uint uVar2;
  undefined4 in_r3;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_0232d9fc(DAT_0232292c,DAT_02322930,8,DAT_02322934,in_r3);
  FUN_023314e8(DAT_02322930,0x3a0);
  iVar3 = DAT_02322930;
  iVar4 = 0;
  do {
    FUN_02336940(iVar3 + iVar4 * 0x20,iVar4 * 0x80 + 0x1d000,0x20);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x1a);
  FUN_02336840(DAT_02322938,0x1f0,2);
  uVar5 = 0;
  do {
    uVar2 = 0;
    iVar3 = DAT_02322930 + uVar5 * 0x68;
    do {
      iVar4 = iVar3 + uVar2 * 8;
      *(uint *)(iVar4 + 0xaa0) = (uVar2 & 0x3f) * 0x80000 | (uVar5 & 0x1f) << 3;
      sVar1 = (short)uVar2;
      uVar2 = uVar2 + 1;
      *(ushort *)(iVar4 + DAT_0232293c) = sVar1 + (short)uVar5 * 0xd + 0x3a0U | 0xf000;
    } while ((int)uVar2 < 0xd);
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 2);
  return;
}

