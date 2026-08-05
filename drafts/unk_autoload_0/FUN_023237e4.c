// decomp: module=unk_autoload_0 addr=0x023237e4 name=FUN_023237e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=30
// verify:  python tools/match.py --c <file> --func FUN_023237e4 --addr 0x023237e4 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_023237e4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_30 [5];
  undefined4 auStack_1c [5];
  
  puVar4 = local_30;
  iVar3 = 5;
  puVar5 = DAT_02323828;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((*DAT_0232382c & 7) == 0) {
    FUN_023236cc(local_30[*(int *)(DAT_02323830 + 0x34)]);
  }
  else {
    FUN_023236cc(auStack_1c[*(int *)(DAT_02323830 + 0x34)]);
  }
  FUN_02320978(0x14);
  return;
}

