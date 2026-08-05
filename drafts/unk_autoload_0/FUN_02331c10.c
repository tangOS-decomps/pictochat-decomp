// decomp: module=unk_autoload_0 addr=0x02331c10 name=FUN_02331c10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02331c10 --addr 0x02331c10 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02331c10(void)

{
  short *psVar1;
  undefined2 *puVar2;
  
  if (*DAT_02331c50 == 0) {
    *DAT_02331c50 = 1;
    FUN_02331be8(0);
    psVar1 = DAT_02331c50;
    psVar1[4] = 0;
    puVar2 = DAT_02331c54;
    psVar1[5] = 0;
    psVar1[6] = 0;
    psVar1[7] = 0;
    *puVar2 = 0;
    puVar2[-1] = 0;
    *puVar2 = 0xc1;
    FUN_02330728(8,DAT_02331c58);
    FUN_023307d4(8);
    psVar1 = DAT_02331c50;
    psVar1[2] = 0;
    psVar1[3] = 0;
  }
  return;
}

