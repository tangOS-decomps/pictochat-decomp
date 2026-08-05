// decomp: module=unk_autoload_0 addr=0x02320fa0 name=FUN_02320fa0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x82 - it excludes this function's trailing literal pool), thumb
// triage: noise=13 statements=36
// verify:  python tools/match.py --c <file> --func FUN_02320fa0 --addr 0x02320fa0 --size 0x8c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02320fa0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x600) == 0x7f) {
    return 0;
  }
  if ((param_3 != (undefined4 *)0x0) && (*(int *)(param_1 + 0x604) == 0x1f)) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x600) * 8;
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + iVar3) = *param_2;
  *(undefined4 *)(param_1 + iVar3 + 4) = uVar1;
  if (param_3 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + DAT_02321024);
  }
  iVar3 = *(int *)(param_1 + 0x600) * 8;
  *(uint *)(param_1 + iVar3) = (uVar2 & 0x1f) << 0x19 | DAT_02321028 & *(uint *)(param_1 + iVar3);
  if (param_3 != (undefined4 *)0x0) {
    iVar3 = param_1 + *(int *)(param_1 + 0x604) * 0x10;
    uVar1 = param_3[1];
    *(undefined4 *)(iVar3 + 0x400) = *param_3;
    *(undefined4 *)(iVar3 + 0x404) = uVar1;
    uVar1 = param_3[3];
    *(undefined4 *)(iVar3 + 0x408) = param_3[2];
    *(undefined4 *)(iVar3 + 0x40c) = uVar1;
    *(int *)(param_1 + 0x604) = *(int *)(param_1 + 0x604) + 1;
  }
  *(int *)(param_1 + 0x600) = *(int *)(param_1 + 0x600) + 1;
  return 1;
}

