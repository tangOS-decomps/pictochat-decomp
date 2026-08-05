// decomp: module=unk_autoload_0 addr=0x02323f00 name=FUN_02323f00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=29
// verify:  python tools/match.py --c <file> --func FUN_02323f00 --addr 0x02323f00 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02323f00(uint param_1)

{
  int iVar1;
  int iVar2;
  int unaff_r7;
  int iVar3;
  
  if (param_1 != 0x3000) {
    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
      iVar1 = FUN_023346a8(*(undefined4 *)(DAT_02323f70 + iVar2 * 4),param_1);
      if (iVar1 != 0) {
        unaff_r7 = (iVar1 - *(int *)(DAT_02323f70 + iVar2 * 4)) / 2;
        break;
      }
    }
    if (3 < iVar2) {
      return param_1;
    }
    for (iVar1 = 1; iVar1 < 4; iVar1 = iVar1 + 1) {
      iVar3 = iVar2 + iVar1 >> 0x1f;
      iVar3 = *(int *)(DAT_02323f70 +
                      (((uint)((iVar2 + iVar1) * 0x40000000 + iVar3) >> 0x1e | iVar3 << 2) - iVar3)
                      * 4);
      if (*(short *)(unaff_r7 * 2 + iVar3) != 0x3000) {
        return (uint)*(ushort *)(iVar3 + unaff_r7 * 2);
      }
    }
  }
  return param_1;
}

