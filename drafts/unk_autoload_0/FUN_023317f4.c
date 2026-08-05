// decomp: module=unk_autoload_0 addr=0x023317f4 name=FUN_023317f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, arm
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023317f4 --addr 0x023317f4 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_023317f4(uint param_1)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Translation_table_base_0();
  coproc_moveto_Translation_table_base_0(uVar1 & ~param_1);
  return;
}

