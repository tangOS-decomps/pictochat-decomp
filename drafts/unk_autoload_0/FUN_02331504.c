// decomp: module=unk_autoload_0 addr=0x02331504 name=FUN_02331504
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, arm
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02331504 --addr 0x02331504 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331504(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffffffe0;
  do {
    coproc_moveto_Data_Synchronization(0);
    coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar1);
    uVar1 = uVar1 + 0x20;
  } while ((int)uVar1 < (int)(param_2 + param_1));
  return;
}

