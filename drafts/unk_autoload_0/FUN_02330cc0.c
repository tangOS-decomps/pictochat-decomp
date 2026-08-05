// decomp: module=unk_autoload_0 addr=0x02330cc0 name=FUN_02330cc0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe0 (Ghidra's cache says 0x9c - it excludes this function's trailing literal pool), thumb
// triage: noise=16 statements=51
// verify:  python tools/match.py --c <file> --func FUN_02330cc0 --addr 0x02330cc0 --size 0xe0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330cc0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = DAT_02330d60;
  iVar1 = DAT_02330d5c;
  if (*(int *)(DAT_02330d5c + 0xc) == 0) {
    *(undefined4 *)(DAT_02330d5c + 0xc) = 1;
    *(undefined4 *)(iVar1 + 8) = uVar2;
    iVar3 = DAT_02330d64;
    *(undefined4 *)(DAT_02330d64 + 0x5c) = 0x10;
    *(undefined4 *)(iVar3 + 0x58) = 0;
    *(undefined4 *)(iVar3 + 0x50) = 1;
    *(undefined4 *)(iVar3 + 0x54) = 0;
    *(undefined4 *)(iVar3 + 0x60) = 0;
    iVar3 = DAT_02330d6c;
    uVar2 = DAT_02330d68;
    *(undefined4 *)(iVar1 + 0x24) = DAT_02330d68;
    *(undefined4 *)(iVar1 + 0x20) = uVar2;
    piVar4 = DAT_02330d80;
    uVar2 = DAT_02330d7c;
    iVar1 = DAT_02330d64;
    iVar5 = DAT_02330d70;
    if (0 < iVar3) {
      iVar5 = (DAT_02330d74 + 0x3f80) - DAT_02330d78;
    }
    iVar6 = (DAT_02330d74 + 0x3f80) - DAT_02330d78;
    *DAT_02330d80 = iVar6;
    *(int *)(iVar1 + 0x7c) = iVar5 - iVar3;
    piVar4[1] = 0;
    *(undefined4 *)(iVar6 + -8) = uVar2;
    **(undefined4 **)(iVar1 + 0x7c) = DAT_02330d84;
    piVar4[3] = 0;
    piVar4[2] = 0;
    uVar2 = DAT_02330d88;
    iVar1 = DAT_02330d5c;
    *(undefined2 *)(DAT_02330d5c + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x1e) = 0;
    *DAT_02330d8c = uVar2;
    FUN_02331064();
    FUN_02330da0(DAT_02330d90,DAT_02330d94,0,DAT_02330d98,200,0x1f);
    iVar1 = DAT_02330d9c;
    *(undefined4 *)(DAT_02330d9c + 0x1c) = 0x20;
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  return;
}

