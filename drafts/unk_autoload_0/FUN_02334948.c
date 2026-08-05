// decomp: module=unk_autoload_0 addr=0x02334948 name=FUN_02334948
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x32, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02334948 --addr 0x02334948 --size 0x32 --module unk_autoload_0 --version 2.0/sp1


void FUN_02334948(int param_1,int param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + 5) + param_2;
  while( true ) {
    pbVar1 = pbVar1 + -1;
    if (*pbVar1 < 9) {
      *pbVar1 = *pbVar1 + 1;
      return;
    }
    if (pbVar1 == (byte *)(param_1 + 5)) break;
    *pbVar1 = 0;
  }
  *pbVar1 = 1;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  return;
}

