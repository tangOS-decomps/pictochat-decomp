// decomp: module=unk_autoload_0 addr=0x02329d44 name=FUN_02329d44
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x62 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=30  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02329d44 --addr 0x02329d44 --size 0x68 --module unk_autoload_0 --version 2.0/sp1


void FUN_02329d44(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 == 0) || (iVar1 = FUN_0232996c(), iVar1 == 1)) {
    uVar2 = FUN_0232ca20();
    if (uVar2 != 0) {
      uVar3 = 0;
      *(char *)(DAT_02329da8 + 2) = (char)param_1;
      if (2 < param_1) {
        param_1 = param_1 + 1;
      }
      do {
        for (; (1 << uVar3 & uVar2) == 0; uVar3 = uVar3 + 1 & 0xf) {
        }
        uVar4 = uVar3 + 1;
        uVar3 = uVar4 & 0xf;
        param_1 = param_1 + -1;
      } while (-1 < param_1);
      FUN_02329d24(uVar4);
      FUN_0232a4fc(uVar4);
      return;
    }
    FUN_02329bd8(0xe);
  }
  return;
}

