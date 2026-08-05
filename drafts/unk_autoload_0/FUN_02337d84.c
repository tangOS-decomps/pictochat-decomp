// decomp: module=unk_autoload_0 addr=0x02337d84 name=FUN_02337d84
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337d84 --addr 0x02337d84 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02337d84(void)

{
  int iVar1;
  
  FUN_023382ac(7,DAT_02337dbc);
  iVar1 = FUN_02337e08();
  if (iVar1 != 0) {
    iVar1 = FUN_023382f8(7,1);
    while (iVar1 == 0) {
      FUN_023320fc(0x32);
      iVar1 = FUN_023382f8(7,1);
    }
  }
  return;
}

