// decomp: module=unk_autoload_0 addr=0x023296d8 name=FUN_023296d8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=27
// verify:  python tools/match.py --c <file> --func FUN_023296d8 --addr 0x023296d8 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023296d8(undefined2 param_1,code *param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_02331c10();
  FUN_02331d84();
  *(undefined4 *)(DAT_02329730 + 0x10) = 0;
  iVar2 = FUN_0232996c();
  puVar1 = DAT_02329730;
  if (iVar2 == 0) {
    *DAT_02329730 = param_1;
    *(code **)(puVar1 + 0xe) = param_2;
    *(undefined4 *)(puVar1 + 6) = param_3;
    *(undefined4 *)(puVar1 + 4) = 1;
    uVar3 = (*param_2)(0xf00,0x20);
    *(undefined4 *)(DAT_02329730 + 2) = uVar3;
    iVar2 = FUN_02329a5c();
    if (iVar2 != 0) {
      FUN_02329c14(4,8);
      FUN_0232a264();
      return 1;
    }
    FUN_023298a0();
  }
  return 0;
}

