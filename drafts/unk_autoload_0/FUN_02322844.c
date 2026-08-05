// decomp: module=unk_autoload_0 addr=0x02322844 name=FUN_02322844
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=7
// verify:  python tools/match.py --c <file> --func FUN_02322844 --addr 0x02322844 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02322844(void)

{
  undefined4 in_r3;
  
  FUN_02337424(DAT_02322868,DAT_0232286c,(uint)*(byte *)(DAT_02322868 + 0x34) << 1,in_r3,in_r3);
  *(undefined2 *)(DAT_0232286c + (uint)*(byte *)(DAT_02322868 + 0x34) * 2) = 0;
  return;
}

