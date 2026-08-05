// decomp: module=arm7 addr=0x022c8bf0 name=FUN_022c8bf0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022c8bf0 --addr 0x022c8bf0 --size 0x24 --module arm7 --version 2.0/sp1


void FUN_022c8bf0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_022c8c10;
  puVar2 = (undefined4 *)(param_1 & 0xfffffffc);
  *(undefined4 **)(DAT_022c8c10 + 4) = puVar2;
  *(undefined4 **)(iVar1 + 8) = puVar2 + 4;
  *(undefined4 *)(iVar1 + 0xc) = *puVar2;
  *(undefined4 *)(iVar1 + 0x10) = puVar2[1];
  *(undefined4 *)(iVar1 + 0x14) = puVar2[2];
  *(undefined4 *)(iVar1 + 0x18) = puVar2[3];
  return;
}

