// decomp: module=arm7 addr=0x022d5d10 name=FUN_022d5d10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x90 (Ghidra's cache says 0x8c - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=23
// verify:  python tools/match.py --c <file> --func FUN_022d5d10 --addr 0x022d5d10 --size 0x90 --module arm7 --version 2.0/sp1


void FUN_022d5d10(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 auStack_288 [128];
  undefined1 auStack_208 [512];
  
  iVar2 = *(int *)(DAT_022d5d9c + 0x550);
  *(short *)(iVar2 + 0xf6) = (short)*(undefined4 *)(param_1 + 4);
  FUN_022ce324(auStack_288,iVar2 + 0xe8);
  iVar2 = FUN_022d07f4(auStack_208,*(short *)(iVar2 + 0xec) + 0x10,auStack_288);
  puVar1 = (undefined2 *)func_0x037d14bc();
  *puVar1 = 0x21;
  if (*(short *)(iVar2 + 4) == 0) {
    puVar1[1] = 0;
  }
  else {
    puVar1[1] = 1;
    puVar1[2] = 0x245;
    puVar1[3] = *(undefined2 *)(iVar2 + 4);
  }
  func_0x037d1464();
  return;
}

