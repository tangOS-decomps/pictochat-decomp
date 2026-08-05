// decomp: module=unk_autoload_0 addr=0x0232d9fc name=FUN_0232d9fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232d9fc --addr 0x0232d9fc --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d9fc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 auStack_110 [256];
  
  *(uint *)(DAT_0232da30 + 4) = *(uint *)(DAT_0232da30 + 4) & 0x80000000 | param_3 - 1U & 0x7fffffff
  ;
  FUN_0232da34(param_1,param_4,auStack_110);
  FUN_023374b8(param_4,param_2,0x340);
  return;
}

