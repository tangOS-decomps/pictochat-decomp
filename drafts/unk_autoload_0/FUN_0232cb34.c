// decomp: module=unk_autoload_0 addr=0x0232cb34 name=FUN_0232cb34
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90, thumb
// triage: noise=2 statements=42
// verify:  python tools/match.py --c <file> --func FUN_0232cb34 --addr 0x0232cb34 --size 0x90 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232cb34(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0232c520(1,2,param_3,param_4,param_4);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 != (int *)0x0) {
    if (((short)param_2[1] != 0) && (*param_2 == 0)) {
      return 6;
    }
    if ((short)param_2[5] == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0x2a;
    }
    if ((uint)*(ushort *)(param_2 + 0xd) + iVar1 < 0x201) {
      if ((short)param_2[5] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 6;
      }
      if ((uint)*(ushort *)((int)param_2 + 0x36) + iVar1 < 0x201) {
        FUN_0232cbc4(param_2);
        FUN_0232c3bc(7,param_1);
        FUN_023314e8(param_2,0x40);
        if ((short)param_2[1] != 0) {
          FUN_023314e8(*param_2);
        }
        iVar1 = FUN_0232c408(7,1,param_2);
        if (iVar1 != 0) {
          return iVar1;
        }
        return 2;
      }
    }
    return 6;
  }
  return 6;
}

