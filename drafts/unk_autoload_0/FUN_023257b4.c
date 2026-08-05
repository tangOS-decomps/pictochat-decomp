// decomp: module=unk_autoload_0 addr=0x023257b4 name=FUN_023257b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50, thumb
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_023257b4 --addr 0x023257b4 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_023257b4(byte *param_1,byte *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = param_1;
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
    if ((*param_2 & 0xf) != 0) {
      *pbVar2 = (*pbVar2 & 0xf0) + (*param_2 & 0xf);
    }
    if ((*param_2 & 0xf0) != 0) {
      *pbVar2 = (*param_2 & 0xf0) + (*pbVar2 & 0xf);
    }
    pbVar2 = pbVar2 + 1;
    param_2 = param_2 + 1;
  }
  FUN_02331504(param_1,param_3,param_3,param_2,param_4);
  return;
}

