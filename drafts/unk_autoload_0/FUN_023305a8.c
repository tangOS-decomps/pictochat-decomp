// decomp: module=unk_autoload_0 addr=0x023305a8 name=FUN_023305a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023305a8 --addr 0x023305a8 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


int FUN_023305a8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[3] <= param_1[2]) {
    return param_1[1];
  }
  iVar2 = *param_1;
  iVar1 = FUN_02335e0c(param_1[2] * (param_1[1] - iVar2));
  return iVar2 + iVar1;
}

