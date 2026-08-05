// decomp: module=unk_autoload_0 addr=0x023298a0 name=FUN_023298a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=11
// verify:  python tools/match.py --c <file> --func FUN_023298a0 --addr 0x023298a0 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_023298a0(void)

{
  int iVar1;
  
  (**(code **)(DAT_023298bc + 0xc))(*(undefined4 *)(DAT_023298bc + 4));
  FUN_0232a304();
  FUN_02329c94();
  iVar1 = DAT_023298bc;
  *(undefined4 *)(DAT_023298bc + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

