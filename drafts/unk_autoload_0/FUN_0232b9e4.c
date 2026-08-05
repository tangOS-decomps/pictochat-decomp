// decomp: module=unk_autoload_0 addr=0x0232b9e4 name=FUN_0232b9e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232b9e4 --addr 0x0232b9e4 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b9e4(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_02332080();
  puVar1 = DAT_0232ba2c;
  *DAT_0232ba2c = (short)DAT_0232ba28;
  *(undefined4 *)(puVar1 + 10) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined4 *)(puVar1 + 0x12) = 0;
  *(undefined4 *)(puVar1 + 0x16) = 0;
  FUN_0232b854(DAT_0232ba30);
  FUN_0232b854(DAT_0232ba34);
  FUN_02332094(uVar2);
  FUN_0232c8c0(0xd,DAT_0232ba38,0);
  FUN_0232c8c0(0xe,DAT_0232ba3c,0);
  return;
}

