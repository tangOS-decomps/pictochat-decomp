// decomp: module=unk_autoload_0 addr=0x02339908 name=FUN_02339908
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=25  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02339908 --addr 0x02339908 --size 0x40 --module unk_autoload_0 --version 2.0/sp1


void FUN_02339908(void)

{
  short *psVar1;
  int iVar2;
  
  psVar1 = DAT_02339940;
  if (*DAT_02339940 == 0) {
    *DAT_02339940 = 1;
    psVar1[2] = 0;
    psVar1[3] = 0;
    psVar1[4] = 0;
    psVar1[5] = 0;
    psVar1[0x10] = 0;
    psVar1[0x11] = 0;
    psVar1[6] = 0;
    psVar1[7] = 0;
    psVar1[8] = 0;
    psVar1[9] = 0;
    FUN_023381f8();
    do {
      iVar2 = FUN_023382f8(5,1);
    } while (iVar2 == 0);
    FUN_023382ac(5,DAT_02339944);
  }
  return;
}

