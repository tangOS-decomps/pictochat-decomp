// decomp: module=arm7 addr=0x022d6f6c name=FUN_022d6f6c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x74 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022d6f6c --addr 0x022d6f6c --size 0x80 --module arm7 --version 2.0/sp1


undefined4 FUN_022d6f6c(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  uVar4 = DAT_022d6fe8;
  puVar3 = DAT_022d6fe4;
  piVar2 = DAT_022d6fe0;
  if (param_1 < 4) {
    uVar1 = (ushort)param_1;
    *(ushort *)(*DAT_022d6fe0 + 0x32e) = uVar1;
    *(ushort *)(*piVar2 + 0x350) = uVar1;
    *puVar3 = *puVar3 & (ushort)uVar4 | uVar1;
    FUN_022d7c88(*(undefined2 *)(*piVar2 + 0x352));
    uVar4 = 0;
    *(uint *)(*DAT_022d6fe0 + 0x340) = *(uint *)(*DAT_022d6fe0 + 0x340) | 8;
  }
  else {
    uVar4 = 5;
  }
  return uVar4;
}

