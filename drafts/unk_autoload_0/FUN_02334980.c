// decomp: module=unk_autoload_0 addr=0x02334980 name=FUN_02334980
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24, thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334980 --addr 0x02334980 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334980(int param_1,int param_2)

{
  int iVar1;
  
  if ((0 < param_2) && (param_2 < (int)(uint)*(byte *)(param_1 + 4))) {
    iVar1 = FUN_023348fc();
    *(char *)(param_1 + 4) = (char)param_2;
    if (-1 < iVar1) {
      FUN_02334948(param_1,param_2);
    }
  }
  return;
}

