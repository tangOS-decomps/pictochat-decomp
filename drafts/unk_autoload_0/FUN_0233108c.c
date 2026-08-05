// decomp: module=unk_autoload_0 addr=0x0233108c name=FUN_0233108c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x20 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0233108c --addr 0x0233108c --size 0x24 --module unk_autoload_0 --version 2.0/sp1


int FUN_0233108c(void)

{
  int iVar1;
  int unaff_r4;
  
  FUN_02332080();
  iVar1 = *(int *)(DAT_023310ac + 4);
  if (iVar1 != -1) {
    *(int *)(DAT_023310ac + 4) = iVar1 + 1;
    unaff_r4 = iVar1;
  }
  FUN_02332094();
  return unaff_r4;
}

