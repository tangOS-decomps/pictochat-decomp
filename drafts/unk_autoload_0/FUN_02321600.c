// decomp: module=unk_autoload_0 addr=0x02321600 name=FUN_02321600
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02321600 --addr 0x02321600 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321600(undefined4 *param_1,uint param_2)

{
  undefined2 uVar1;
  
  FUN_0232e084(param_1,0);
  FUN_02321cf8(*DAT_02321630 & 7);
  uVar1 = (undefined2)((param_2 & 0x7fffff) >> 7);
  *(undefined2 *)(param_1 + 3) = uVar1;
  *(undefined2 *)((int)param_1 + 0xe) = uVar1;
  FUN_0233746c(0,param_1[5],0x10000);
  return;
}

