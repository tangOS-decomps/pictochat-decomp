// decomp: module=arm7 addr=0x022c4948 name=FUN_022c4948
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x68 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022c4948 --addr 0x022c4948 --size 0x74 --module arm7 --version 2.0/sp1


void FUN_022c4948(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_022c49b4;
  if (*DAT_022c49b0 == 0) {
    *DAT_022c49b0 = 1;
    *(undefined2 *)(iVar1 + 6) = 0;
    while (puVar2 = DAT_022c49b8, *(short *)(iVar1 + 4) != 0x7f) {
      thunk_EXT_FUN_037fb7b8(0x400);
    }
    *DAT_022c49b8 = 0xffffffff;
    puVar2[1] = 0xffff0000;
    *(undefined2 *)(iVar1 + 6) = 0xbf;
  }
  return;
}

