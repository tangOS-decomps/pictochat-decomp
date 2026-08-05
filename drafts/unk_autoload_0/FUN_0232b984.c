// decomp: module=unk_autoload_0 addr=0x0232b984 name=FUN_0232b984
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x40 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=23
// verify:  python tools/match.py --c <file> --func FUN_0232b984 --addr 0x0232b984 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232b984(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_02332080();
  iVar4 = FUN_0232b95c();
  puVar1 = PTR_DAT_0232b9c4;
  if (iVar4 != 0) {
    *(undefined4 *)(PTR_DAT_0232b9c4 + 0x14) = 1;
    puVar2 = PTR_DAT_0232b9c8;
    *(undefined4 *)(puVar1 + 0x28) = param_2;
    *(undefined4 *)puVar2 = param_1;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0xffffffff;
    FUN_0232bcfc();
    FUN_02332094(uVar3);
    return 1;
  }
  FUN_02332094(uVar3);
  return 0;
}

