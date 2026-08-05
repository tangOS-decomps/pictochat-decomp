// decomp: module=unk_autoload_0 addr=0x0232be80 name=FUN_0232be80
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=18
// verify:  python tools/match.py --c <file> --func FUN_0232be80 --addr 0x0232be80 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232be80(undefined1 param_1)

{
  ushort uVar1;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined2 local_16;
  undefined1 local_10;
  
  local_1c = 3;
  local_1a = 0x14;
  uVar1 = FUN_0232a4e8();
  local_18 = (undefined1)uVar1;
  local_16 = (undefined2)DAT_0232bec0;
  local_10 = param_1;
  FUN_02337584(&local_1c,*(undefined4 *)(DAT_0232bec4 + 0xc),0x14);
  FUN_0232c100(0xd,*(undefined4 *)(DAT_0232bec4 + 0xc),0x14,1,DAT_0232bec8);
  return;
}

