// decomp: module=unk_autoload_0 addr=0x02327990 name=FUN_02327990
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0x10 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=6
// verify:  python tools/match.py --c <file> --func FUN_02327990 --addr 0x02327990 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


int FUN_02327990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_023279a4(*(undefined2 *)(DAT_023279a0 + 0xc),2,param_3,param_4,param_4);
  return iVar1 + 0x37;
}

