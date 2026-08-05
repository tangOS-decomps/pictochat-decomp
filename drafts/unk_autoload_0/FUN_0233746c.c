// decomp: module=unk_autoload_0 addr=0x0233746c name=FUN_0233746c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c, arm
// triage: noise=2 statements=21
// verify:  python tools/match.py --c <file> --func FUN_0233746c --addr 0x0233746c --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_0233746c(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)param_2 + param_3;
  iVar2 = (int)param_2 + (param_3 & 0xffffffe0);
  for (; (int)param_2 < iVar2; param_2 = param_2 + 8) {
    *param_2 = param_1;
    param_2[1] = param_1;
    param_2[2] = param_1;
    param_2[3] = param_1;
    param_2[4] = param_1;
    param_2[5] = param_1;
    param_2[6] = param_1;
    param_2[7] = param_1;
  }
  for (; (int)param_2 < iVar1; param_2 = param_2 + 1) {
    *param_2 = param_1;
  }
  return;
}

