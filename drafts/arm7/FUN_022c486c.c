// decomp: module=arm7 addr=0x022c486c name=FUN_022c486c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=14
// verify:  python tools/match.py --c <file> --func FUN_022c486c --addr 0x022c486c --size 0x38 --module arm7 --version 2.0/sp1


ulonglong FUN_022c486c(uint param_1)

{
  uint uVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar2 = FUN_022c4854();
  uVar4 = *DAT_022c48a0;
  puVar3 = DAT_022c48a0 + -2;
  *DAT_022c48a0 = uVar4 | param_1;
  uVar1 = *puVar3;
  *(ushort *)puVar3 = uVar2;
  return (ulonglong)CONCAT24((ushort)uVar1,uVar4);
}

