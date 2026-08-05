// decomp: module=unk_autoload_0 addr=0x0233465c name=FUN_0233465c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x22, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0233465c --addr 0x0233465c --size 0x22 --module unk_autoload_0 --version 2.0/sp1


void FUN_0233465c(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  
  do {
    psVar2 = param_1;
    param_1 = psVar2 + 1;
  } while (*psVar2 != 0);
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    *psVar2 = sVar1;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return;
}

