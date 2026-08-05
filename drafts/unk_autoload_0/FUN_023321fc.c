// decomp: module=unk_autoload_0 addr=0x023321fc name=FUN_023321fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_023321fc --addr 0x023321fc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_023321fc(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = 0;
  *DAT_02332214 = 0;
  puVar2 = DAT_02332218;
  do {
    iVar1 = iVar1 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 9);
  return;
}

