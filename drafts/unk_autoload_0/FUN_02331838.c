// decomp: module=unk_autoload_0 addr=0x02331838 name=FUN_02331838
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=5
// verify:  python tools/match.py --c <file> --func FUN_02331838 --addr 0x02331838 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02331838(int param_1,undefined4 param_2)

{
  (**(code **)(DAT_02331850 + param_1 * 4))(param_2);
  return;
}

