// decomp: module=arm7 addr=0x022c6168 name=FUN_022c6168
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7c (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=27
// verify:  python tools/match.py --c <file> --func FUN_022c6168 --addr 0x022c6168 --size 0x7c --module arm7 --version 2.0/sp1


void FUN_022c6168(void)

{
  short *psVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  
  if (*DAT_022c61d8 == 0) {
    *DAT_022c61d8 = 1;
    FUN_022c614c(0);
    psVar1 = DAT_022c61d8;
    psVar1[4] = 0;
    puVar2 = DAT_022c61dc;
    psVar1[5] = 0;
    psVar1[6] = 0;
    psVar1[7] = 0;
    *puVar2 = 0;
    uVar3 = DAT_022c61e0;
    puVar2[-1] = 0;
    *puVar2 = 0xc1;
    FUN_022c4738(8,uVar3,0xc1,puVar2,in_r3);
    FUN_022c486c(8);
    psVar1 = DAT_022c61d8;
    psVar1[2] = 0;
    psVar1[3] = 0;
  }
  return;
}

