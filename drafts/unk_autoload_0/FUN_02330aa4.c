// decomp: module=unk_autoload_0 addr=0x02330aa4 name=FUN_02330aa4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=21  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02330aa4 --addr 0x02330aa4 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


int FUN_02330aa4(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = LZCOUNT(*DAT_02330af4);
  if (iVar2 == 0x20) {
    puVar3 = DAT_02330af4 + 1;
    iVar2 = LZCOUNT(*puVar3);
    if (iVar2 == 0x20) {
      return DAT_02330af8;
    }
    iVar1 = 0x60;
  }
  else {
    iVar1 = 0x40;
    puVar3 = DAT_02330af4;
  }
  *puVar3 = *puVar3 & ~(0x80000000U >> iVar2);
  return iVar1 + iVar2;
}

