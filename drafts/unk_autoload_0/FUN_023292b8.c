// decomp: module=unk_autoload_0 addr=0x023292b8 name=FUN_023292b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c, thumb
// triage: noise=1 statements=13
// verify:  python tools/match.py --c <file> --func FUN_023292b8 --addr 0x023292b8 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


int FUN_023292b8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x54) == 2) {
    uVar1 = FUN_02329994();
    iVar2 = FUN_02332e38(uVar1,param_1,6);
    if (iVar2 != 0) {
      return param_1 + 6;
    }
  }
  return 0;
}

