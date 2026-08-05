// decomp: module=unk_autoload_0 addr=0x0232e680 name=FUN_0232e680
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c, thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232e680 --addr 0x0232e680 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232e680(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = ~(param_3 - 1U) & param_1[1] - param_2;
  if (uVar1 < *param_1) {
    return 0;
  }
  if ((param_1[-1] & 1) != 0) {
    FUN_02337440(0,uVar1,param_1[1] - uVar1,param_4,param_4);
  }
  param_1[1] = uVar1;
  return uVar1;
}

