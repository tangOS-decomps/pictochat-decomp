// decomp: module=unk_autoload_0 addr=0x02326718 name=FUN_02326718
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02326718 --addr 0x02326718 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


int FUN_02326718(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(DAT_02326738 + 4) == 0x380) {
    iVar1 = *(int *)(DAT_02326738 + 0x20);
  }
  if (param_1 < iVar1) {
    param_1 = param_1 + 0x400;
  }
  return param_1;
}

