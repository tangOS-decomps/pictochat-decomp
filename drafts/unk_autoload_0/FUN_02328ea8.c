// decomp: module=unk_autoload_0 addr=0x02328ea8 name=FUN_02328ea8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x27c (Ghidra's cache says 0x26a - it excludes this function's trailing literal pool), thumb
// triage: noise=15 statements=134
// verify:  python tools/match.py --c <file> --func FUN_02328ea8 --addr 0x02328ea8 --size 0x27c --module unk_autoload_0 --version 2.0/sp1


void FUN_02328ea8(void)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  undefined4 in_r3;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  undefined1 auStack_158 [20];
  undefined2 local_144;
  undefined1 auStack_118 [256];
  undefined4 uStack_18;
  
  uStack_18 = in_r3;
  FUN_023295e4();
  iVar9 = 0;
  bVar1 = PTR_DAT_02329114[3];
  while ((iVar9 < (int)(uint)bVar1 && (pcVar4 = (char *)FUN_02329570(), pcVar4 != (char *)0x0))) {
    iVar10 = *(int *)(pcVar4 + 0x4000);
    if (iVar10 != 0) {
      if (*pcVar4 == '\x03') {
        cVar2 = pcVar4[1];
        if (cVar2 == '\0') {
          FUN_023293fc(pcVar4 + 2,pcVar4 + 8,1);
          FUN_0233746c(0,pcVar4,0x4000);
        }
        else if (cVar2 == '\x01') {
          FUN_023293fc(pcVar4 + 2,pcVar4 + 8,0);
          FUN_0233746c(0,pcVar4,0x4000);
        }
        else if (cVar2 == '\x02') {
          uVar5 = FUN_02329994();
          iVar6 = FUN_02332e38(pcVar4 + 2,uVar5,6);
          if (iVar6 != 0) {
            iVar6 = FUN_023294e4(pcVar4 + 2);
            if (iVar6 == 0) {
              uVar5 = FUN_02332080();
              pvVar7 = FUN_0232a4f4();
              FUN_02337584(pvVar7,PTR_DAT_02329118,0x60);
              FUN_02332094(uVar5);
              puVar11 = PTR_DAT_02329118;
              iVar10 = 0;
              do {
                iVar6 = FUN_02332e38(pcVar4 + 2,puVar11 + iVar10 * 6,6);
                if (iVar6 == 0) {
                  FUN_02328e74(0);
                }
                iVar10 = iVar10 + 1;
              } while (iVar10 < 0x10);
            }
            else {
              FUN_02327960((int)(pcVar4 + 8));
              FUN_0232679c(pcVar4 + 0x24,iVar10 + -0x24,*(undefined2 *)(iVar6 + 0x4e),iVar6 + 6);
            }
          }
          FUN_0233746c(0,pcVar4,0x4000);
        }
      }
      pcVar4[0x4000] = '\0';
      pcVar4[0x4001] = '\0';
      pcVar4[0x4002] = '\0';
      pcVar4[0x4003] = '\0';
    }
    iVar9 = iVar9 + 1;
  }
  FUN_02329600();
  iVar9 = *(int *)PTR_DAT_0232911c;
  if (iVar9 == 0) {
    iVar9 = FUN_0232996c();
    if ((iVar9 == 6) || (iVar9 = FUN_0232996c(), iVar9 == 7)) {
      *(undefined4 *)PTR_DAT_0232911c = 1;
    }
  }
  else if ((((iVar9 == 1) || (iVar9 == 2)) && (iVar9 = FUN_0232996c(), iVar9 != 6)) &&
          (iVar9 = FUN_0232996c(), iVar9 != 7)) {
    *(undefined4 *)PTR_DAT_0232911c = 0;
  }
  if ((*(int *)PTR_DAT_0232911c == 1) && (iVar9 = FUN_02329338(1), iVar9 != 0)) {
    *(undefined4 *)PTR_DAT_0232911c = 2;
  }
  iVar9 = FUN_0232996c();
  if (((iVar9 != 8) && (iVar9 != 9)) && (iVar9 != 10)) {
    uVar5 = FUN_02332080();
    pvVar7 = FUN_0232a4f4();
    FUN_02337584(pvVar7,PTR_DAT_02329118,0x60);
    FUN_02332094(uVar5);
    iVar9 = 0;
    do {
      puVar11 = PTR_DAT_02329120 + iVar9 * 0x58;
      if (*(int *)(puVar11 + 0x54) == 2) {
        bVar3 = false;
        iVar10 = 0;
        do {
          iVar6 = FUN_02332e38(puVar11,PTR_DAT_02329118 + iVar10 * 6,6);
          if (iVar6 == 0) {
            bVar3 = true;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x10);
        if (!bVar3) {
          puVar11 = PTR_DAT_02329120 + iVar9 * 0x58;
          FUN_02334628(auStack_158,puVar11 + 6,10);
          local_144 = 0;
          piVar8 = FUN_023260bc();
          FUN_02329634((int)auStack_118,*piVar8,(int)auStack_158);
          uVar5 = FUN_02329994();
          iVar10 = FUN_02332e38(uVar5,puVar11,6);
          if (iVar10 != 0) {
            FUN_02326488(auStack_118,0x11);
          }
          FUN_0233746c(0,puVar11,0x58);
          *(undefined4 *)(puVar11 + 0x54) = 0;
          FUN_023274f8();
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 0x10);
  }
  puVar11 = PTR_DAT_02329120;
  iVar9 = 0;
  do {
    if ((*(int *)(puVar11 + iVar9 * 0x58 + 0x54) == 1) && (iVar10 = FUN_02329338(0), iVar10 != 0)) {
      *(undefined4 *)(puVar11 + iVar9 * 0x58 + 0x54) = 2;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0x10);
  FUN_0232996c();
  return;
}

