// decomp: module=unk_autoload_0 addr=0x023236cc name=FUN_023236cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), thumb
// triage: noise=20 statements=40
// verify:  python tools/match.py --c <file> --func FUN_023236cc --addr 0x023236cc --size 0xcc --module unk_autoload_0 --version 2.0/sp1


void FUN_023236cc(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_02323764;
  *(undefined4 *)(PTR_DAT_02323764 + 0x34) = param_1;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  *(undefined2 *)(puVar1 + 0x2c) = 0;
  *(undefined2 *)(puVar1 + 0x2e) = 0;
  *(undefined2 *)(puVar1 + 0x32) = 0;
  *(undefined2 *)(puVar1 + 0x30) = 0;
  FUN_0232518c((ushort *)PTR_DAT_02323768,0x28,5);
  puVar1 = PTR_DAT_02323764;
  switch(param_1) {
  case 0:
    *(undefined **)(PTR_DAT_02323764 + 0x14) = PTR_PTR_0232376c;
    *(undefined **)(puVar1 + 0x20) = PTR_DAT_02323770 + 2;
    break;
  case 1:
    *(undefined **)(PTR_DAT_02323764 + 0x14) = PTR_PTR_02323774;
    *(undefined **)(puVar1 + 0x20) = PTR_DAT_02323778 + 2;
    *(undefined2 *)(puVar1 + 0x32) = 4;
    break;
  case 2:
    *(undefined **)(PTR_DAT_02323764 + 0x14) = PTR_PTR_0232377c;
    *(undefined **)(puVar1 + 0x20) = PTR_DAT_02323780 + 2;
    break;
  case 3:
    *(undefined **)(PTR_DAT_02323764 + 0x14) = PTR_PTR_02323784;
    *(undefined **)(puVar1 + 0x20) = PTR_DAT_02323788 + 2;
    break;
  case 4:
    *(undefined **)(PTR_DAT_02323764 + 0x14) = PTR_PTR_0232378c;
    *(undefined **)(puVar1 + 0x20) = PTR_DAT_02323790 + 2;
  }
  FUN_023231f4(PTR_DAT_02323794);
  FUN_023232e8(PTR_DAT_02323794);
  FUN_023240f4(PTR_DAT_02323794);
  return;
}

