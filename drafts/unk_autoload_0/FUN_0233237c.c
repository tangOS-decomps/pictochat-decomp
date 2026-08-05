// decomp: module=unk_autoload_0 addr=0x0233237c name=FUN_0233237c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0233237c --addr 0x0233237c --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233237c(void)

{
  int iVar1;
  
  iVar1 = DAT_02332390;
  *(undefined4 *)(DAT_02332390 + 0x14) = 0xfffffffd;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}

