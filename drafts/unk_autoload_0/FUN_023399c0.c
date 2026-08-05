// decomp: module=unk_autoload_0 addr=0x023399c0 name=FUN_023399c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x5c - it excludes this function's trailing literal pool), thumb
// triage: noise=9 statements=23
// verify:  python tools/match.py --c <file> --func FUN_023399c0 --addr 0x023399c0 --size 0x64 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023399c0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  *DAT_02339a1c = *param_1 & 0xff | *DAT_02339a1c & 0xffffff00;
  FUN_02332080();
  if (*(int *)(DAT_02339a20 + 4) != 0) {
    FUN_02332094();
    return 1;
  }
  *(undefined4 *)(DAT_02339a20 + 4) = 1;
  FUN_02332094();
  iVar1 = DAT_02339a20;
  *(undefined4 *)(DAT_02339a20 + 0x18) = 0xf;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = param_3;
  iVar1 = FUN_02339e90();
  if (iVar1 != 0) {
    return 0;
  }
  *(undefined4 *)(DAT_02339a20 + 4) = 0;
  return 3;
}

