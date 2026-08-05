// decomp: module=unk_autoload_0 addr=0x023371e4 name=FUN_023371e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=20
// verify:  python tools/match.py --c <file> --func FUN_023371e4 --addr 0x023371e4 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_023371e4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0233723c;
  if (param_4 != 0) {
    iVar2 = (param_1 * 3 + 2) * 4;
    do {
    } while ((*(uint *)(iVar2 + DAT_0233723c) & 0x80000000) != 0);
    if (param_5 == 0) {
      FUN_01ff81b4(param_1,param_3,param_2,param_4 >> 2 | 0x5000000,0x16);
    }
    else {
      FUN_01ff81b4(param_1,param_3,param_2,param_4 >> 2 | 0x85000000,0x12);
    }
    do {
    } while ((*(uint *)(iVar2 + iVar1) & 0x80000000) != 0);
  }
  return;
}

