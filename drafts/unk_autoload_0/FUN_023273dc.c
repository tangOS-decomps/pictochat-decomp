// decomp: module=unk_autoload_0 addr=0x023273dc name=FUN_023273dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_023273dc --addr 0x023273dc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_023273dc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_023273f8;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x5c;
    iVar3 = iVar3 + 1;
    *(undefined1 *)(iVar1 + iVar2 + 0x59) = 0;
  } while (iVar3 < 10);
  return;
}

