// decomp: module=unk_autoload_0 addr=0x02332598 name=FUN_02332598
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xb4 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=48
// verify:  python tools/match.py --c <file> --func FUN_02332598 --addr 0x02332598 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


uint FUN_02332598(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_28;
  uint local_24;
  uint local_1c;
  
  local_1c = *(uint *)(DAT_0233264c + 8);
  local_28 = param_2;
  local_24 = param_3;
  for (uVar5 = param_4; uVar5 != 0; uVar5 = uVar5 - uVar7) {
    uVar1 = DAT_02332650 & local_24;
    uVar7 = 0x200;
    uVar4 = DAT_02332654;
    if (uVar1 != local_1c) {
      if (((uVar1 != local_24) || ((local_28 & 3) != 0)) || (uVar4 = local_28, uVar5 < 0x200)) {
        uVar4 = DAT_02332654;
        local_1c = uVar1;
      }
      FUN_0233256c(uVar1);
      uVar6 = 0;
      do {
        uVar3 = *DAT_02332658;
        if (((uVar3 & 0x800000) != 0) && (uVar6 < 0x80)) {
          iVar2 = uVar6 * 4;
          uVar6 = uVar6 + 1;
          *(undefined4 *)(uVar4 + iVar2) = *DAT_0233265c;
        }
      } while ((uVar3 & 0x80000000) != 0);
    }
    if (uVar4 == DAT_02332654) {
      uVar7 = 0x200 - (local_24 - uVar1);
      if (uVar5 <= uVar7) {
        uVar7 = uVar5;
      }
      FUN_02337584(DAT_02332654 + (local_24 - uVar1),local_28,uVar7);
    }
    local_28 = local_28 + uVar7;
    local_24 = local_24 + uVar7;
  }
  *(uint *)(DAT_0233264c + 8) = local_1c;
  return param_4;
}

