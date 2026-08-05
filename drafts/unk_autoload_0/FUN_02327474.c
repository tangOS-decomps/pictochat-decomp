// decomp: module=unk_autoload_0 addr=0x02327474 name=FUN_02327474
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02327474 --addr 0x02327474 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327474(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_023274b0;
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x5c;
    if ((*(char *)(iVar1 + iVar2 + 0x58) != '\0') && (*(char *)(iVar1 + iVar2 + 0x59) == '\0')) {
      FUN_0233746c(0,iVar1 + iVar2,0x16);
      *(undefined1 *)(iVar1 + iVar2 + 0x58) = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  return;
}

