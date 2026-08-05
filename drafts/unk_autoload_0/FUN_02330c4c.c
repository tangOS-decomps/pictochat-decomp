// decomp: module=unk_autoload_0 addr=0x02330c4c name=FUN_02330c4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x6a - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02330c4c --addr 0x02330c4c --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330c4c(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  puVar1 = DAT_02330cbc;
  if (DAT_02330cb8[1] == 0) {
    if ((*(short *)((int)DAT_02330cb8 + 0x1e) != 0) || (iVar2 = FUN_023320e4(), iVar2 == 0x12)) {
      *puVar1 = 1;
      return;
    }
    iVar5 = *(int *)DAT_02330cb8[2];
    iVar2 = FUN_02330fd0();
    if (((iVar5 != iVar2) && (iVar2 != 0)) &&
       ((*(int *)(iVar5 + 100) == 2 || (iVar3 = FUN_02331148(iVar5), iVar3 == 0)))) {
      if ((code *)*DAT_02330cb8 != (code *)0x0) {
        (*(code *)*DAT_02330cb8)(iVar5,iVar2);
      }
      pcVar4 = *(code **)(puVar1 + 6);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(iVar5,iVar2);
      }
      DAT_02330cb8[8] = iVar2;
      FUN_02331194(iVar2);
    }
  }
  return;
}

