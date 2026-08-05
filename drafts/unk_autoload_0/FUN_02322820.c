// decomp: module=unk_autoload_0 addr=0x02322820 name=FUN_02322820
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02322820 --addr 0x02322820 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322820(void)

{
  undefined4 in_r3;
  
  FUN_02337424(DAT_0232283c,DAT_02322840,(uint)*(byte *)(DAT_0232283c + 0x14) << 1,in_r3,in_r3);
  *(undefined2 *)(DAT_02322840 + (uint)*(byte *)(DAT_0232283c + 0x14) * 2) = 0;
  return;
}

