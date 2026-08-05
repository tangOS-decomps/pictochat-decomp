// decomp: module=unk_autoload_0 addr=0x023234d0 name=FUN_023234d0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40, thumb
// triage: noise=0 statements=18  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023234d0 --addr 0x023234d0 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_023234d0(int param_1,int param_2,byte *param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      FUN_02337454(param_2 + (uint)*param_3 * 0x20,param_1,0x20);
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 0x20;
      param_3 = param_3 + 1;
    } while (uVar1 < 0x19);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xb);
  FUN_02337440(0,param_1,0x20);
  return;
}

