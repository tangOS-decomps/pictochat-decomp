// decomp: module=unk_autoload_0 addr=0x023327dc name=FUN_023327dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0x9a - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=28
// verify:  python tools/match.py --c <file> --func FUN_023327dc --addr 0x023327dc --size 0xa8 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_023327dc(void)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_18 [2];
  undefined1 auStack_10 [8];
  
  uVar2 = 1;
  iVar1 = FUN_0233276c();
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)((int)DAT_02332878 + 5) & 3) >> 1 == 1) {
    return 0;
  }
  FUN_023328e0(*(undefined2 *)(DAT_0233287c + 6),auStack_10);
  FUN_02332884(aiStack_18);
  if ((((DAT_080000b2 == -0x6a) && (*DAT_02332878 != _DAT_080000be)) ||
      ((DAT_080000b2 != -0x6a && (*DAT_02332878 != *DAT_02332880)))) ||
     ((*(int *)(DAT_02332878 + 4) != _DAT_080000ac &&
      ((int)((uint)*(byte *)((int)DAT_02332878 + 5) << 0x1f) < 0)))) {
    uVar2 = 0;
    *(byte *)((int)DAT_02332878 + 5) = *(byte *)((int)DAT_02332878 + 5) | 2;
  }
  FUN_023328b8(aiStack_18);
  FUN_0233291c(*(undefined2 *)(DAT_0233287c + 6),auStack_10);
  return uVar2;
}

