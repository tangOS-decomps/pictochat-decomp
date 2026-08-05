// decomp: module=arm7 addr=0x022c4e28 name=FUN_022c4e28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xd4 (Ghidra's cache says 0xcc - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=31
// verify:  python tools/match.py --c <file> --func FUN_022c4e28 --addr 0x022c4e28 --size 0xd4 --module arm7 --version 2.0/sp1


void FUN_022c4e28(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  puVar1 = DAT_022c4ef8;
  if (DAT_022c4ef4[1] == 0) {
    if ((*(short *)((int)DAT_022c4ef4 + 0x1e) == 0) && (iVar2 = FUN_022c6d98(), iVar2 != 0x12)) {
      iVar5 = *(int *)DAT_022c4ef4[2];
      iVar2 = FUN_022c537c();
      if ((iVar5 != iVar2 && iVar2 != 0) &&
         ((*(int *)(iVar5 + 0x48) == 2 || (iVar3 = FUN_022c5628(iVar5), iVar3 == 0)))) {
        if ((code *)*DAT_022c4ef4 != (code *)0x0) {
          (*(code *)*DAT_022c4ef4)(iVar5,iVar2);
        }
        pcVar4 = *(code **)(puVar1 + 6);
        if (pcVar4 != (code *)0x0) {
          (*pcVar4)(iVar5,iVar2);
        }
        DAT_022c4ef4[8] = iVar2;
        FUN_022c565c(iVar2);
      }
    }
    else {
      *puVar1 = 1;
    }
  }
  return;
}

