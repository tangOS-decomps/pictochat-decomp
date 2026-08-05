// decomp: module=unk_autoload_0 addr=0x02337ad0 name=FUN_02337ad0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c, thumb
// triage: noise=0 statements=33  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02337ad0 --addr 0x02337ad0 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


int FUN_02337ad0(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_02337e08();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_02337dd8();
  if (iVar1 == 0) {
    if ((param_1 & 1) == 0) {
      return 0;
    }
    iVar1 = FUN_02337d54();
    if (iVar1 < 1) {
      FUN_02337b54(1);
    }
    else {
      do {
        iVar1 = FUN_02337a28(0);
      } while (iVar1 != 0);
      iVar1 = FUN_02337dd8();
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    FUN_02337dc0();
    do {
      FUN_02337a28(1);
      iVar1 = FUN_02337dd8();
    } while (iVar1 == 0);
  }
  return iVar1;
}

