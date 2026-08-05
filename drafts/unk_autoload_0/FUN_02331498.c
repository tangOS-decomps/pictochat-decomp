// decomp: module=unk_autoload_0 addr=0x02331498 name=FUN_02331498
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34, arm
// triage: noise=6 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02331498 --addr 0x02331498 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331498(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coprocessor_moveto(0xf,0,2,uVar2 | uVar1,in_cr7,in_cr14);
      uVar1 = uVar1 + 0x20;
    } while ((int)uVar1 < 0x400);
    uVar2 = uVar2 + 0x40000000;
  } while (uVar2 != 0);
  return;
}

