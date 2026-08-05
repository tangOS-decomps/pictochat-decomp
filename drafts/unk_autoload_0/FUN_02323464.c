// decomp: module=unk_autoload_0 addr=0x02323464 name=FUN_02323464
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4a - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02323464 --addr 0x02323464 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_02323464(int param_1,short param_2,short param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_0233740c(DAT_023234b0,param_1,0x800);
  iVar4 = 0;
  do {
    iVar3 = 0;
    do {
      sVar1 = (short)iVar3;
      iVar2 = iVar3 * 2;
      iVar3 = iVar3 + 1;
      *(short *)(param_1 + iVar4 * 0x40 + iVar2) =
           param_2 * 0x1000 | sVar1 + param_3 + (short)iVar4 * 0x19;
    } while (iVar3 < 0x19);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xb);
  FUN_023314e8(param_1,0x800);
  return;
}

