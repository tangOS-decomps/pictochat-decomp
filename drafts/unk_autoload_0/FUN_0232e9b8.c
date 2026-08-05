// decomp: module=unk_autoload_0 addr=0x0232e9b8 name=FUN_0232e9b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1e, thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_0232e9b8 --addr 0x0232e9b8 --size 0x1e --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e9b8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  if (*param_1 != 0) {
    cVar1 = *(char *)(*param_1 + 0x2c);
    if (cVar1 != '\x02') {
      FUN_02330590(*param_1 + 0x1c,param_2 << 8,param_3,cVar1,param_4);
    }
  }
  return;
}

