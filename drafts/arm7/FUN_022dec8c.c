// decomp: module=arm7 addr=0x022dec8c name=FUN_022dec8c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x64 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=16
// verify:  python tools/match.py --c <file> --func FUN_022dec8c --addr 0x022dec8c --size 0x64 --module arm7 --version 2.0/sp1


void FUN_022dec8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *DAT_022decec + 0x42c + param_1 * 0x14;
  if (*(short *)(*DAT_022decec + 0x42c + param_1 * 0x14) != 0) {
    sVar1 = **(short **)(iVar2 + 8);
    if (sVar1 == 0) {
      sVar1 = 2;
    }
    *(short *)(*(int *)(iVar2 + 0xc) + 8) = sVar1;
    (**(code **)(iVar2 + 0x10))
              (*(undefined4 *)(iVar2 + 0xc),0,*(code **)(iVar2 + 0x10),param_4,param_4);
  }
  return;
}

