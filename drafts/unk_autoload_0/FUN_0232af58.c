// decomp: module=unk_autoload_0 addr=0x0232af58 name=FUN_0232af58
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb4 (Ghidra's cache says 0x96 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=46
// verify:  python tools/match.py --c <file> --func FUN_0232af58 --addr 0x0232af58 --size 0xb4 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232af58(int param_1)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_0232981c();
  if (iVar2 == 0) {
    sVar1 = *(short *)(param_1 + 2);
    if (((sVar1 == 0) && (*(short *)(param_1 + 8) == 9)) && (*(int *)(DAT_0232b004 + 0x30) != 0)) {
      FUN_02329734();
      return;
    }
    if (sVar1 == 0) {
      switch(*(undefined2 *)(param_1 + 8)) {
      default:
        FUN_02329bd8(0xc);
        return;
      case 6:
        FUN_0232acb4();
        return;
      case 7:
        FUN_0232acb8(param_1);
        return;
      case 8:
        FUN_0232acd4();
        return;
      case 9:
        FUN_0232acd8(param_1);
        return;
      }
    }
    if (sVar1 == 1) {
      if (*(int *)(DAT_0232b004 + 0x48) != 0) {
        FUN_02329b2c(DAT_0232b008,0);
        return;
      }
      FUN_02329bd8(1);
      return;
    }
    if (sVar1 == 0xc) {
      FUN_02329bd8(0xd);
      return;
    }
    FUN_02329bd8(0xc);
  }
  return;
}

