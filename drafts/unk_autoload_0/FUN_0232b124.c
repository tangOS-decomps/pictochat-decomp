// decomp: module=unk_autoload_0 addr=0x0232b124 name=FUN_0232b124
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=48
// verify:  python tools/match.py --c <file> --func FUN_0232b124 --addr 0x0232b124 --size 0x9c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232b124(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0232981c();
  iVar3 = DAT_0232b1bc;
  if (iVar2 == 0) {
    sVar1 = *(short *)(param_1 + 2);
    if (sVar1 == 0) {
      switch(*(undefined2 *)(param_1 + 4)) {
      case 10:
        *(undefined4 *)(DAT_0232b1bc + 0x1c) = 0;
        if (*(short *)(iVar3 + 0xc) != 0) {
          iVar3 = FUN_0232996c();
          if (iVar3 == 8) {
            FUN_02329bd8(9);
          }
          FUN_0232a7c4();
          return;
        }
        iVar3 = FUN_02329978();
        FUN_0232a648(0,iVar3 + 0xe0);
        iVar3 = FUN_0232996c();
        if (iVar3 == 8) {
          FUN_02329bd8(10);
          return;
        }
        break;
      case 0xb:
        FUN_0232ad80();
        iVar3 = FUN_0232c0dc();
        if (iVar3 != 0) {
          FUN_0232a8b8();
          return;
        }
        break;
      case 0xc:
        FUN_0232ad80();
        return;
      }
    }
    else if (((sVar1 != 9) && (sVar1 != 0xd)) && (sVar1 != 0xf)) {
      FUN_02329bd8(0xc);
    }
  }
  return;
}

