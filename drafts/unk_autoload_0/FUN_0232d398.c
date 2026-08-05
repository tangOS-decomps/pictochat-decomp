// decomp: module=unk_autoload_0 addr=0x0232d398 name=FUN_0232d398
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x22 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232d398 --addr 0x0232d398 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d398(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = DAT_0232d3c0;
  puVar1 = DAT_0232d3bc;
  *(undefined4 *)(DAT_0232d3c0 + 0x10) = *DAT_0232d3bc;
  piVar3 = puVar1 + 4;
  *(undefined4 *)(iVar2 + 0xc) = puVar1[1];
  if (*piVar3 != *(int *)(iVar2 + 8)) {
    *(int *)(iVar2 + 8) = *piVar3;
  }
  return;
}

