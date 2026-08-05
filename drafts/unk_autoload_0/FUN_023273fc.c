// decomp: module=unk_autoload_0 addr=0x023273fc name=FUN_023273fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=29
// verify:  python tools/match.py --c <file> --func FUN_023273fc --addr 0x023273fc --size 0x78 --module unk_autoload_0 --version 2.0/sp1


int FUN_023273fc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_02327470;
  iVar2 = 0;
  do {
    if (9 < iVar2) {
      iVar2 = 0;
      while ((iVar3 = DAT_02327470, iVar2 < 10 &&
             (iVar3 = DAT_02327470 + iVar2 * 0x5c, *(char *)(iVar3 + 0x58) != '\0'))) {
        iVar2 = iVar2 + 1;
      }
      FUN_023374b8(param_1,iVar3,0x16);
      FUN_023216e0(iVar3 + 0x18,iVar3);
      *(undefined1 *)(iVar3 + 0x58) = 1;
LAB_02327462:
      *(undefined1 *)(iVar3 + 0x59) = 1;
      return iVar3 + 0x18;
    }
    iVar1 = FUN_02334680(iVar3 + iVar2 * 0x5c,param_1,10);
    if (iVar1 == 0) {
      iVar3 = DAT_02327470 + iVar2 * 0x5c;
      goto LAB_02327462;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

