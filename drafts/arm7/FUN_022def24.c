// decomp: module=arm7 addr=0x022def24 name=FUN_022def24
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=30
// verify:  python tools/match.py --c <file> --func FUN_022def24 --addr 0x022def24 --size 0xe8 --module arm7 --version 2.0/sp1


void FUN_022def24(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *DAT_022df008;
  sVar1 = *(short *)(iVar3 + 0x350);
  if (sVar1 == 1) {
    FUN_022df00c(0,1);
    FUN_022df00c(1,0);
    FUN_022df00c(2,1);
    if (*(short *)(iVar3 + 0x468) != 0) {
      *(undefined2 *)(iVar3 + 0x468) = 0;
      piVar2 = DAT_022df008;
      *(short *)(iVar3 + 0x46a) = *(short *)(iVar3 + 0x46a) + -1;
      func_0x037c5998(*piVar2 + 0x188,*(undefined4 *)(iVar3 + 0x4bc));
    }
  }
  else if (sVar1 == 2 || sVar1 == 3) {
    FUN_022df00c(0,1);
    FUN_022df00c(1,0);
    FUN_022df00c(2,0);
  }
  else {
    FUN_022df00c(0,0);
    FUN_022df00c(1,0);
    FUN_022df00c(2,0);
  }
  return;
}

