// decomp: module=unk_autoload_0 addr=0x0232ec2c name=FUN_0232ec2c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x3a - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232ec2c --addr 0x0232ec2c --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ec2c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  FUN_023376e0(*(undefined1 *)(param_1 + 0x3c));
  if (*(int *)(iVar2 + 0x1c) != 0) {
    FUN_02337750(*(undefined1 *)(param_1 + 0x3c),DAT_0232ec68);
  }
  FUN_0232ece0(param_1);
  uVar1 = FUN_02337cac();
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  *(undefined1 *)(param_1 + 0x2f) = 1;
  *(undefined1 *)(param_1 + 0x2c) = 1;
  return;
}

