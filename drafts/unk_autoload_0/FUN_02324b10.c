// decomp: module=unk_autoload_0 addr=0x02324b10 name=FUN_02324b10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x474 (Ghidra's cache says 0x444 - it excludes this function's trailing literal pool), thumb
// triage: noise=44 statements=282
// verify:  python tools/match.py --c <file> --func FUN_02324b10 --addr 0x02324b10 --size 0x474 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02324b10(void)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int extraout_r1;
  int extraout_r1_00;
  undefined4 in_r3;
  int iVar10;
  undefined1 auStack_28 [16];
  undefined4 uStack_18;
  
  uStack_18 = in_r3;
  FUN_02324fb0();
  iVar5 = FUN_0232996c();
  puVar1 = PTR_DAT_02324df8;
  if (iVar5 == 1) {
    *(undefined4 *)(PTR_DAT_02324df8 + 0x24) = 0;
    FUN_02329db8(*(undefined4 *)(puVar1 + 0x28),0,0,1000);
    puVar1 = PTR_DAT_02324dfc;
    iVar10 = 0;
    iVar5 = *(int *)(PTR_DAT_02324df8 + 0x28) + 1 >> 0x1f;
    *(uint *)(PTR_DAT_02324df8 + 0x28) =
         ((uint)((*(int *)(PTR_DAT_02324df8 + 0x28) + 1) * 0x40000000 + iVar5) >> 0x1e | iVar5 << 2)
         - iVar5;
    do {
      iVar5 = FUN_0232a064(iVar10);
      if (iVar5 == 0) {
        *(undefined4 *)(puVar1 + iVar10 * 0x8c + 0x88) = 0;
        FUN_02334610(auStack_28,PTR_u_0_16_02324e04);
        FUN_023216e0(puVar1 + iVar10 * 0x8c + 0x40,auStack_28);
      }
      else {
        FUN_02329a08();
        iVar6 = FUN_02329270();
        *(int *)(puVar1 + iVar10 * 0x8c + 0x88) = iVar6 + 8;
        uVar7 = FUN_02329a3c(iVar5);
        FUN_023227e0(auStack_28,uVar7);
        FUN_0233465c(auStack_28,PTR_DAT_02324e00);
        FUN_023216e0(puVar1 + iVar10 * 0x8c + 0x40,auStack_28);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 4);
  }
  switch(*(undefined4 *)(PTR_DAT_02324df8 + 0x2c)) {
  case 0:
    uVar8 = FUN_02325278();
    uVar4 = FUN_023212c8(0x300);
    puVar1 = PTR_DAT_02324df8;
    if ((uVar8 & 0x40) == 0) {
      if ((uVar8 & 0x80) == 0) {
        if (uVar4 == 0) {
          *(undefined4 *)PTR_DAT_02324df8 = 0;
          *(undefined4 *)(puVar1 + 4) = 0;
        }
        else {
          iVar5 = *(int *)PTR_DAT_02324df8;
          if (iVar5 == 0) {
            if (((uVar4 & 0x200) == 0) || ((uVar4 & 0x100) != 0)) {
              if (((uVar4 & 0x100) != 0) && ((uVar4 & 0x200) == 0)) {
                *(undefined4 *)PTR_DAT_02324df8 = 2;
              }
            }
            else {
              *(undefined4 *)PTR_DAT_02324df8 = 1;
            }
          }
          else if ((iVar5 == 1) || (iVar5 == 3)) {
            if ((uVar4 & 0x100) != 0) {
              *(undefined4 *)PTR_DAT_02324df8 = 3;
              FUN_02335e0c(*(int *)(puVar1 + 4) + 1,10);
              *(int *)(PTR_DAT_02324df8 + 4) = extraout_r1;
              if (extraout_r1 == 0) {
                FUN_02327d68();
              }
            }
            if ((uVar4 & 0x200) == 0) {
              *(undefined4 *)PTR_DAT_02324df8 = 0;
            }
          }
          else if ((iVar5 == 2) || (iVar5 == 4)) {
            if ((uVar4 & 0x200) != 0) {
              *(undefined4 *)PTR_DAT_02324df8 = 4;
              FUN_02335e0c(*(int *)(puVar1 + 4) + 1,10);
              *(int *)(PTR_DAT_02324df8 + 4) = extraout_r1_00;
              if (extraout_r1_00 == 0) {
                FUN_02327ce0();
              }
            }
            if ((uVar4 & 0x100) == 0) {
              *(undefined4 *)PTR_DAT_02324df8 = 0;
            }
          }
          if (*(uint *)PTR_DAT_02324df8 < 3) {
            if ((uVar8 & 0x200) == 0) {
              if ((uVar8 & 0x100) != 0) {
                FUN_02327c9c();
              }
            }
            else {
              FUN_02327d24();
            }
          }
        }
      }
      else if (*(int *)(PTR_DAT_02324df8 + 0x20) < 3) {
        iVar5 = *(int *)(PTR_DAT_02324df8 + 0x20) + 1;
        *(int *)(PTR_DAT_02324df8 + 0x20) = iVar5;
        *(int *)(puVar1 + 0x30) = iVar5 * 0x20000;
        FUN_02320978(0x1d);
      }
    }
    else if (0 < *(int *)(PTR_DAT_02324df8 + 0x20)) {
      iVar5 = *(int *)(PTR_DAT_02324df8 + 0x20) + -1;
      *(int *)(PTR_DAT_02324df8 + 0x20) = iVar5;
      *(int *)(puVar1 + 0x30) = iVar5 * 0x20000;
      FUN_02320978(0x1d);
    }
    puVar2 = PTR_DAT_02324dfc;
    puVar1 = PTR_DAT_02324df8;
    iVar5 = 0;
    do {
      iVar10 = FUN_023213c4((undefined4 *)PTR_DAT_02324e08,*(int *)(puVar2 + iVar5 * 0x8c + 0x80));
      if (iVar10 != 0) {
        *(undefined4 *)(puVar1 + 0x1c) = 1;
        *(int *)(puVar1 + 0x20) = iVar5;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    iVar5 = FUN_02322438(0);
    if (iVar5 == 0) {
      iVar5 = FUN_02322438(1);
      if (iVar5 != 0) {
        FUN_02320978(0x1a);
        *(undefined4 *)(PTR_DAT_02324df8 + 0x2c) = 1;
        FUN_02321f9c();
        FUN_023223f0(0x1f,0);
        FUN_023223f0(0x20,1);
      }
    }
    else {
      *(undefined4 *)(PTR_DAT_02324df8 + 0x1c) = 1;
    }
    break;
  case 1:
    iVar5 = FUN_02322438(0);
    if (iVar5 != 0) {
      FUN_02320978(0x1c);
      bVar3 = true;
      goto LAB_02324eea;
    }
    iVar5 = FUN_02322438(1);
    if (iVar5 != 0) {
      FUN_02320978(0x20);
      *(undefined4 *)(PTR_DAT_02324df8 + 0x2c) = 0;
      FUN_02321fd4();
      FUN_023223f0(0x1a,0);
      FUN_023223f0(0x23,1);
      FUN_023224c4();
      FUN_023224e0();
    }
    break;
  case 2:
  case 4:
    iVar5 = FUN_02322438(0);
    if (iVar5 != 0) {
      FUN_02320978(0x1a);
      *(undefined4 *)(PTR_DAT_02324df8 + 0x2c) = 0;
      FUN_02321fd4();
      FUN_023223f0(0x1a,0);
      FUN_023223f0(0x23,1);
      FUN_023224c4();
      FUN_023224e0();
      FUN_0232a428();
    }
    break;
  case 3:
    iVar5 = FUN_02322438(0);
    if (iVar5 != 0) {
      FUN_023393e0();
    }
    break;
  case 5:
    iVar5 = FUN_02321fec();
    if (iVar5 == 0) {
      FUN_02321f9c();
      FUN_023223f0(0x1f,0);
      FUN_023223f0(0x22,1);
    }
    iVar5 = FUN_02322438(0);
    if (iVar5 == 0) {
      iVar5 = FUN_02322438(1);
      if (iVar5 != 0) {
        *(undefined4 *)(PTR_DAT_02324f78 + 0x2c) = 6;
        FUN_02321fd4();
        FUN_02320978(0x20);
      }
    }
    else {
      FUN_02329804();
      *(undefined4 *)(PTR_DAT_02324f78 + 0x2c) = 0;
      FUN_02321fd4();
      FUN_02320978(0x1a);
      FUN_023223f0(0x1a,0);
      FUN_023223f0(0x23,1);
      FUN_023224c4();
      FUN_023224e0();
    }
    break;
  case 6:
    iVar5 = FUN_02321fec();
    if (iVar5 == 0) {
      FUN_02321f9c();
      FUN_023223f0(0x1f,0);
      FUN_023223f0(0x20,1);
    }
    iVar5 = FUN_02322438(0);
    if (iVar5 == 0) {
      iVar5 = FUN_02322438(1);
      if (iVar5 != 0) {
        *(undefined4 *)(PTR_DAT_02324f78 + 0x2c) = 5;
        FUN_02321fd4();
        FUN_02320978(0x20);
      }
    }
    else {
      *(undefined4 *)(PTR_DAT_02324f78 + 0x2c) = 7;
      FUN_02321fd4();
      FUN_02320978(0x1c);
    }
    break;
  case 7:
    iVar5 = FUN_02321fec();
    if (iVar5 == 0) {
      FUN_02329804();
      bVar3 = true;
      goto LAB_02324eea;
    }
  }
  bVar3 = false;
LAB_02324eea:
  puVar1 = PTR_DAT_02324f78;
  if (bVar3) {
    *(undefined4 *)(PTR_DAT_02324f78 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    FUN_02321fd4();
    FUN_0232234c();
    FUN_02322004();
    FUN_02325040();
    uVar7 = 3;
  }
  else {
    FUN_0232234c();
    FUN_02322004();
    FUN_02325040();
    if (*(int *)(PTR_DAT_02324f78 + 0x2c) == 0) {
      FUN_02321328(PTR_DAT_02324f7c,PTR_DAT_02324f80);
    }
    uVar7 = FUN_02335e0c(*(int *)(PTR_DAT_02324f78 + 0x34) * 8 +
                         *(int *)(PTR_DAT_02324f78 + 0x30) * 2,10);
    puVar1 = PTR_DAT_02324f78;
    *(undefined4 *)(PTR_DAT_02324f78 + 0x34) = uVar7;
    if ((*(int *)(puVar1 + 0x1c) == 0) || (iVar5 = FUN_0232996c(), iVar5 < 1)) {
      uVar7 = 0;
    }
    else {
      FUN_02320978(0x1b);
      puVar9 = FUN_023260bc();
      *puVar9 = *(undefined4 *)(PTR_DAT_02324f78 + 0x20);
      FUN_02329e80();
      FUN_0232a368(*(undefined4 *)(PTR_DAT_02324f78 + 0x20),0);
      *(undefined4 *)(PTR_DAT_02324f78 + 0x14) = 0;
      uVar7 = 2;
    }
  }
  return uVar7;
}

