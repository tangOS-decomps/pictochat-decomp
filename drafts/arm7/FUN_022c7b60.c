// decomp: module=arm7 addr=0x022c7b60 name=FUN_022c7b60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x40 (Ghidra's cache says 0x32 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=9  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_022c7b60 --addr 0x022c7b60 --size 0x40 --module arm7 --version 2.0/sp1


void FUN_022c7b60(void)

{
  longlong lVar1;
  
  lVar1 = thunk_EXT_FUN_037fdcec();
  thunk_EXT_FUN_037fe01c
            (DAT_022c7b9c,(int)(lVar1 + 0x10000),(int)((ulonglong)(lVar1 + 0x10000) >> 0x20),
             DAT_022c7b98,0,DAT_022c7b94,0);
  return;
}

