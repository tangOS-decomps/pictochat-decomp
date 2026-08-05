// decomp: module=unk_autoload_0 addr=0x02331804 name=FUN_02331804
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, arm
// triage: noise=8 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02331804 --addr 0x02331804 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331804(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr5;
  
  uVar1 = coprocessor_movefromRt(0xf,0,2,in_cr5,in_cr0);
  coprocessor_moveto(0xf,0,2,uVar1 & ~param_1 | param_2,in_cr5,in_cr0);
  return;
}

