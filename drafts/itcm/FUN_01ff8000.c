// decomp: module=itcm addr=0x01ff8000 name=FUN_01ff8000
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=22
// verify:  python tools/match.py --c <file> --func FUN_01ff8000 --addr 0x01ff8000 --size 0x58 --module itcm --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01ff8000(void)

{
  int iVar1;
  uint uVar2;
  
  if (_DAT_04000208 == 0) {
    return;
  }
  uVar2 = _DAT_04000210 & _DAT_04000214;
  if (uVar2 != 0) {
    do {
      iVar1 = LZCOUNT(uVar2);
      uVar2 = uVar2 & ~(0x80000000U >> iVar1);
    } while (uVar2 != 0);
    _DAT_04000214 = 0x80000000 >> iVar1;
                    /* WARNING: Could not recover jumptable at 0x01ff804c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_01ff8050 + (0x1f - iVar1) * 4))();
    return;
  }
  return;
}

