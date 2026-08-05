// decomp: module=unk_autoload_0 addr=0x02331dac name=FUN_02331dac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02331dac --addr 0x02331dac --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331dac(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02332080();
  if (*DAT_02331dd0 != 0) {
    FUN_02331bfc(1);
    *DAT_02331dd0 = 0;
  }
  FUN_02332094(uVar1);
  return;
}

