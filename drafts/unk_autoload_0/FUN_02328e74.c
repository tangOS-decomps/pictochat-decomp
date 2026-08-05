// decomp: module=unk_autoload_0 addr=0x02328e74 name=FUN_02328e74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02328e74 --addr 0x02328e74 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_02328e74(int param_1)

{
  *DAT_02328ea0 = 0;
  if (param_1 != 0) {
    FUN_0232a428();
  }
  FUN_0233746c(0,DAT_02328ea4,0x580);
  FUN_023314e8(DAT_02328ea4,0x580);
  FUN_02329524();
  return;
}

