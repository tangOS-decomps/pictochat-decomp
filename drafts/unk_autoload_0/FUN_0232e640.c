// decomp: module=unk_autoload_0 addr=0x0232e640 name=FUN_0232e640
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e640 --addr 0x0232e640 --size 0x3e --module unk_autoload_0 --version 2.0/sp1


uint FUN_0232e640(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_1;
  uVar3 = ~(param_3 - 1U) & (param_3 - 1U) + uVar1;
  uVar2 = param_2 + uVar3;
  if (param_1[1] < uVar2) {
    return 0;
  }
  if ((param_1[-1] & 1) != 0) {
    FUN_02337440(0,uVar1,uVar2 - uVar1);
  }
  *param_1 = uVar2;
  return uVar3;
}

