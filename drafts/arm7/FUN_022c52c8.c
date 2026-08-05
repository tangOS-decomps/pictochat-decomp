// decomp: module=arm7 addr=0x022c52c8 name=FUN_022c52c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88, arm
// triage: noise=7 statements=33
// verify:  python tools/match.py --c <file> --func FUN_022c52c8 --addr 0x022c52c8 --size 0x88 --module arm7 --version 2.0/sp1


void FUN_022c52c8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_022c6d40();
  if (*param_1 != 0) {
    while( true ) {
      iVar3 = *param_1;
      if (iVar3 == 0) break;
      if (iVar3 != 0) {
        iVar2 = *(int *)(iVar3 + 100);
        *param_1 = iVar2;
        if (iVar2 == 0) {
          param_1[1] = 0;
          *(undefined4 *)(iVar3 + 0x5c) = 0;
        }
        else {
          *(undefined4 *)(iVar2 + 0x60) = 0;
        }
      }
      *(undefined4 *)(iVar3 + 0x48) = 1;
      *(undefined4 *)(iVar3 + 0x5c) = 0;
      *(undefined4 *)(iVar3 + 100) = 0;
      *(undefined4 *)(iVar3 + 0x60) = 0;
    }
    param_1[1] = 0;
    *param_1 = 0;
    FUN_022c4e28();
  }
  FUN_022c6d54(uVar1);
  return;
}

