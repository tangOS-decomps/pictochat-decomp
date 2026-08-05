// decomp: module=unk_autoload_0 addr=0x0232f63c name=FUN_0232f63c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=27  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232f63c --addr 0x0232f63c --size 0x4c --module unk_autoload_0 --version 2.0/sp1


int FUN_0232f63c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(*DAT_0232f684 + 0x8c);
  iVar1 = *(int *)(iVar2 + 0x18);
  if (iVar1 == 0) {
    puVar3 = (uint *)0x0;
  }
  else {
    puVar3 = (uint *)(iVar2 + iVar1);
  }
  if (puVar3 == (uint *)0x0) {
    return 0;
  }
  if ((int)param_1 < 0) {
    return 0;
  }
  if (*puVar3 <= param_1) {
    return 0;
  }
  if (puVar3[param_1 + 1] == 0) {
    return 0;
  }
  return *(int *)(*DAT_0232f684 + 0x8c) + puVar3[param_1 + 1];
}

