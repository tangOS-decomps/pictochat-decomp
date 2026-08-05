// decomp: module=arm7 addr=0x022c720c name=FUN_022c720c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022c720c --addr 0x022c720c --size 0x68 --module arm7 --version 2.0/sp1


undefined4 FUN_022c720c(void)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  iVar1 = thunk_EXT_FUN_037fdc74();
  if ((iVar1 == 0) || (iVar1 = thunk_EXT_FUN_037fde60(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else if (*DAT_022c7264 == 0) {
    thunk_EXT_FUN_037fde70(DAT_022c7268);
    lVar3 = thunk_EXT_FUN_037fdcec();
    thunk_EXT_FUN_037fe01c
              (DAT_022c7268,(int)(lVar3 + (ulonglong)DAT_022c7270),
               (int)(lVar3 + (ulonglong)DAT_022c7270 >> 0x20),DAT_022c7270,0,DAT_022c726c,0);
    uVar2 = 1;
    *DAT_022c7264 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

