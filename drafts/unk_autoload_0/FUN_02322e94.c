// decomp: module=unk_autoload_0 addr=0x02322e94 name=FUN_02322e94
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x7e - it excludes this function's trailing literal pool), thumb
// triage: noise=12 statements=48
// verify:  python tools/match.py --c <file> --func FUN_02322e94 --addr 0x02322e94 --size 0x88 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322e94(void)

{
  undefined1 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  
  puVar3 = PTR_DAT_02322f18;
  if (*(int *)PTR_DAT_02322f14 != 0) {
    uVar4 = 0;
    uVar6 = 0;
    uVar8 = 0xffffffff;
    while ((uVar4 < 4 && (*(int *)(PTR_DAT_02322f18 + uVar4 * 0x30 + 0x24) != 0))) {
      if (*(uint *)(PTR_DAT_02322f18 + uVar4 * 0x30 + 0x20) < uVar8) {
        uVar6 = uVar4;
        uVar8 = *(uint *)(PTR_DAT_02322f18 + uVar4 * 0x30 + 0x20);
      }
      uVar4 = uVar4 + 1 & 0xff;
    }
    if (uVar4 == 4) {
      uVar4 = uVar6;
    }
    *(undefined4 *)(PTR_DAT_02322f18 + uVar4 * 0x30 + 0x24) = 1;
    *(undefined2 *)(puVar3 + uVar4 * 0x30 + 0x28) = 0;
    puVar3[uVar4 * 0x30 + 0x2c] = 0;
    puVar2 = PTR_DAT_02322f14;
    uVar9 = *(undefined4 *)(PTR_DAT_02322f14 + 4);
    puVar3[uVar4 * 0x30 + 0x2d] = ((byte)uVar9 & 0xf) + 3;
    *(undefined4 *)(puVar3 + uVar4 * 0x30 + 0x20) = uVar9;
    puVar10 = *(undefined1 **)puVar2;
    puVar7 = puVar3 + uVar4 * 0x30 + 4;
    iVar5 = 0x1a;
    do {
      uVar1 = *puVar10;
      puVar10 = puVar10 + 1;
      *puVar7 = uVar1;
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined4 *)PTR_DAT_02322f14 = 0;
  }
  return;
}

