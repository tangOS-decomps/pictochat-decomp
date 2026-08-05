// decomp: module=unk_autoload_0 addr=0x02332134 name=FUN_02332134
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02332134 --addr 0x02332134 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332134(void)

{
  int iVar1;
  
  if (*DAT_02332180 != 0) {
    return;
  }
  *DAT_02332180 = 1;
  FUN_023381f8();
  do {
    iVar1 = FUN_023382f8(0xc,1);
  } while (iVar1 == 0);
  FUN_023382ac(0xc,DAT_02332184);
  return;
}

