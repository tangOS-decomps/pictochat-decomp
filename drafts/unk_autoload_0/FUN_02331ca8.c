// decomp: module=unk_autoload_0 addr=0x02331ca8 name=FUN_02331ca8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02331ca8 --addr 0x02331ca8 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_02331ca8(void)

{
  ushort uVar1;
  bool bVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_02332080();
  uVar1 = *DAT_02331d0c;
  local_14 = *(uint *)(DAT_02331d14 + 8);
  local_10 = DAT_02331d10 & *(uint *)(DAT_02331d14 + 0xc);
  if ((*DAT_02331d18 & 8) != 0) {
    if ((uVar1 & 0x8000) == 0) {
      bVar2 = 0xfffffffe < local_14;
      local_14 = local_14 + 1;
      local_10 = local_10 + bVar2;
    }
  }
  FUN_02332094();
  return CONCAT44(local_10 << 0x10 | local_14 >> 0x10,local_14 * 0x10000 | (uint)uVar1);
}

