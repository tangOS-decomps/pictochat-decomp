// decomp: module=unk_autoload_0 addr=0x02322004 name=FUN_02322004
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x100 (Ghidra's cache says 0xf8 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=89
// verify:  python tools/match.py --c <file> --func FUN_02322004 --addr 0x02322004 --size 0x100 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322004(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(PTR_DAT_023220fc + 0xc);
  if (iVar3 < (int)(uint)*(ushort *)(PTR_DAT_02322100 + *(int *)(PTR_DAT_023220fc + 0x20) * 2)) {
    *(int *)(PTR_DAT_023220fc + 0xc) = iVar3 + 0x10;
  }
  else if ((int)(uint)*(ushort *)(PTR_DAT_02322100 + *(int *)(PTR_DAT_023220fc + 0x20) * 2) < iVar3)
  {
    *(int *)(PTR_DAT_023220fc + 0xc) = iVar3 + -0x10;
  }
  puVar1 = PTR_DAT_023220fc;
  if (-1 < *(int *)(PTR_DAT_023220fc + 0x14)) {
    iVar3 = *(int *)(PTR_DAT_023220fc + 0x18);
    if (iVar3 == 2) {
      iVar5 = 0x90;
    }
    else {
      iVar5 = 0x78;
    }
    iVar4 = *(int *)(PTR_DAT_023220fc + 0x1c);
    if (iVar4 == 0) {
      iVar3 = *(int *)(PTR_DAT_023220fc + 0x10) + 1;
      *(int *)(PTR_DAT_023220fc + 0x10) = iVar3;
      if (iVar3 < 0x10) {
        uVar2 = FUN_02335e0c(iVar5 * (0xf - iVar3));
        *(undefined4 *)PTR_DAT_023220fc = uVar2;
        return;
      }
      if (*(int *)(puVar1 + 0x18) == 1) {
        FUN_02322518();
      }
      puVar1 = PTR_DAT_023220fc;
      *(undefined4 *)(PTR_DAT_023220fc + 0x10) = 0;
      *(undefined4 *)(puVar1 + 0x1c) = 1;
      return;
    }
    if (iVar4 == 1) {
      if (iVar3 == 0) {
        iVar3 = *(int *)(PTR_DAT_023220fc + 0x10);
        *(int *)(PTR_DAT_023220fc + 0x10) = iVar3 + 1;
        if (0xb4 < iVar3 + 1) {
          *(undefined4 *)(puVar1 + 0x10) = 0;
          *(undefined4 *)(puVar1 + 0x1c) = 2;
          return;
        }
      }
      else if (iVar3 == 1) {
        *(int *)(PTR_DAT_023220fc + 0x10) = *(int *)(PTR_DAT_023220fc + 0x10) + 1;
        if (*(int *)(puVar1 + 0x24) != 0) {
          FUN_02322524();
          puVar1 = PTR_DAT_023220fc;
          if (0x1e < *(int *)(PTR_DAT_023220fc + 0x10)) {
            *(undefined4 *)(PTR_DAT_023220fc + 0x10) = 0;
            *(undefined4 *)(puVar1 + 0x1c) = 2;
            return;
          }
        }
      }
      else if (((iVar3 == 2) &&
               (iVar3 = *(int *)(PTR_DAT_023220fc + 0x10),
               *(int *)(PTR_DAT_023220fc + 0x10) = iVar3 + 1, 0x1e < iVar3 + 1)) &&
              (*(int *)(puVar1 + 0x24) != 0)) {
        *(undefined4 *)(puVar1 + 0x10) = 0;
        *(undefined4 *)(puVar1 + 0x1c) = 2;
        return;
      }
    }
    else {
      if (iVar4 != 2) {
        return;
      }
      iVar3 = *(int *)(PTR_DAT_023220fc + 0x10) + 1;
      *(int *)(PTR_DAT_023220fc + 0x10) = iVar3;
      if (iVar3 < 0x10) {
        iVar3 = FUN_02335e0c(iVar5 * (0xf - iVar3));
        *(int *)PTR_DAT_023220fc = iVar5 - iVar3;
        return;
      }
      FUN_02322518();
      FUN_02321df4();
    }
  }
  return;
}

