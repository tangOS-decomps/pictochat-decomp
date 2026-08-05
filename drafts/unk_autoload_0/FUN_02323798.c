// decomp: module=unk_autoload_0 addr=0x02323798 name=FUN_02323798
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=30
// verify:  python tools/match.py --c <file> --func FUN_02323798 --addr 0x02323798 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02323798(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_20 [5];
  
  puVar4 = local_20;
  iVar3 = 2;
  puVar5 = DAT_023237dc;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar4 = *puVar5;
  if ((*DAT_023237e0 & 7) == 0) {
    local_20[0] = 1;
    local_20[1] = 0;
    local_20[2] = 2;
  }
  FUN_023236cc(local_20[param_1]);
  FUN_02320978(0x14);
  return;
}

