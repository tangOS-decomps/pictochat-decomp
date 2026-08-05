// decomp: module=unk_autoload_0 addr=0x023320ac name=FUN_023320ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14, arm
// triage: noise=10 statements=11
// verify:  python tools/match.py --c <file> --func FUN_023320ac --addr 0x023320ac --size 0x14 --module unk_autoload_0 --version 2.0/sp1


longlong FUN_023320ac(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  return (ulonglong)
         ((uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b | 0xc0) <<
         0x20;
}

