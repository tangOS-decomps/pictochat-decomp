// decomp: module=unk_autoload_0 addr=0x02329db8 name=FUN_02329db8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x76 - it excludes this function's trailing literal pool), thumb
// triage: noise=10 statements=29
// verify:  python tools/match.py --c <file> --func FUN_02329db8 --addr 0x02329db8 --size 0x80 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329db8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_023298d8(0);
  iVar1 = FUN_0232996c();
  if (iVar1 == 1) {
    FUN_02329d44(param_1);
    FUN_02329bd8(3);
    if (param_2 == 0) {
      FUN_0232b6d8(*(int *)(DAT_02329e30 + 0x30) + (uint)*(byte *)(DAT_02329e30 + 2) * 0x10,500);
      FUN_02329d0c(0);
    }
    else {
      FUN_0232b6b0(*(int *)(DAT_02329e30 + 0x30) + (uint)*(byte *)(DAT_02329e30 + 2) * 0x10);
    }
    iVar1 = DAT_02329e30;
    *(undefined4 *)(DAT_02329e30 + 0xc) = 0;
    *(int *)(iVar1 + 0x1c) = param_2;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    FUN_02331ef0(DAT_02329e34);
    iVar1 = DAT_02329e30;
    *(undefined4 *)(DAT_02329e30 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 8) = param_3;
    *(undefined4 *)(iVar1 + 0x28) = 1;
    *(undefined4 *)(iVar1 + 0x2c) = param_4;
    FUN_0232a0b8();
  }
  return 1;
}

