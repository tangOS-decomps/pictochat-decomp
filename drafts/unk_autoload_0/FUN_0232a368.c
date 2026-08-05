// decomp: module=unk_autoload_0 addr=0x0232a368 name=FUN_0232a368
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xa6 - it excludes this function's trailing literal pool), thumb
// triage: noise=14 statements=40
// verify:  python tools/match.py --c <file> --func FUN_0232a368 --addr 0x0232a368 --size 0xc0 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232a368(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  
  *(undefined4 *)(PTR_DAT_0232a410 + 0x14) = 0;
  FUN_02331ef0(PTR_DAT_0232a414);
  FUN_02329d0c(0);
  *(undefined4 *)(PTR_DAT_0232a410 + 0x54) = 0;
  FUN_02331ef0(PTR_DAT_0232a418);
  puVar1 = PTR_DAT_0232a410;
  *(undefined4 *)(PTR_DAT_0232a410 + 0x30) = 0;
  *(undefined4 *)(puVar1 + 0x40) = 0;
  FUN_023298d8();
  iVar2 = FUN_0232996c();
  if (iVar2 != 1) {
    return 0;
  }
  uVar3 = FUN_02331ca8();
  *(undefined4 *)(PTR_DAT_0232a410 + 0x4c) = uVar3;
  FUN_0232c8c0(0xc,PTR_FUN_0232aa3c_1_0232a41c,0);
  FUN_02329d44(param_1);
  FUN_0232b9e4();
  FUN_0232c0c4();
  puVar1 = PTR_DAT_0232a410;
  *(undefined4 *)(PTR_DAT_0232a410 + 0x10) = 0;
  *(undefined4 *)(puVar1 + 0x20) = 0;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  FUN_0232aa0c();
  if (param_2 == 0) {
    iVar2 = DAT_0232a420 * *(int *)(PTR_DAT_0232a410 + 0x4c) + DAT_0232a424;
    *(int *)(PTR_DAT_0232a410 + 0x4c) = iVar2;
    FUN_02336018(iVar2,200);
    uVar3 = FUN_02329db8(param_1,1,1,extraout_r1 * 2 + 500);
    return uVar3;
  }
  FUN_0232a620(param_2,0);
  return 1;
}

