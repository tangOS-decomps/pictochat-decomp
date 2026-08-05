// decomp: module=unk_autoload_0 addr=0x023276d8 name=FUN_023276d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x114 (Ghidra's cache says 0x104 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=41
// verify:  python tools/match.py --c <file> --func FUN_023276d8 --addr 0x023276d8 --size 0x114 --module unk_autoload_0 --version 2.0/sp1


void FUN_023276d8(void)

{
  ushort uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint local_24;
  
  for (iVar8 = 0; puVar2 = PTR_DAT_023277dc, iVar8 < *(int *)PTR_DAT_023277e8; iVar8 = iVar8 + 1) {
    iVar5 = iVar8 * 0x94;
    if (*(short *)(PTR_DAT_023277dc + iVar5 + 0x5c) != 0) {
      FUN_023210c8(PTR_DAT_023277dc + iVar5 + 0x50,*(ushort *)(PTR_DAT_023277dc + iVar5 + 0x90) - 1,
                   0,0,0);
    }
    uVar1 = *(ushort *)(puVar2 + iVar5 + 0x4c);
    if ((uVar1 & 1) == 0) {
      uVar6 = 0x18;
    }
    else {
      uVar6 = 0x19;
    }
    uVar3 = FUN_02320c7c();
    FUN_02320e60(uVar3,PTR_DAT_023277e4,PTR_DAT_023277e0,uVar6,
                 *(undefined2 *)(puVar2 + iVar5 + 0x90),0,(uVar1 >> 1) + 8);
    iVar4 = (int)(*(ushort *)(puVar2 + iVar5 + 0x5c) + 2) >> 3;
    local_24 = (uint)((int)((*(ushort *)(puVar2 + iVar5 + 0x5c) + 7 & 0xfffffff8) + iVar4 * -8) < 4)
    ;
    for (iVar7 = 0; iVar7 < iVar4 + 1; iVar7 = iVar7 + 1) {
      uVar6 = FUN_02320c7c();
      FUN_02320e60(uVar6,PTR_DAT_023277e4,PTR_DAT_023277e0,0x16,
                   (uint)*(ushort *)(puVar2 + iVar5 + 0x90) + iVar7 * 8,0,0);
    }
    uVar6 = FUN_02320c7c();
    FUN_02320e60(uVar6,PTR_DAT_023277e4,PTR_DAT_023277e0,0x17,
                 ((uint)*(ushort *)(puVar2 + iVar5 + 0x90) + iVar7 * 8) - (local_24 * 8) / 2,0,0);
  }
  return;
}

