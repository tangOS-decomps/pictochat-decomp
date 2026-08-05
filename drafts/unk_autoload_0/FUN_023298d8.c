// decomp: module=unk_autoload_0 addr=0x023298d8 name=FUN_023298d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x94 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=30
// verify:  python tools/match.py --c <file> --func FUN_023298d8 --addr 0x023298d8 --size 0x94 --module unk_autoload_0 --version 2.0/sp1


void FUN_023298d8(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar3 = FUN_02331ca8();
  while ((iVar1 = FUN_0232996c(), iVar1 != 1 &&
         (((param_1 == 0 || (iVar1 = FUN_0232996c(), iVar1 != 0)) &&
          (iVar1 = FUN_0232996c(), iVar1 != 0xe))))) {
    if ((param_1 == 0) && (iVar1 = FUN_0232996c(), iVar1 == 0)) {
      FUN_02329bd8(0xe);
      return;
    }
    lVar4 = FUN_02331ca8();
    uVar2 = (uint)(lVar4 - lVar3);
    uVar5 = FUN_02335da4(uVar2 * 0x40,
                         (int)((ulonglong)(lVar4 - lVar3) >> 0x20) * 0x40 | uVar2 >> 0x1a,
                         DAT_02329964,0);
    if (((uint)((uint)uVar5 < 0x7d1) <= (uint)-(int)((ulonglong)uVar5 >> 0x20)) ||
       (iVar1 = FUN_0232996c(), 0xb < iVar1)) {
      *(undefined4 *)(DAT_02329968 + 0x10) = 0;
      FUN_023298c0();
      FUN_02329bd8(2);
      lVar3 = FUN_02331ca8();
    }
  }
  return;
}

