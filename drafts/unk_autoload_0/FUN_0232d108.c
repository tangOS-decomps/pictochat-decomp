// decomp: module=unk_autoload_0 addr=0x0232d108 name=FUN_0232d108
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=20
// verify:  python tools/match.py --c <file> --func FUN_0232d108 --addr 0x0232d108 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d108(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  ushort *puVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  
  puVar2 = DAT_0232d150;
  puVar1 = DAT_0232d14c;
  DAT_0232d14c[5] = DAT_0232d148;
  *puVar1 = DAT_0232d154;
  puVar1[1] = DAT_0232d158;
  *puVar2 = (ushort)((uint)puVar2 >> 0xb) | *puVar2;
  uStack_c = param_4;
  FUN_023371d8(3);
  local_10 = 0;
  FUN_02332d32(&local_10,DAT_0232d154,DAT_0232d15c);
  *DAT_0232d160 = param_1;
  *DAT_0232d164 = 2;
  return;
}

