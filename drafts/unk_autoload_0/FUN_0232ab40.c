// decomp: module=unk_autoload_0 addr=0x0232ab40 name=FUN_0232ab40
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x6e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=36
// verify:  python tools/match.py --c <file> --func FUN_0232ab40 --addr 0x0232ab40 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ab40(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_r3;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  if (*(int *)(DAT_0232abb0 + 0x58) != 0) {
    FUN_0232aabc();
    iVar1 = FUN_0232996c();
    if (iVar1 == 4) {
      lVar6 = FUN_02331ca8();
      lVar6 = lVar6 - *(longlong *)(DAT_0232abb0 + 0x5c);
      uVar3 = (uint)lVar6;
      uVar7 = FUN_02335da4(uVar3 * 0x40,(int)((ulonglong)lVar6 >> 0x20) * 0x40 | uVar3 >> 0x1a,
                           DAT_0232abb4,0,in_r3);
      uVar3 = (uint)((ulonglong)uVar7 >> 0x20);
      uVar4 = *(uint *)(DAT_0232abb0 + 0x58);
      uVar2 = (int)uVar4 >> 0x1f;
      bVar5 = (uint)uVar7 <= uVar4;
      if (uVar2 <= uVar3 && (uint)bVar5 <= uVar2 - uVar3) {
        FUN_02329bd8(2,uVar3,(uVar2 - uVar3) - (uint)!bVar5);
        FUN_02329b2c(DAT_0232abb8,0);
      }
    }
    if (*(int *)(DAT_0232abb0 + 0x38) != 0) {
      FUN_0232a51c(DAT_0232abbc,*(ushort *)(DAT_0232abb0 + 6) & 0xff);
      FUN_0232b064();
      *(undefined4 *)(DAT_0232abb0 + 0x38) = 0;
    }
  }
  return;
}

