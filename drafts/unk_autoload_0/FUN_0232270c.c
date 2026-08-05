// decomp: module=unk_autoload_0 addr=0x0232270c name=FUN_0232270c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x9c (Ghidra's cache says 0x90 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=34  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232270c --addr 0x0232270c --size 0x9c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232270c(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = FUN_0232254c();
  uVar2 = FUN_023226d4();
  uVar3 = *puVar1;
  if (-1 < (int)(uVar3 << 0x19)) {
    if (((int)(uVar3 << 0x17) < 0) && ((uVar2 & DAT_0232279c) == DAT_0232279c)) {
      *puVar1 = uVar3 | 0x10;
      return;
    }
    if ((((int)((uint)*DAT_023227a0 << 0x19) < 0) && ((*DAT_023227a4 & 1) != 0)) &&
       (-1 < (int)(*puVar1 << 0x1c))) {
      if ((*DAT_023227a4 & 2) == 0) {
        *puVar1 = *puVar1 | 0x10;
        return;
      }
      iVar4 = 0;
      while ((uVar2 & 2) != 0) {
        FUN_0233210c();
        uVar2 = FUN_023226d4();
        iVar4 = iVar4 + 1;
        if (0x1d < iVar4) {
          *puVar1 = *puVar1 | 0x10;
          return;
        }
      }
    }
  }
  return;
}

