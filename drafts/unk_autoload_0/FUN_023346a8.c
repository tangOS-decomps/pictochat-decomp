// decomp: module=unk_autoload_0 addr=0x023346a8 name=FUN_023346a8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023346a8 --addr 0x023346a8 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


ushort * FUN_023346a8(ushort *param_1,uint param_2)

{
  ushort uVar1;
  
  uVar1 = *param_1;
  while( true ) {
    if (uVar1 == 0) break;
    if (uVar1 == param_2) {
      return param_1;
    }
    uVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  if (param_2 == 0) {
    return param_1;
  }
  return (ushort *)0x0;
}

