// decomp: module=arm7 addr=0x022dff6c name=FUN_022dff6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_022dff6c --addr 0x022dff6c --size 0x58 --module arm7 --version 2.0/sp1


void FUN_022dff6c(ushort param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  
  piVar1 = DAT_022dffc0;
  puVar2 = *(undefined2 **)(*DAT_022dffc0 + 0x45c);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[5] = 0x14;
  puVar2[6] = 0xa4;
  puVar2[7] = param_1 | 0xc000;
  FUN_022d8138(puVar2 + 8,(ushort *)(*piVar1 + 0x3a8),(ushort *)(*piVar1 + 0x324));
  return;
}

