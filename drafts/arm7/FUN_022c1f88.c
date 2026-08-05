// decomp: module=arm7 addr=0x022c1f88 name=FUN_022c1f88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022c1f88 --addr 0x022c1f88 --size 0x6c --module arm7 --version 2.0/sp1


void FUN_022c1f88(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = DAT_022c1ff0;
  iVar2 = *DAT_022c1fec;
  *DAT_022c1ff0 = 0x2000;
  puVar1[0x4e] = 0xd;
  if (*(short *)(iVar2 + 0x35e) == 1) {
    *(undefined2 *)(iVar2 + 0x35e) = 2;
    return;
  }
  if (*(short *)(iVar2 + 0x35e) != 2) {
    if (*(short *)(iVar2 + 0x350) == 2) {
      if (*(short *)(iVar2 + 0x34c) != 0x40) {
        puVar1[0x1c] = 0;
      }
      return;
    }
    return;
  }
  *(undefined2 *)(iVar2 + 0x35e) = 0;
  return;
}

