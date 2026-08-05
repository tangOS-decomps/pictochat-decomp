// decomp: module=unk_autoload_0 addr=0x023396c0 name=FUN_023396c0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0xb2 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=49
// verify:  python tools/match.py --c <file> --func FUN_023396c0 --addr 0x023396c0 --size 0xc0 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023396c0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    do {
      iVar2 = FUN_023393f0(0);
    } while (iVar2 != 0);
    if ((uint)(*DAT_02339774 - *(int *)(DAT_02339778 + 8)) < 3) {
      FUN_0233210c();
      FUN_0233210c();
    }
    piVar1 = DAT_02339774;
    *DAT_0233977c = *DAT_0233977c & 0xfffe;
    *(int *)(DAT_02339778 + 4) = *piVar1;
    if (param_2 != 0) {
      if (param_4 == 0) {
        FUN_023392c0(param_2,0,0);
      }
      else {
        FUN_023392f8(param_2);
      }
    }
  }
  else if (param_1 == 1) {
    if ((param_3 == 0) && ((uint)(*DAT_02339774 - *(int *)(DAT_02339778 + 4)) < 8)) {
      return 0;
    }
    if (param_2 != 0) {
      if (param_4 == 0) {
        do {
          iVar2 = FUN_023392c0(param_2,0,0);
        } while (iVar2 != 0);
      }
      else {
        do {
          iVar2 = FUN_023392f8(param_2);
        } while (iVar2 != 0);
      }
    }
    *DAT_0233977c = *DAT_0233977c | 1;
    iVar2 = DAT_02339778;
    do {
      iVar3 = FUN_023393f0(*(undefined4 *)(iVar2 + 0x14));
    } while (iVar3 != 0);
  }
  return 1;
}

