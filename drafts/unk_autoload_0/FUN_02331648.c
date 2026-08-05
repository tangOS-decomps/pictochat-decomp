// decomp: module=unk_autoload_0 addr=0x02331648 name=FUN_02331648
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30, thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02331648 --addr 0x02331648 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331648(void)

{
  undefined4 uVar1;
  
  FUN_023311d8();
  uVar1 = FUN_02331678(2);
  FUN_0233178c(2,uVar1);
  uVar1 = FUN_02331718(2);
  FUN_02331798(2,uVar1);
  FUN_023318d4(1,0x2000000,0x2a);
  return;
}

