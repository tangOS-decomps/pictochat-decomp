// decomp: module=unk_autoload_0 addr=0x0232b85c name=FUN_0232b85c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x82 - it excludes this function's trailing literal pool), thumb
// triage: noise=23 statements=34
// verify:  python tools/match.py --c <file> --func FUN_0232b85c --addr 0x0232b85c --size 0xa0 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b85c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  puVar1 = DAT_0232b8e0;
  *(undefined4 *)(DAT_0232b8e0 + 10) = 0;
  uVar2 = DAT_0232b8e4;
  *(undefined4 *)(puVar1 + 0x1c) = 0;
  *puVar1 = (short)uVar2;
  *(undefined4 *)(puVar1 + 2) = 0;
  *(undefined4 *)(puVar1 + 0x1e) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0xffffffff;
  pcVar3 = (code *)*DAT_0232b8e8;
  if (pcVar3 != (code *)0x0) {
    uVar2 = (*pcVar3)(param_1,0x20,pcVar3,0,param_4);
    pcVar3 = (code *)*DAT_0232b8e8;
    *(undefined4 *)(DAT_0232b8e0 + 0x18) = uVar2;
    uVar2 = (*pcVar3)(0xc0,0x20);
    pcVar3 = (code *)*DAT_0232b8e8;
    *(undefined4 *)(DAT_0232b8e0 + 0x1a) = uVar2;
    uVar2 = (*pcVar3)(0xc0,0x20);
    pcVar3 = (code *)*DAT_0232b8e8;
    *(undefined4 *)(DAT_0232b8e0 + 6) = uVar2;
    uVar2 = (*pcVar3)(0xc0,0x20);
    *(undefined4 *)(DAT_0232b8e0 + 8) = uVar2;
  }
  *(undefined4 *)(DAT_0232b8e0 + 4) = 0xc0;
  FUN_0232b74c(DAT_0232b8ec,0x14,0x40);
  FUN_0232b74c(DAT_0232b8f0,*(undefined4 *)(DAT_0232b8e0 + 4),0x40);
  FUN_0232c8c0(0xd,DAT_0232b8f4,0);
  FUN_0232c8c0(0xe,DAT_0232b8f8,0);
  return;
}

