// decomp: module=arm7 addr=0x022c5864 name=FUN_022c5864
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84 (Ghidra's cache says 0x80 - it excludes this function's trailing literal pool), arm
// triage: noise=2 statements=24
// verify:  python tools/match.py --c <file> --func FUN_022c5864 --addr 0x022c5864 --size 0x84 --module arm7 --version 2.0/sp1


void FUN_022c5864(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_022c6d40();
  iVar2 = *(int *)(DAT_022c58e4 + 4);
  do {
    if (*(int *)(param_1 + 8) == 0) {
      *(int *)(param_1 + 8) = iVar2;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      FUN_022c5980(iVar2,param_1);
LAB_022c58d4:
      FUN_022c6d54(uVar1);
      return;
    }
    if (*(int *)(param_1 + 8) == iVar2) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      goto LAB_022c58d4;
    }
    *(int *)(iVar2 + 0x68) = param_1;
    FUN_022c5274(param_1);
    *(undefined4 *)(iVar2 + 0x68) = 0;
  } while( true );
}

