// decomp: module=unk_autoload_0 addr=0x0232de74 name=FUN_0232de74
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54, thumb
// triage: noise=1 statements=33
// verify:  python tools/match.py --c <file> --func FUN_0232de74 --addr 0x0232de74 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


short * FUN_0232de74(undefined4 param_1,short *param_2,int *param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = *param_2;
  iVar3 = 0;
  while( true ) {
    if (sVar1 == 0) {
      if (param_3 != (int *)0x0) {
        if (param_4 < iVar3) {
          iVar3 = iVar3 - param_4;
        }
        *param_3 = iVar3;
      }
      return (short *)0x0;
    }
    if (sVar1 == 10) break;
    if (sVar1 != 0xd) {
      iVar2 = FUN_0232de60(param_1);
      iVar3 = iVar3 + param_4 + iVar2;
    }
    param_2 = param_2 + 1;
    sVar1 = *param_2;
  }
  if (param_3 != (int *)0x0) {
    if (param_4 < iVar3) {
      iVar3 = iVar3 - param_4;
    }
    *param_3 = iVar3;
  }
  return param_2 + 1;
}

