// decomp: module=unk_autoload_0 addr=0x023201fc name=FUN_023201fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0x8e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=40
// verify:  python tools/match.py --c <file> --func FUN_023201fc --addr 0x023201fc --size 0xa8 --module unk_autoload_0 --version 2.0/sp1


void FUN_023201fc(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = false;
  if (param_1 == 0) {
    if (param_2 == 0) {
      iVar3 = FUN_02322800(4,(*DAT_0232028c & 0x3f) >> 4,DAT_02320290,1);
      if (iVar3 != 0) {
        bVar1 = true;
      }
    }
    else if (param_2 == 1) {
      uVar4 = 2;
      piVar2 = FUN_0232254c();
      if (*piVar2 << 0x1b < 0) {
        uVar4 = (*DAT_0232028c & 0xf) >> 3;
      }
      iVar3 = FUN_02339318(uVar4,1,DAT_02320290,2);
      if (iVar3 != 0) {
        bVar1 = true;
      }
    }
    else if (param_2 == 2) {
      *DAT_02320294 = 1;
      FUN_02331dac();
    }
  }
  else {
    bVar1 = true;
    param_2 = param_2 + -1;
  }
  if (bVar1) {
    FUN_02331ef0(DAT_02320298);
    FUN_02331ea8(DAT_02320298,DAT_0232029c,0,DAT_023202a0,param_2,param_4);
  }
  return;
}

