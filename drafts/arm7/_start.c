// decomp: module=arm7 addr=0x022c0000 name=_start
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc0 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=27
// verify:  python tools/match.py --c <file> --func _start --addr 0x022c0000 --size 0xc0 --module arm7 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _start(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_022c009c;
  _DAT_04000208 = 0x4000000;
  puVar2 = DAT_022c0098;
  if (-1 < 0x3800000 - (int)DAT_022c0098) {
    puVar2 = (undefined4 *)&DAT_03800000;
  }
  for (; (int)puVar2 < iVar1; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  FUN_022c00c0(0x1f);
  puVar3 = *(undefined4 **)(DAT_022c00ac + 0x10);
  for (puVar2 = *(undefined4 **)(DAT_022c00ac + 0xc); puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  FUN_022c011c();
  *DAT_022c00b0 = DAT_022c00b4;
                    /* WARNING: Could not recover jumptable at 0x022c0094. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_022c00b8)();
  return;
}

