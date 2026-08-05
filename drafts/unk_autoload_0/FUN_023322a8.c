// decomp: module=unk_autoload_0 addr=0x023322a8 name=FUN_023322a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xaa - it excludes this function's trailing literal pool), thumb
// triage: noise=16 statements=43
// verify:  python tools/match.py --c <file> --func FUN_023322a8 --addr 0x023322a8 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


void FUN_023322a8(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort uVar4;
  
  iVar1 = DAT_02332354;
  if (*(int *)(DAT_02332354 + 4) == 0) {
    *(undefined4 *)(DAT_02332354 + 4) = 1;
    uVar4 = FUN_02332120();
    if (uVar4 == 1) {
      FUN_02337584(DAT_02332358,DAT_0233235c,0x160);
    }
    iVar2 = DAT_02332360;
    *(undefined4 *)(iVar1 + DAT_02332360) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 4) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 8) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 0xc) = 0xffffffff;
    *(undefined4 *)(iVar1 + iVar2 + 0x10) = 0;
    puVar3 = DAT_02332364;
    *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
    *puVar3 = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
    *(undefined4 *)(iVar1 + 8) = 4;
    FUN_0233237c();
    iVar2 = DAT_02332368;
    *(undefined4 *)(iVar1 + DAT_02332368) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 4) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar1 + iVar2 + 8) = *(undefined4 *)(iVar1 + iVar2 + 0xc);
    FUN_02330da0(iVar1 + 0x28,DAT_0233236c,0,iVar1 + iVar2 + -4,iVar2 + -0xec,
                 *(undefined4 *)(iVar1 + 8));
    FUN_02330fb4((int *)(iVar1 + 0x28));
    FUN_02332394();
    FUN_02332660();
    uVar4 = FUN_02332120();
    if (uVar4 == 1) {
      FUN_02332370((void *)0x1);
    }
    FUN_02332670();
  }
  return;
}

