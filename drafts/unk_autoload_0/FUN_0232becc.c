// decomp: module=unk_autoload_0 addr=0x0232becc name=FUN_0232becc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xb0 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=43
// verify:  python tools/match.py --c <file> --func FUN_0232becc --addr 0x0232becc --size 0xc0 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232becc(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined4 local_14;
  
  iVar4 = *(int *)(DAT_0232bf7c + 0x28) - *(int *)(DAT_0232bf7c + 0x1c);
  iVar2 = iVar4;
  if (0xa0 < iVar4) {
    iVar2 = 0xa0;
  }
  if (0 < iVar2) {
    local_1c = 2;
    uVar3 = iVar2 + 0xc;
    local_1a = (undefined2)uVar3;
    uVar1 = FUN_0232a4e8();
    local_18 = (undefined1)uVar1;
    local_16 = (undefined1)iVar2;
    local_15 = iVar4 - iVar2 < 1;
    local_14 = *(undefined4 *)(DAT_0232bf7c + 0x1c);
    FUN_02337584(&local_1c,*(undefined4 *)(DAT_0232bf7c + 0x10),0xc);
    FUN_02337584(*DAT_0232bf80 + *(int *)(DAT_0232bf7c + 0x1c),*(int *)(DAT_0232bf7c + 0x10) + 0xc,
                 iVar2);
    uVar1 = FUN_0232a4e8();
    if (uVar1 == 0) {
      FUN_0232c100(0xe,*(undefined4 *)(DAT_0232bf7c + 0x10),uVar3 & 0xffff,DAT_0232bf88,DAT_0232bf84
                  );
    }
    else {
      FUN_0232c100(0xe,*(undefined4 *)(DAT_0232bf7c + 0x10),uVar3 & 0xffff,1,DAT_0232bf84);
    }
    if (*(int *)(DAT_0232bf7c + 0x1c) < *(int *)(DAT_0232bf7c + 0x20) + 0x640) {
      *(int *)(DAT_0232bf7c + 0x1c) = *(int *)(DAT_0232bf7c + 0x1c) + iVar2;
    }
  }
  return;
}

