// decomp: module=unk_autoload_0 addr=0x02331204 name=FUN_02331204
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0xe - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=6
// verify:  python tools/match.py --c <file> --func FUN_02331204 --addr 0x02331204 --size 0x14 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02331204(void)

{
  ushort uVar1;
  
  uVar1 = FUN_02332120();
  return *(undefined4 *)(DAT_02331214 + (uint)uVar1 * 4);
}

