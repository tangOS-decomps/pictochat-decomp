// decomp: module=arm7 addr=0x022d3484 name=FUN_022d3484
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0xa4 - it excludes this function's trailing literal pool), arm
// triage: noise=11 statements=34
// verify:  python tools/match.py --c <file> --func FUN_022d3484 --addr 0x022d3484 --size 0xa8 --module arm7 --version 2.0/sp1


void FUN_022d3484(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_022d3528 + 0x550);
  *(short *)(iVar2 + 0x196) = (short)*(undefined4 *)(param_1 + 4);
  switch(*(undefined2 *)(iVar2 + 0x196)) {
  case 0:
    *(undefined4 *)(iVar2 + 0x198) = 0;
    goto LAB_022d34dc;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    *(undefined4 *)(iVar2 + 0x198) = 0;
    goto LAB_022d34dc;
  }
  *(undefined4 *)(iVar2 + 0x198) = 1;
LAB_022d34dc:
  if (*(int *)(iVar2 + 0x198) == 1) {
    func_0x037cb8b4(*(undefined4 *)(param_1 + 8),iVar2 + 0x19c);
  }
  else {
    func_0x037cb820(iVar2 + 0x19c,0,0x50,iVar2,param_4);
  }
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x14;
  puVar1[1] = 0;
  func_0x037d1464();
  return;
}

