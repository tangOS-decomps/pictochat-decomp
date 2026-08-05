// decomp: module=unk_autoload_0 addr=0x0233083c name=FUN_0233083c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0233083c --addr 0x0233083c --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0233083c(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_02330860;
  iVar2 = DAT_0233085c;
  iVar1 = DAT_02330854;
  *(undefined4 *)(DAT_02330854 + DAT_0233085c) = DAT_02330858;
  *(undefined4 *)((iVar1 + iVar2 + 4) - DAT_02330864) = uVar3;
  return;
}

