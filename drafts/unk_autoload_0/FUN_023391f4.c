// decomp: module=unk_autoload_0 addr=0x023391f4 name=FUN_023391f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023391f4 --addr 0x023391f4 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023391f4(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint local_1c;
  uint local_18;
  
  local_1c = DAT_02339244;
  FUN_023391a0(&local_1c,1,param_3,param_4,param_2);
  do {
    iVar1 = FUN_023396c0(0,2,0,1);
  } while (iVar1 != 1);
  local_1c = DAT_02339248 | param_1 & 0xff;
  local_18 = DAT_0233924c | param_2 & 0xffff;
  FUN_023391a0(&local_1c,2);
  return 0;
}

