// decomp: module=unk_autoload_0 addr=0x0232e198 name=FUN_0232e198
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3e, thumb
// triage: noise=0 statements=18  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232e198 --addr 0x0232e198 --size 0x3e --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e198(int *param_1,uint param_2)

{
  int b;
  int iVar1;
  
  b = FUN_0232e178(param_1,0);
  while( true ) {
    if (b == 0) {
      return 0;
    }
    if ((*(uint *)(b + 0x18) <= param_2) && (param_2 < *(uint *)(b + 0x1c))) break;
    b = FUN_0232e178(param_1,b);
  }
  iVar1 = FUN_0232e198(b + 0xc,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  return b;
}

