// decomp: module=unk_autoload_0 addr=0x02332a44 name=FUN_02332a44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x150 (Ghidra's cache says 0x120 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=54
// verify:  python tools/match.py --c <file> --func FUN_02332a44 --addr 0x02332a44 --size 0x150 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332a44(void)

{
  undefined2 uVar1;
  ushort uVar2;
  short *psVar3;
  char *pcVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int aiStack_24 [2];
  undefined1 auStack_1c [8];
  
  if ((*DAT_02332b64 == 0) && (*DAT_02332b64 = 1, (*DAT_02332b68 & 1) != 0)) {
    uVar6 = FUN_023307b4(0x40000);
    uVar1 = *DAT_02332b6c;
    *DAT_02332b6c = 1;
    FUN_023328e0(DAT_02332b70[1],auStack_1c);
    uVar2 = *DAT_02332b74;
    uVar7 = (uint)DAT_02332b74 >> 0xb;
    FUN_02332884(aiStack_24);
    *DAT_02332b74 = (ushort)DAT_02332b78 & *DAT_02332b74;
    FUN_023314cc(DAT_02332b7c + 0x80,0x40);
    FUN_023372b0(1,DAT_02332b80,DAT_02332b7c + 0x80,0x40,1);
    *DAT_02332b74 =
         (ushort)(((int)(uVar7 & uVar2) >> 0xf) << 0xf) | *DAT_02332b74 & (ushort)DAT_02332b78;
    FUN_023328b8(aiStack_24);
    FUN_0233291c(DAT_02332b70[1],auStack_1c);
    puVar5 = DAT_02332b88;
    iVar9 = DAT_02332b7c;
    if ((*DAT_02332b84 != '\0') || (DAT_02332b84[-1] == '\0')) {
      *DAT_02332b88 = *(undefined2 *)(DAT_02332b7c + 0xbe);
      for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {
        *(undefined1 *)((int)puVar5 + iVar8 + 2) = *(undefined1 *)(iVar9 + iVar8 + 0xb5);
      }
      puVar5[3] = *(undefined2 *)(iVar9 + 0xb0);
      *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(iVar9 + 0xac);
      iVar9 = FUN_023327dc();
      pcVar4 = DAT_02332b84;
      *DAT_02332b84 = iVar9 != 0;
      pcVar4[-1] = '\x01';
    }
    FUN_02337454(DAT_02332b8c,DAT_02332b90,0x9c);
    FUN_02331498();
    FUN_02332934((DAT_02332b7c + 0xfe000000U >> 5) << 6 | 1);
    psVar3 = DAT_02332b70;
    while (*psVar3 != 1) {
      FUN_02332d10(1);
    }
    *DAT_02332b6c = uVar1;
    FUN_023307b4(uVar6);
  }
  return;
}

