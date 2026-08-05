// decomp: module=unk_autoload_0 addr=0x023310b0 name=FUN_023310b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023310b0 --addr 0x023310b0 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


int FUN_023310b0(void)

{
  int iVar1;
  int iVar2;
  
  FUN_02332080();
  iVar1 = *(int *)(DAT_023310d0 + 4);
  iVar2 = 0;
  if (iVar1 != 0) {
    *(int *)(DAT_023310d0 + 4) = iVar1 + -1;
    iVar2 = iVar1;
  }
  FUN_02332094();
  return iVar2;
}

