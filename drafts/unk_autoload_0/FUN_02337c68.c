// decomp: module=unk_autoload_0 addr=0x02337c68 name=FUN_02337c68
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44, thumb
// triage: noise=1 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02337c68 --addr 0x02337c68 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02337c68(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_02337ccc();
  if (iVar1 == 0) {
    do {
      iVar1 = FUN_02337a28(0);
    } while (iVar1 != 0);
    iVar1 = FUN_02337ccc(param_1);
    if (iVar1 == 0) {
      FUN_02337dc0();
      iVar1 = FUN_02337ccc(param_1);
      while (iVar1 == 0) {
        FUN_02337a28(1);
        iVar1 = FUN_02337ccc(param_1);
      }
    }
  }
  return;
}

