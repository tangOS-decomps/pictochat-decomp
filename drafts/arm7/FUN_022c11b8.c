// decomp: module=arm7 addr=0x022c11b8 name=FUN_022c11b8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), arm
// triage: noise=4 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022c11b8 --addr 0x022c11b8 --size 0x80 --module arm7 --version 2.0/sp1


int FUN_022c11b8(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_022c1230;
  if (*(ushort *)(param_2 + 10) == DAT_022c1234) {
    iVar1 = FUN_022c105c(param_1);
    if (iVar1 == 0) {
      if (*(int *)(iVar2 + 0x17c) == 0) {
        FUN_022c5d90(*(undefined4 *)(iVar2 + 0x180),*(undefined4 *)(iVar2 + 0x184),param_2);
      }
      else if (*(int *)(iVar2 + 0x17c) == 1) {
        (**(code **)(iVar2 + 0x184))(param_2);
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

