// decomp: module=unk_autoload_0 addr=0x023328b8 name=FUN_023328b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=9
// verify:  python tools/match.py --c <file> --func FUN_023328b8 --addr 0x023328b8 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void FUN_023328b8(int *p)

{
  ushort *puVar1;
  
  puVar1 = DAT_023328dc;
  *DAT_023328dc = (ushort)(*p << 2) | *DAT_023328dc & 0xfff3;
  *puVar1 = (ushort)(p[1] << 4) | *puVar1 & 0xffef;
  return;
}

