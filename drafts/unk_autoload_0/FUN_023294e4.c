// decomp: module=unk_autoload_0 addr=0x023294e4 name=FUN_023294e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_023294e4 --addr 0x023294e4 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


int FUN_023294e4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_02329520;
  iVar3 = 0;
  while( true ) {
    if (0xf < iVar3) {
      return 0;
    }
    iVar4 = iVar1 + iVar3 * 0x58;
    if ((*(int *)(iVar4 + 0x54) != 0) && (iVar2 = FUN_02332e38(param_1,iVar4,6), iVar2 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return iVar4;
}

