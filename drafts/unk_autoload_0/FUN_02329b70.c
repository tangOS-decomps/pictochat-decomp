// decomp: module=unk_autoload_0 addr=0x02329b70 name=FUN_02329b70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02329b70 --addr 0x02329b70 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_02329b70(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(DAT_02329bc4 + 0x18) = 0;
  FUN_02329bcc();
  iVar1 = DAT_02329bc4;
  if (*(short *)(param_1 + 2) == 0) {
    *(undefined4 *)(DAT_02329bc4 + 0x20) = 0;
    FUN_02329bd8(1);
    if ((*(int *)(DAT_02329bc4 + 8) == 0) || (*(int *)(DAT_02329bc4 + 8) == 0xb)) {
      FUN_02329ad4();
      return;
    }
  }
  else {
    *(int *)(DAT_02329bc4 + 0x20) = *(int *)(DAT_02329bc4 + 0x20) + 1;
    if (0x10 < *(int *)(iVar1 + 0x20)) {
      FUN_02329bd8(0xe);
      return;
    }
    FUN_02329b2c(DAT_02329bc8,1);
  }
  return;
}

