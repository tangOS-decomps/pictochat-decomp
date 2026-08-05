// decomp: module=arm7 addr=0x022ce808 name=FUN_022ce808
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022ce808 --addr 0x022ce808 --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022ce808(uint param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_022ce854 + 0x550);
  if (0x200 < param_1) {
    param_1 = 0x200;
  }
  sVar1 = (short)param_1;
  *(short *)(iVar2 + 0x36) = sVar1;
  *(short *)(iVar2 + 0x32) = sVar1;
  sVar1 = sVar1 + 2;
  if (*(short *)(iVar2 + 0x188) == 0) {
    *(short *)(iVar2 + 0x3e) = sVar1;
    *(short *)(iVar2 + 0x3a) = sVar1;
  }
  else {
    *(short *)(iVar2 + 0x3c) = sVar1;
    *(short *)(iVar2 + 0x38) = sVar1;
  }
  return;
}

