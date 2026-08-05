// decomp: module=unk_autoload_0 addr=0x0232bd8c name=FUN_0232bd8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xf4 (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=67
// verify:  python tools/match.py --c <file> --func FUN_0232bd8c --addr 0x0232bd8c --size 0xf4 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bd8c(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = FUN_02332080();
  iVar3 = FUN_0232b834(DAT_0232be70);
  puVar1 = DAT_0232be74;
  if ((iVar3 != 0) || (*(int *)(DAT_0232be74 + 0x1c) != 0)) {
    FUN_02332094(uVar2);
    return;
  }
  puVar1[0x1c] = 2;
  puVar1[0x1d] = 0;
  puVar1[0x10] = 0xffff;
  puVar1[0x11] = 0xffff;
  if (*(int *)(puVar1 + 0x16) != 0) {
    FUN_02332274();
  }
  puVar1 = DAT_0232be74;
  puVar1[0x16] = 1;
  puVar1[0x17] = 0;
  FUN_0232b7ec(DAT_0232be70,*(undefined4 *)(puVar1 + 6),0x14);
  FUN_02332094(uVar2);
  puVar1 = DAT_0232be74;
  **(undefined2 **)(DAT_0232be74 + 6) = 1;
  uVar4 = (uint)*(byte *)(*(int *)(puVar1 + 6) + 4);
  if (uVar4 == 0) {
    FUN_0232c100(0xd,*(int *)(puVar1 + 6),0x14,DAT_0232be78,DAT_0232be7c);
    puVar1 = DAT_0232be74;
    if (*(int *)(DAT_0232be74 + 10) != 1) {
      return;
    }
    puVar1[10] = 2;
    puVar1[0xb] = 0;
    *puVar1 = 0;
    FUN_0232becc();
    return;
  }
  uVar4 = 1 << uVar4 & 0xffff;
  iVar3 = FUN_02329978();
  uVar2 = DAT_0232be78;
  puVar1 = DAT_0232be74;
  if (uVar4 == (*(ushort *)(iVar3 + 0x86) & uVar4)) {
    iVar3 = *(int *)(DAT_0232be74 + 6);
    *DAT_0232be74 = (ushort)*(byte *)(iVar3 + 4);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(iVar3 + 8);
    FUN_0232c100(0xd,iVar3,0x14,uVar2,DAT_0232be7c);
    return;
  }
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  iVar3 = FUN_0232b834(DAT_0232be70);
  puVar1 = DAT_0232be74;
  if (iVar3 != 0) {
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x10] = 0xffff;
    puVar1[0x11] = 0xffff;
    return;
  }
  puVar1[0x1c] = 0;
  puVar1[0x1d] = 0;
  FUN_0232bd8c();
  return;
}

