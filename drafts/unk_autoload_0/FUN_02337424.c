// decomp: module=unk_autoload_0 addr=0x02337424 name=FUN_02337424
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c, arm
// triage: noise=2 statements=8
// verify:  python tools/match.py --c <file> --func FUN_02337424 --addr 0x02337424 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02337424(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 2) {
    *(undefined2 *)(param_2 + iVar1) = *(undefined2 *)(param_1 + iVar1);
  }
  return;
}

