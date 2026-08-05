// decomp: module=unk_autoload_0 addr=0x023372b0 name=FUN_023372b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x66 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=21
// verify:  python tools/match.py --c <file> --func FUN_023372b0 --addr 0x023372b0 --size 0x6c --module unk_autoload_0 --version 2.0/sp1


void FUN_023372b0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_4 != 0) {
    FUN_023373c4(param_1,param_2,param_4,0);
    iVar1 = DAT_02337318;
    iVar2 = (param_1 * 3 + 2) * 4;
    do {
    } while ((*(uint *)(iVar2 + DAT_02337318) & 0x80000000) != 0);
    if (param_5 == 0) {
      FUN_01ff81b4(param_1,param_2,param_3,param_4 >> 1,6);
    }
    else {
      FUN_01ff81b4(param_1,param_2,param_3,param_4 >> 1 | 0x80000000,2);
    }
    do {
    } while ((*(uint *)(iVar2 + iVar1) & 0x80000000) != 0);
  }
  return;
}

