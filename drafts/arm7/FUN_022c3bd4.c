// decomp: module=arm7 addr=0x022c3bd4 name=FUN_022c3bd4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=13
// verify:  python tools/match.py --c <file> --func FUN_022c3bd4 --addr 0x022c3bd4 --size 0x7c --module arm7 --version 2.0/sp1


void FUN_022c3bd4(uint param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  int local_c;
  
  uVar1 = (ulonglong)DAT_022c3c48 * (ulonglong)param_1 >> 6;
  local_c = 1;
  uVar2 = FUN_022c3f7c((int)uVar1,(int)(uVar1 >> 0x20),1000,0);
  FUN_022c651c(*DAT_022c3c4c + 0x634,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_2,&local_c);
  do {
  } while (local_c != 0);
  return;
}

