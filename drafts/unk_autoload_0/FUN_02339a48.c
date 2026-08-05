// decomp: module=unk_autoload_0 addr=0x02339a48 name=FUN_02339a48
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x72 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=34
// verify:  python tools/match.py --c <file> --func FUN_02339a48 --addr 0x02339a48 --size 0x78 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339a48(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (1 < param_1) {
    return 2;
  }
  if (1 < *param_2) {
    return 2;
  }
  FUN_02332080();
  if (*(int *)(DAT_02339abc + 4) != 0) {
    FUN_02332094();
    return 1;
  }
  *(undefined4 *)(DAT_02339abc + 4) = 1;
  FUN_02332094();
  if (param_1 == 0) {
    *(undefined4 *)(DAT_02339abc + 0x18) = 9;
  }
  else if (param_1 == 1) {
    *(undefined4 *)(DAT_02339abc + 0x18) = 10;
  }
  iVar1 = DAT_02339abc;
  *(undefined4 *)(DAT_02339abc + 0x1c) = 0;
  *(int **)(iVar1 + 0xc) = param_2;
  *(undefined4 *)(iVar1 + 8) = param_3;
  *(undefined4 *)(iVar1 + 0x14) = param_4;
  iVar1 = FUN_02339e78();
  if (iVar1 == 0) {
    *(undefined4 *)(DAT_02339abc + 4) = 0;
    return 3;
  }
  return 0;
}

