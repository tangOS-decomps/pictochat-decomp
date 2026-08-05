// decomp: module=unk_autoload_0 addr=0x02323510 name=FUN_02323510
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1bc (Ghidra's cache says 0x16e - it excludes this function's trailing literal pool), thumb
// triage: noise=20 statements=70
// verify:  python tools/match.py --c <file> --func FUN_02323510 --addr 0x02323510 --size 0x1bc --module unk_autoload_0 --version 2.0/sp1


void FUN_02323510(uint param_1,uint param_2,undefined4 param_3)

{
  short sVar1;
  ushort uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  int iVar7;
  ushort uVar8;
  
  puVar3 = PTR_DAT_02323680;
  *(uint *)(PTR_DAT_02323680 + 4) = param_1 & 0xffff;
  *(uint *)(puVar3 + 8) = param_2 & 0xffff;
  *(undefined4 *)(puVar3 + 0x3c) = 0;
  *(undefined4 *)(puVar3 + 0x40) = param_3;
  puVar5 = PTR_DAT_02323688;
  puVar4 = PTR_DAT_02323684;
  if (*(int *)puVar3 == 0) {
    uVar6 = *(undefined4 *)(PTR_DAT_02323684 + 0x18);
    *(undefined4 *)(PTR_DAT_02323684 + 8) = uVar6;
    *(undefined4 *)puVar4 = uVar6;
    *(undefined4 *)(puVar4 + 0x10) = uVar6;
    *(undefined4 *)(puVar4 + 0x14) = *(undefined4 *)(puVar4 + 0x1c);
    *(undefined4 *)(puVar4 + 4) = *(undefined4 *)(puVar4 + 0x20);
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(puVar4 + 0x24);
    puVar3 = PTR_PTR_02323694;
    *(short *)(PTR_PTR_02323694 + 0xe) =
         (short)((uint)((int)PTR_DAT_0232368c - (int)PTR_DAT_02323690) >> 3);
    *(short *)(puVar3 + 0x1e) = (short)((uint)((int)puVar5 - (int)PTR_DAT_02323698) >> 3);
    sVar1 = (short)((uint)((int)PTR_DAT_0232369c - (int)PTR_DAT_023236a0) >> 3);
    *(short *)(puVar3 + 0x2e) = sVar1 + -3;
    *(short *)(puVar3 + 0x3e) = sVar1;
    puVar3 = PTR_DAT_023236a8;
    *(short *)(PTR_PTR_023236a4 + 0xe) = sVar1;
    FUN_023234d0(PTR_DAT_023236ac,puVar3,PTR_PTR_023236b0);
    FUN_023234d0(PTR_DAT_023236b4,PTR_DAT_023236a8,PTR_PTR_023236b8);
    FUN_023234d0(PTR_DAT_023236bc,PTR_DAT_023236a8,PTR_PTR_023236c0);
    FUN_02337454(PTR_DAT_023236bc,PTR_DAT_023236c4,0x2280);
    iVar7 = *(int *)(PTR_PTR_02323694 + 0x30);
    uVar2 = *(ushort *)(iVar7 + 0x1b8) >> 8;
    uVar8 = *(ushort *)(iVar7 + 0x1b8) & 0xff;
    FUN_02323f80(PTR_DAT_023236c4,200,2,uVar8,uVar2,uVar8 + (*(ushort *)(iVar7 + 0x1ba) & 0xff),
                 uVar2 + (*(ushort *)(iVar7 + 0x1ba) >> 8) + 1);
    uVar2 = *(ushort *)(iVar7 + 0x1c0) >> 8;
    uVar8 = *(ushort *)(iVar7 + 0x1c0) & 0xff;
    FUN_02323f80(PTR_DAT_023236c4,200,2,uVar8,uVar2,uVar8 + (*(ushort *)(iVar7 + 0x1c2) & 0xff),
                 uVar2 + (*(ushort *)(iVar7 + 0x1c2) >> 8) + 1);
    uVar2 = *(ushort *)(iVar7 + 0x1c8) >> 8;
    uVar8 = *(ushort *)(iVar7 + 0x1c8) & 0xff;
    FUN_02323f80(PTR_DAT_023236c4,200,2,uVar8,uVar2,uVar8 + (*(ushort *)(iVar7 + 0x1ca) & 0xff),
                 uVar2 + (*(ushort *)(iVar7 + 0x1ca) >> 8) + 1);
    puVar3 = PTR_DAT_02323680;
    *(undefined4 *)(PTR_DAT_02323680 + 0x18) = 0;
    *(undefined4 *)(puVar3 + 0x1c) = 0;
  }
  if ((*(int *)(PTR_DAT_02323680 + 0x40) != 0) || (*(int *)PTR_DAT_02323680 == 0)) {
    if ((*DAT_023236c8 & 7) == 0) {
      *(uint *)(PTR_DAT_02323680 + 0x38) =
           *(int *)(PTR_PTR_02323694 + 0x10) + (uint)*(ushort *)(PTR_PTR_02323694 + 0x1c) * 8;
      FUN_023236cc(1);
    }
    else {
      *(uint *)(PTR_DAT_02323680 + 0x38) =
           *(int *)PTR_PTR_02323694 + (uint)*(ushort *)(PTR_PTR_02323694 + 0xc) * 8;
      FUN_023236cc(0);
    }
    *(undefined4 *)PTR_DAT_02323680 = 1;
  }
  return;
}

