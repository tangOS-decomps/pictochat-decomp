// decomp: module=arm7 addr=0x022c6ac4 name=FUN_022c6ac4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022c6ac4 --addr 0x022c6ac4 --size 0x74 --module arm7 --version 2.0/sp1


void FUN_022c6ac4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_022c6d40();
  if (param_1 == 0) {
    FUN_022c6e94();
  }
  iVar2 = *(int *)(DAT_022c6b34 + 0xc);
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x18);
  }
  while (iVar2 != 0) {
    if (*(int *)(iVar2 + 8) == param_1) {
      FUN_022c6a78();
    }
    iVar2 = iVar3;
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x18);
    }
  }
  FUN_022c6d54(uVar1);
  return;
}

