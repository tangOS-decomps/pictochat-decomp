// decomp: module=unk_autoload_0 addr=0x023232e8 name=FUN_023232e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x170 (Ghidra's cache says 0x166 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=57
// verify:  python tools/match.py --c <file> --func FUN_023232e8 --addr 0x023232e8 --size 0x170 --module unk_autoload_0 --version 2.0/sp1


void FUN_023232e8(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  int *piVar7;
  ushort *puVar8;
  
  piVar7 = (int *)param_1[2];
  FUN_023374b8(PTR_DAT_02323450,PTR_DAT_02323454,0x2280);
  if (*(ushort *)((int)param_1 + 0x26) != 0) {
    iVar2 = (*(ushort *)((int)param_1 + 0x26) - 1) * 8;
    iVar4 = *piVar7 + iVar2;
    uVar5 = *(ushort *)(*piVar7 + iVar2);
    uVar6 = uVar5 >> 8;
    uVar5 = uVar5 & 0xff;
    FUN_02323f80(PTR_DAT_02323454,200,8,uVar5,uVar6,uVar5 + (*(ushort *)(iVar4 + 2) & 0xff),
                 uVar6 + (*(ushort *)(iVar4 + 2) >> 8));
  }
  puVar1 = PTR_DAT_02323454;
  puVar8 = (ushort *)*param_1;
  if ((puVar8 != (ushort *)0x0) && (param_1[1] != 0)) {
    uVar5 = *(ushort *)(param_1[1] + 6);
    if ((uVar5 != *(ushort *)((int)param_1 + 0x26)) &&
       ((uVar6 = puVar8[3], uVar6 != *(ushort *)((int)param_1 + 0x26) && (uVar6 != 0)))) {
      if (uVar6 == uVar5) {
        do {
          uVar5 = *puVar8 >> 8;
          uVar6 = *puVar8 & 0xff;
          FUN_02323f80(puVar1,200,8,uVar6,uVar5,uVar6 + (puVar8[1] & 0xff),uVar5 + (puVar8[1] >> 8))
          ;
          puVar8 = puVar8 + (short)puVar8[2] * 4;
        } while (puVar8 != (ushort *)*param_1);
      }
      else {
        do {
          uVar5 = *puVar8 >> 8;
          uVar6 = *puVar8 & 0xff;
          FUN_02323f80(puVar1,200,8,uVar6,uVar5,uVar6 + (puVar8[1] & 0xff),uVar5 + 1);
          iVar2 = (uint)(*puVar8 >> 8) + (uint)(puVar8[1] >> 8);
          uVar5 = *puVar8 & 0xff;
          FUN_02323f80(puVar1,200,8,uVar5,iVar2 + -1,uVar5 + (puVar8[1] & 0xff),iVar2);
          uVar3 = (uint)(*puVar8 >> 8);
          uVar5 = *puVar8 & 0xff;
          FUN_02323f80(puVar1,200,8,uVar5,uVar3 + 1,uVar5 + 1,uVar3 + (puVar8[1] >> 8) + -1);
          uVar3 = (uint)(*puVar8 >> 8);
          iVar2 = (*puVar8 & 0xff) + (puVar8[1] & 0xff);
          FUN_02323f80(puVar1,200,8,iVar2 + -1,uVar3 + 1,iVar2,uVar3 + (puVar8[1] >> 8) + -1);
          puVar8 = puVar8 + (short)puVar8[2] * 4;
        } while (puVar8 != (ushort *)*param_1);
      }
    }
  }
  return;
}

