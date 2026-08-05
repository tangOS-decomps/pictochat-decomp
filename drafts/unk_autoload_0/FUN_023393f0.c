// decomp: module=unk_autoload_0 addr=0x023393f0 name=FUN_023393f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=3 statements=11
// verify:  python tools/match.py --c <file> --func FUN_023393f0 --addr 0x023393f0 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023393f0(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_02339794();
  if (iVar1 != 0) {
    uVar2 = FUN_02339298(0x10,param_1,0);
    return uVar2;
  }
  return 0;
}

