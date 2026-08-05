// decomp: module=arm7 addr=0x022e00ec name=FUN_022e00ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=28
// verify:  python tools/match.py --c <file> --func FUN_022e00ec --addr 0x022e00ec --size 0xa4 --module arm7 --version 2.0/sp1


int FUN_022e00ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = *DAT_022e0188;
  FUN_022d8d40(param_1,1,iVar3,param_4,param_4);
  iVar2 = DAT_022e018c;
  iVar4 = 2;
  uVar5 = 0;
  do {
    if (((uint)*(ushort *)(iVar3 + 0x3a6) & 1 << (uVar5 & 0xff)) != 0) {
      uVar1 = *(ushort *)(iVar2 + uVar5 * 2);
      if (((uint)*(ushort *)(iVar3 + 0x3a4) & 1 << (uVar5 & 0xff)) == 0) {
        FUN_022d8d40(param_1 + iVar4,uVar1 & 0xff);
      }
      else {
        FUN_022d8d40(param_1 + iVar4,uVar1 & 0xff | 0x80);
      }
      iVar4 = iVar4 + 1;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  FUN_022d8d40(param_1 + 1,iVar4 - 2U & 0xff);
  return iVar4;
}

