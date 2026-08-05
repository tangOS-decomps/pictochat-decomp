// decomp: module=arm7 addr=0x022c8454 name=FUN_022c8454
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0 (Ghidra's cache says 0x96 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=29
// verify:  python tools/match.py --c <file> --func FUN_022c8454 --addr 0x022c8454 --size 0xa0 --module arm7 --version 2.0/sp1


void FUN_022c8454(uint param_1,uint param_2)

{
  undefined4 *p;
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = param_1; ((int)uVar1 < 0x10 && (uVar2 != 0)); uVar2 = uVar2 >> 1) {
    if (((uVar2 & 1) != 0) &&
       (p = (undefined4 *)(DAT_022c84ec + uVar1 * 0x54),
       (1 << (uVar1 & 0xff) & DAT_022c84f0[1]) == 0)) {
      if (p[0x12] != 0) {
        FUN_022c4438(p,0,p[0x13]);
      }
      FUN_022c77a0(uVar1,0);
      *(undefined1 *)((int)p + 0x22) = 0;
      FUN_022c83d0(p);
      *(byte *)((int)p + 3) = *(byte *)((int)p + 3) & 7;
      *(byte *)((int)p + 3) = *(byte *)((int)p + 3) & 0xfe;
    }
    uVar1 = uVar1 + 1;
  }
  if ((param_2 & 1) == 0) {
    DAT_022c84f0[1] = DAT_022c84f0[1] | param_1;
  }
  else {
    *DAT_022c84f0 = *DAT_022c84f0 | param_1;
  }
  return;
}

