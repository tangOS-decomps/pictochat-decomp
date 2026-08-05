// decomp: module=unk_autoload_0 addr=0x0232a1e4 name=FUN_0232a1e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=18 statements=43
// verify:  python tools/match.py --c <file> --func FUN_0232a1e4 --addr 0x0232a1e4 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a1e4(void)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  
  puVar2 = DAT_0232a258;
  DAT_0232a258[6] = (short)DAT_0232a254;
  *(undefined4 *)(puVar2 + 0x1c) = 0;
  *(undefined4 *)(puVar2 + 0x18) = 0;
  *(undefined4 *)(puVar2 + 0x20) = 0;
  *(undefined4 *)(puVar2 + 0x16) = 0;
  *(undefined4 *)(puVar2 + 0x24) = 0;
  *(undefined4 *)(puVar2 + 10) = 0;
  *(undefined4 *)(puVar2 + 0xe) = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 0x10) = 0;
  *(undefined4 *)(puVar2 + 0x12) = 0;
  *puVar2 = 8;
  *(undefined4 *)(puVar2 + 0x2e) = 0;
  *(undefined4 *)(puVar2 + 0x30) = 0;
  *(undefined4 *)(puVar2 + 0x2c) = 0;
  FUN_023374f0(&local_12,0,6);
  iVar1 = 0;
  puVar2 = DAT_0232a25c;
  puVar3 = DAT_0232a260;
  do {
    *puVar2 = local_12;
    *puVar3 = local_12;
    puVar2[1] = local_10;
    puVar3[1] = local_10;
    puVar2[2] = local_e;
    puVar3[2] = local_e;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 3;
    puVar3 = puVar3 + 3;
  } while (iVar1 < 0x10);
  FUN_0232b9e4();
  FUN_0232c0c4();
  return;
}

