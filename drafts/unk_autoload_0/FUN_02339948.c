// decomp: module=unk_autoload_0 addr=0x02339948 name=FUN_02339948
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02339948 --addr 0x02339948 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339948(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_02332080();
  if (*(int *)(DAT_02339998 + 4) != 0) {
    FUN_02332094();
    return 1;
  }
  *(undefined4 *)(DAT_02339998 + 4) = 1;
  FUN_02332094();
  iVar1 = DAT_02339998;
  *(undefined4 *)(DAT_02339998 + 0x18) = 2;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0x14) = param_4;
  iVar1 = FUN_02339e6c();
  if (iVar1 != 0) {
    return 0;
  }
  *(undefined4 *)(DAT_02339998 + 4) = 0;
  return 3;
}

