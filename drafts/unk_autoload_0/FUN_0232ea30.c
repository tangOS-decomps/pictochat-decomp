// decomp: module=unk_autoload_0 addr=0x0232ea30 name=FUN_0232ea30
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x66 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=30
// verify:  python tools/match.py --c <file> --func FUN_0232ea30 --addr 0x0232ea30 --size 0x78 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ea30(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_0232e084(DAT_0232ea98,0x14);
  FUN_0232e084(DAT_0232ea9c,0x14);
  puVar2 = DAT_0232ea9c;
  iVar1 = 0;
  iVar3 = DAT_0232eaa0;
  do {
    *(undefined1 *)(iVar3 + 0x2c) = 0;
    *(char *)(iVar3 + 0x3c) = (char)iVar1;
    FUN_0232e0ac(puVar2,iVar3);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x44;
  } while (iVar1 < 0x10);
  iVar3 = 0;
  puVar2 = DAT_0232eaa4;
  do {
    FUN_0232e084(puVar2,0xc);
    FUN_0232e084(puVar2 + 3,0);
    *(undefined1 *)(puVar2 + 8) = 0x7f;
    puVar2[6] = 1;
    puVar2[7] = 0;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 9;
  } while (iVar3 < 0x20);
  return;
}

