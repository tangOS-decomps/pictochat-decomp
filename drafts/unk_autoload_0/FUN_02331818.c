// decomp: module=unk_autoload_0 addr=0x02331818 name=FUN_02331818
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x10, arm
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02331818 --addr 0x02331818 --size 0x10 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331818(uint param_1)

{
  uint uVar1;
  
  uVar1 = coproc_movefrom_Domain_Access_Control();
  coproc_moveto_Domain_Access_Control(uVar1 | param_1);
  return;
}

