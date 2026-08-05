// decomp: module=arm7 addr=0x022c6300 name=FUN_022c6300
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x7c - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022c6300 --addr 0x022c6300 --size 0x8c --module arm7 --version 2.0/sp1


void FUN_022c6300(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar5 = FUN_022c625c();
  *DAT_022c637c = 0;
  uVar4 = *(uint *)(param_1 + 0xc) - (uint)uVar5;
  iVar3 = *(int *)(param_1 + 0x10) -
          ((int)((ulonglong)uVar5 >> 0x20) + (uint)(*(uint *)(param_1 + 0xc) < (uint)uVar5));
  FUN_022c47d4(1,DAT_022c6380,0,*(int *)(param_1 + 0x10),param_4);
  puVar1 = DAT_022c6388;
  uVar2 = DAT_022c6384;
  if ((-1 < iVar3) && (uVar2 = 0, iVar3 < (int)(uint)(uVar4 < 0x10000))) {
    uVar2 = ~uVar4 & 0xffff;
  }
  *DAT_022c6388 = (short)uVar2;
  puVar1[1] = 0xc1;
  FUN_022c486c(0x10);
  return;
}

