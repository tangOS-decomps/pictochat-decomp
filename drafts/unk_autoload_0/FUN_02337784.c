// decomp: module=unk_autoload_0 addr=0x02337784 name=FUN_02337784
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, thumb
// triage: noise=3 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02337784 --addr 0x02337784 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337784(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  for (uVar2 = param_3; (iVar1 < 8 && (uVar2 != 0)); uVar2 = uVar2 >> 1) {
    if ((uVar2 & 1) != 0) {
      FUN_02337e54(iVar1);
    }
    iVar1 = iVar1 + 1;
  }
  FUN_02337930(0xd,param_1,param_2,param_3,param_4);
  return;
}

