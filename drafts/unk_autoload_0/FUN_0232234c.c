// decomp: module=unk_autoload_0 addr=0x0232234c name=FUN_0232234c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=46
// verify:  python tools/match.py --c <file> --func FUN_0232234c --addr 0x0232234c --size 0xa4 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232234c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = *(int *)(PTR_DAT_023223d8 + 4);
  if ((*(uint *)PTR_DAT_023223d8 & 1) == 0) {
    if (iVar4 != 0x18) {
      *(int *)(PTR_DAT_023223d8 + 4) = iVar4 + 2;
    }
  }
  else if (iVar4 != 0) {
    *(int *)(PTR_DAT_023223d8 + 4) = iVar4 + -2;
  }
  puVar2 = PTR_DAT_023223e0;
  puVar1 = PTR_DAT_023223dc;
  iVar4 = 0;
  do {
    piVar6 = (int *)(puVar2 + iVar4 * 0x54);
    iVar5 = piVar6[2];
    if (piVar6[4] == 0) {
      if (iVar5 != 0) {
        piVar6[2] = iVar5 + -2;
      }
    }
    else if (iVar5 == 0x18) {
      piVar6[3] = (uint)((*(uint *)(puVar1 + iVar4 * 4) & *(uint *)PTR_DAT_023223d8) != 0);
      puVar3 = PTR_DAT_023223e4;
      if (piVar6[1] != -1) {
        *piVar6 = piVar6[1];
        FUN_02321684(piVar6 + 5,puVar3);
        piVar6[1] = -1;
      }
      piVar6[4] = 0;
    }
    else {
      piVar6[2] = iVar5 + 2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_02321328(PTR_DAT_023223e8,PTR_DAT_023223ec);
  return;
}

