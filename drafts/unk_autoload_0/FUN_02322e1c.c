// decomp: module=unk_autoload_0 addr=0x02322e1c name=FUN_02322e1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x28 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02322e1c --addr 0x02322e1c --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322e1c(char *param_1)

{
  int iVar1;
  
  if (*param_1 == '\x01') {
    *(undefined **)PTR_DAT_02322e48 = PTR_DAT_02322e44;
    return;
  }
  iVar1 = FUN_02322e4c();
  if (iVar1 != 0) {
    *(char **)PTR_DAT_02322e48 = param_1;
    return;
  }
  *(undefined4 *)PTR_DAT_02322e48 = 0;
  return;
}

