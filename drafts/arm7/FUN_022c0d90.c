// decomp: module=arm7 addr=0x022c0d90 name=FUN_022c0d90
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xb8 (Ghidra's cache says 0xac - it excludes this function's trailing literal pool), arm
// triage: noise=12 statements=36
// verify:  python tools/match.py --c <file> --func FUN_022c0d90 --addr 0x022c0d90 --size 0xb8 --module arm7 --version 2.0/sp1


void FUN_022c0d90(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 in_r3;
  int iVar6;
  undefined4 uStack_20;
  
  uVar2 = DAT_022c0e40;
  piVar1 = DAT_022c0e3c;
  iVar6 = *DAT_022c0e3c;
  *(undefined2 *)(iVar6 + 0x10) = 0;
  uVar3 = DAT_022c0e44;
  *(undefined2 *)(iVar6 + 0x14) = 0;
  uStack_20 = in_r3;
  do {
    while( true ) {
      iVar5 = FUN_022c573c(*(undefined4 *)(*piVar1 + 0x308),&uStack_20,0);
      if (iVar5 != 0) {
        FUN_022c0fb4(&uStack_20);
      }
      FUN_022c48a4(uVar2);
      *(ushort *)(iVar6 + 0x12) = *(ushort *)(iVar6 + 0x10);
      if (*(ushort *)(iVar6 + (uint)*(ushort *)(iVar6 + 0x10) * 2) != uVar3) break;
      *(short *)(iVar6 + 0x10) = *(short *)(iVar6 + 0x10) + 1;
      FUN_022c486c();
    }
    FUN_022c486c();
    uVar4 = FUN_022c0f00(*(undefined2 *)(iVar6 + 0x12));
    *(undefined2 *)(iVar6 + 0x14) = uVar4;
    (**(code **)(iVar6 + (uint)*(ushort *)(iVar6 + 0x14) * 8 + 0xc0))();
    *(short *)(iVar6 + 0x14) = (short)uVar3;
  } while( true );
}

