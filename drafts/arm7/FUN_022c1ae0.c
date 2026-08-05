// decomp: module=arm7 addr=0x022c1ae0 name=FUN_022c1ae0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c1ae0 --addr 0x022c1ae0 --size 0xa4 --module arm7 --version 2.0/sp1


void FUN_022c1ae0(uint param_1)

{
  int iVar1;
  
  iVar1 = *DAT_022c1b78;
  if (*(ushort *)(iVar1 + 0x34c) != param_1) {
    if (*(ushort *)(iVar1 + 0x34c) == 0x40) {
      FUN_022c6600(iVar1 + 0x634);
    }
    if (param_1 == 0) {
      func_0x00dd3550();
    }
    else if (param_1 == 0x10) {
      *DAT_022c1b7c = 0;
      FUN_022c1a40();
      func_0x00dd35d8();
    }
    else if (param_1 == 0x40) {
      if (*(short *)(iVar1 + 0x350) == 2) {
        func_0x00dd373c();
      }
      func_0x00dd4218(100,DAT_022c1b80);
    }
    *(short *)(iVar1 + 0x34c) = (short)param_1;
  }
  return;
}

