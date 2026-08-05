// decomp: module=arm7 addr=0x022d7c88 name=FUN_022d7c88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=21
// verify:  python tools/match.py --c <file> --func FUN_022d7c88 --addr 0x022d7c88 --size 0x68 --module arm7 --version 2.0/sp1


undefined4 FUN_022d7c88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = *DAT_022d7ce8;
  *(short *)(iVar3 + 0x352) = (short)param_1;
  puVar2 = DAT_022d7cec;
  sVar1 = 0;
  if (param_1 != 0) {
    sVar1 = *(short *)(iVar3 + 0x32e);
  }
  if (param_1 != 0 && sVar1 != 1) {
    *DAT_022d7cec = *DAT_022d7cec | 0x40;
  }
  else {
    *DAT_022d7cec = *DAT_022d7cec & 0xffbf;
    FUN_022d71ec(*(undefined2 *)(iVar3 + 0x33c),0,puVar2,iVar3 + 0x31c,param_4);
  }
  return 0;
}

