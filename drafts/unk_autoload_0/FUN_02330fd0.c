// decomp: module=unk_autoload_0 addr=0x02330fd0 name=FUN_02330fd0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=8  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02330fd0 --addr 0x02330fd0 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330fd0(void)

{
  int iVar1;
  
  for (iVar1 = *(int *)(DAT_02330fe4 + 0x24); (iVar1 != 0 && (*(int *)(iVar1 + 100) != 1));
      iVar1 = *(int *)(iVar1 + 0x68)) {
  }
  return;
}

