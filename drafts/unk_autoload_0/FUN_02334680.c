// decomp: module=unk_autoload_0 addr=0x02334680 name=FUN_02334680
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x26, thumb
// triage: noise=0 statements=20  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334680 --addr 0x02334680 --size 0x26 --module unk_autoload_0 --version 2.0/sp1


int FUN_02334680(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar1 = *param_2;
    uVar2 = (uint)*param_1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    if (uVar2 != uVar1) break;
    if (uVar2 == 0) {
      return 0;
    }
    param_3 = param_3 + -1;
  }
  return uVar2 - uVar1;
}

