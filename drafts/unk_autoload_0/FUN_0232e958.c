// decomp: module=unk_autoload_0 addr=0x0232e958 name=FUN_0232e958
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232e958 --addr 0x0232e958 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e958(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = DAT_0232e97c;
  do {
    if (*(char *)(iVar2 + 0x2c) != '\0') {
      FUN_0232ec6c(iVar2,param_1);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x44;
  } while (iVar1 < 0x10);
  return;
}

