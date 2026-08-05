// decomp: module=unk_autoload_0 addr=0x02325774 name=FUN_02325774
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02325774 --addr 0x02325774 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325774(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_023257b0;
  iVar4 = 0;
  do {
    iVar5 = 0;
    do {
      sVar1 = (short)iVar5;
      iVar3 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      *(short *)(iVar2 + iVar4 * 0x40 + iVar3) = sVar1 + (short)iVar4 * 0x20;
    } while (iVar5 < 0x20);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  FUN_023314e8(DAT_023257b0,0x800,iVar2,iVar4,in_r3);
  FUN_02336a84(DAT_023257b0,0,0x800);
  return;
}

