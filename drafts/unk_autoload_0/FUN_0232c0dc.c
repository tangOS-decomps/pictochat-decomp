// decomp: module=unk_autoload_0 addr=0x0232c0dc name=FUN_0232c0dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_0232c0dc --addr 0x0232c0dc --size 0x24 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232c0dc(void)

{
  int iVar1;
  
  iVar1 = FUN_0232b834(DAT_0232c0f8);
  if ((iVar1 != 0) && (*DAT_0232c0fc == 0)) {
    return 1;
  }
  return 0;
}

