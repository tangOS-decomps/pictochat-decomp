// decomp: module=unk_autoload_0 addr=0x02326bac name=FUN_02326bac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x7a - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=41
// verify:  python tools/match.py --c <file> --func FUN_02326bac --addr 0x02326bac --size 0x80 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02326bac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint a;
  int local_30 [6];
  char local_16;
  byte local_15;
  
  piVar4 = local_30;
  iVar1 = (int)*(uint *)(DAT_02326c28 + 0x14) >> 3;
  if ((*(uint *)(DAT_02326c28 + 0x14) & 3) == 0) {
    iVar1 = FUN_02326774(iVar1);
  }
  puVar5 = (undefined4 *)(*(int *)(DAT_02326c28 + 8) + iVar1 * 0x1c);
  iVar1 = 3;
  do {
    uVar2 = *puVar5;
    uVar3 = puVar5[1];
    puVar5 = puVar5 + 2;
    *piVar4 = uVar2;
    piVar4[1] = uVar3;
    piVar4 = piVar4 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *piVar4 = *puVar5;
  if ((local_30[0] == 0) || (local_16 == '\x10')) {
    uVar2 = 0;
  }
  else {
    a = (uint)(local_30[0] - *(int *)(DAT_02326c28 + 0xc)) >> 10;
    for (iVar1 = 0; iVar1 < (int)((uint)local_15 * 2); iVar1 = iVar1 + 1) {
      FUN_023257b4(param_1 + iVar1 * 0x400,*(int *)(DAT_02326c28 + 0xc) + a * 0x400,0x400);
      a = FUN_02326764(a);
    }
    uVar2 = 1;
  }
  return uVar2;
}

