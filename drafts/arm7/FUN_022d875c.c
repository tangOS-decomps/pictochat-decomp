// decomp: module=arm7 addr=0x022d875c name=FUN_022d875c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022d875c --addr 0x022d875c --size 0x38 --module arm7 --version 2.0/sp1


void FUN_022d875c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_022d8790;
  uVar4 = 0;
  do {
    iVar1 = uVar4 * 4;
    iVar2 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(undefined2 *)(&DAT_04808000 + *(ushort *)(iVar3 + iVar1)) = *(undefined2 *)(iVar3 + iVar2 + 2)
    ;
  } while (uVar4 < 0x19);
  return;
}

