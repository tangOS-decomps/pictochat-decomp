// decomp: module=unk_autoload_0 addr=0x02325960 name=FUN_02325960
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02325960 --addr 0x02325960 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02325960(int param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + DAT_02325988);
  if (uVar1 == 4) {
    return 0;
  }
  if (0x3d < (uint)*(ushort *)(param_1 + DAT_02325988 + 2) + (uint)uVar1 * 0x10) {
    return 0;
  }
  *(ushort *)(param_1 + DAT_02325988) = uVar1 + 1;
  return 1;
}

