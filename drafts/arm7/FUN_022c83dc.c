// decomp: module=arm7 addr=0x022c83dc name=FUN_022c83dc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x78 (Ghidra's cache says 0x70 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=22
// verify:  python tools/match.py --c <file> --func FUN_022c83dc --addr 0x022c83dc --size 0x78 --module arm7 --version 2.0/sp1


void FUN_022c83dc(uint param_1)

{
  undefined4 *p;
  uint uVar1;
  
  uVar1 = 0;
  for (; ((int)uVar1 < 0x10 && (param_1 != 0)); param_1 = param_1 >> 1) {
    if (((param_1 & 1) != 0) &&
       (p = (undefined4 *)(DAT_022c844c + uVar1 * 0x54),
       (1 << (uVar1 & 0xff) & *(uint *)(DAT_022c8450 + 4)) == 0)) {
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
  return;
}

