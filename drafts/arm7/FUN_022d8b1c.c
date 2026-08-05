// decomp: module=arm7 addr=0x022d8b1c name=FUN_022d8b1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022d8b1c --addr 0x022d8b1c --size 0x64 --module arm7 --version 2.0/sp1


void FUN_022d8b1c(uint param_1,undefined4 param_2)

{
  ulonglong uVar1;
  
  func_0x037cade0(*DAT_022d8b78 + 0x634);
  uVar1 = (ulonglong)DAT_022d8b7c * (ulonglong)param_1 >> 6;
  func_0x037cacfc(*DAT_022d8b78 + 0x634,(int)uVar1,(int)(uVar1 >> 0x20),param_2,0);
  return;
}

