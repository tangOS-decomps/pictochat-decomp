// decomp: module=unk_autoload_0 addr=0x023277ec name=FUN_023277ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x7a - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=25
// verify:  python tools/match.py --c <file> --func FUN_023277ec --addr 0x023277ec --size 0x88 --module unk_autoload_0 --version 2.0/sp1


undefined * FUN_023277ec(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar5 = *(ushort *)(PTR_DAT_02327868 + 0x10) + 0x15;
  while( true ) {
    if (*(int *)PTR_DAT_0232786c <= iVar2) {
      return (undefined *)0x0;
    }
    iVar4 = iVar2 * 0x94;
    iVar1 = (int)(*(ushort *)(PTR_DAT_02327870 + iVar4 + 0x5c) + 2) >> 3;
    iVar3 = *(ushort *)(PTR_DAT_02327870 + iVar4 + 0x90) + 0x1b + (iVar1 + 1) * 8;
    if ((int)((*(ushort *)(PTR_DAT_02327870 + iVar4 + 0x5c) + 7 & 0xfffffff8) + iVar1 * -8) < 4) {
      iVar3 = iVar3 + -4;
    }
    if ((iVar5 < param_1) && (param_1 <= iVar3)) break;
    iVar2 = iVar2 + 1;
    iVar5 = iVar3;
  }
  return PTR_DAT_02327870 + iVar4;
}

