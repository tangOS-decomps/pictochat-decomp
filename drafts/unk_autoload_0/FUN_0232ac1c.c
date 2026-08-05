// decomp: module=unk_autoload_0 addr=0x0232ac1c name=FUN_0232ac1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232ac1c --addr 0x0232ac1c --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ac1c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_0232a648(*(undefined2 *)(param_1 + 0x10),0,param_3,param_4,param_4);
  FUN_0232a824();
  iVar1 = DAT_0232ac58;
  *(short *)(DAT_0232ac58 + 6) = *(short *)(DAT_0232ac58 + 6) + -1;
  *(undefined4 *)(iVar1 + 0x38) = 1;
  if (*(ushort *)(iVar1 + 6) < 2) {
    FUN_02329bd8(2);
    if (*(int *)(DAT_0232ac58 + 0x30) == 0) {
      FUN_0232b9e4();
      FUN_02329b2c(DAT_0232ac5c,0);
    }
  }
  return;
}

