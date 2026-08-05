// decomp: module=unk_autoload_0 addr=0x023295ac name=FUN_023295ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=15
// verify:  python tools/match.py --c <file> --func FUN_023295ac --addr 0x023295ac --size 0x38 --module unk_autoload_0 --version 2.0/sp1


int FUN_023295ac(void)

{
  byte bVar1;
  int iVar2;
  undefined1 extraout_r1;
  
  iVar2 = DAT_023295d8;
  bVar1 = *(byte *)(DAT_023295d8 + 1);
  if (*(byte *)(DAT_023295d8 + 3) < 6) {
    *(byte *)(DAT_023295d8 + 3) = *(byte *)(DAT_023295d8 + 3) + 1;
    *(byte *)(iVar2 + 1) = bVar1 + 1;
    FUN_02335e0c(*(undefined1 *)(iVar2 + 1),6);
    *(undefined1 *)(DAT_023295d8 + 1) = extraout_r1;
  }
  return DAT_023295e0 + (uint)bVar1 * DAT_023295dc;
}

