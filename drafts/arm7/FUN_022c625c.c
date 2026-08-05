// decomp: module=arm7 addr=0x022c625c name=FUN_022c625c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=18
// verify:  python tools/match.py --c <file> --func FUN_022c625c --addr 0x022c625c --size 0xa4 --module arm7 --version 2.0/sp1


undefined8 FUN_022c625c(void)

{
  ushort uVar1;
  bool bVar2;
  uint local_c;
  uint local_8;
  
  FUN_022c6d40();
  uVar1 = *DAT_022c62f4;
  local_c = *(uint *)(DAT_022c62f8 + 8) & DAT_022c62fc - 0x10000;
  local_8 = *(uint *)(DAT_022c62f8 + 0xc) & DAT_022c62fc;
  if (((*(uint *)(DAT_022c62f4 + 0x8a) & 8) != 0) && ((uVar1 & 0x8000) == 0)) {
    bVar2 = 0xfffffffe < local_c;
    local_c = local_c + 1;
    local_8 = local_8 + bVar2;
  }
  FUN_022c6d54();
  return CONCAT44(local_8 << 0x10 | local_c >> 0x10,(uint)uVar1 | local_c << 0x10);
}

