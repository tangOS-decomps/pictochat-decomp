// decomp: module=unk_autoload_0 addr=0x02322c4c name=FUN_02322c4c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x5a - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=26
// verify:  python tools/match.py --c <file> --func FUN_02322c4c --addr 0x02322c4c --size 0x6c --module unk_autoload_0 --version 2.0/sp1


void FUN_02322c4c(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_DAT_02322ca8;
  uVar4 = 0;
  iVar3 = *(int *)PTR_DAT_02322ca8;
  if (iVar3 != -1) {
    iVar2 = *(int *)(PTR_DAT_02322cac + 0x14) + 1;
    *(int *)(PTR_DAT_02322cac + 0x14) = iVar2;
    if (iVar3 == 0) {
      uVar4 = FUN_02335e0c((*(int *)(puVar1 + 4) - iVar2) * 0x10);
    }
    else if (iVar3 == 1) {
      uVar4 = FUN_02335e0c(iVar2 * 0x10,*(undefined4 *)(puVar1 + 4));
    }
    FUN_02336404(DAT_02322cb0,uVar4);
    FUN_02336404(DAT_02322cb4,uVar4);
    if (*(int *)(PTR_DAT_02322cac + 0x14) == *(int *)(PTR_DAT_02322ca8 + 4)) {
      *(undefined4 *)PTR_DAT_02322ca8 = 0xffffffff;
    }
  }
  return;
}

