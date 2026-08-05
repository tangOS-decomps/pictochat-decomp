// decomp: module=unk_autoload_0 addr=0x0232b74c name=FUN_0232b74c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232b74c --addr 0x0232b74c --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b74c(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((code *)*DAT_0232b774 != (code *)0x0) {
    uVar1 = (*(code *)*DAT_0232b774)(param_2 * param_3,4);
    *param_1 = uVar1;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  param_1[1] = param_2;
  *(short *)(param_1 + 3) = (short)param_3;
  return;
}

