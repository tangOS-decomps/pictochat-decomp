// decomp: module=unk_autoload_0 addr=0x023398b0 name=FUN_023398b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x42, thumb
// triage: noise=0 statements=17  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023398b0 --addr 0x023398b0 --size 0x42 --module unk_autoload_0 --version 2.0/sp1


void FUN_023398b0(void)

{
  int iVar1;
  
  FUN_023320fc(0x360000);
  iVar1 = FUN_02339794();
  if (iVar1 != 1) {
    do {
      iVar1 = FUN_02339374(2,0);
    } while (iVar1 != 0);
    iVar1 = FUN_02339780(1);
    while (iVar1 == 0) {
      FUN_023320fc(5);
      iVar1 = FUN_02339780(1);
    }
  }
  return;
}

