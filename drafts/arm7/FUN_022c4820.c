// decomp: module=arm7 addr=0x022c4820 name=FUN_022c4820
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022c4820 --addr 0x022c4820 --size 0x34 --module arm7 --version 2.0/sp1


ulonglong FUN_022c4820(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  uVar2 = FUN_022c4854();
  uVar4 = *DAT_022c4850;
  puVar3 = (ushort *)(DAT_022c4850 + -2);
  *DAT_022c4850 = param_1;
  uVar1 = *puVar3;
  *puVar3 = uVar2;
  return (ulonglong)CONCAT24(uVar1,uVar4);
}

