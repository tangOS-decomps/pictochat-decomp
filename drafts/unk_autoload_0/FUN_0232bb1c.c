// decomp: module=unk_autoload_0 addr=0x0232bb1c name=FUN_0232bb1c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7e, thumb
// triage: noise=3 statements=30
// verify:  python tools/match.py --c <file> --func FUN_0232bb1c --addr 0x0232bb1c --size 0x7e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232bb1c(int param_1)

{
  int iVar1;
  short local_30 [10];
  undefined1 auStack_1c [20];
  
  iVar1 = FUN_0232981c();
  if (iVar1 == 0) {
    if (((*(short *)(param_1 + 2) == 0) && (*(short *)(param_1 + 0x10) != 0)) &&
       (*(short *)(param_1 + 4) == 0x15)) {
      FUN_02337584(*(undefined4 *)(param_1 + 0xc),auStack_1c,0x14);
    }
    if (((*(short *)(param_1 + 2) == 0) && (*(short *)(param_1 + 0x10) != 0)) &&
       (*(short *)(param_1 + 4) == 0x15)) {
      FUN_02337584(*(undefined4 *)(param_1 + 0xc),local_30,0x14);
      if (local_30[0] == 0) {
        FUN_0232ba40(param_1,local_30);
        return;
      }
      if (local_30[0] == 1) {
        FUN_0232ba7c(param_1,local_30);
        return;
      }
      if (local_30[0] != 3) {
        return;
      }
      FUN_0232bac4(param_1,local_30);
    }
  }
  return;
}

