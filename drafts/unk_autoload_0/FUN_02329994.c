// decomp: module=unk_autoload_0 addr=0x02329994 name=FUN_02329994
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02329994 --addr 0x02329994 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329994(void)

{
  int iVar1;
  
  iVar1 = FUN_0232996c();
  if (iVar1 == 0) {
    return 0;
  }
  return DAT_023299a8;
}

