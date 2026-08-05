// decomp: module=arm7 addr=0x022d90cc name=FUN_022d90cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x80 (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), arm
// triage: noise=8 statements=17
// verify:  python tools/match.py --c <file> --func FUN_022d90cc --addr 0x022d90cc --size 0x80 --module arm7 --version 2.0/sp1


void FUN_022d90cc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_022d9144;
  if ((*(short *)(iVar2 + 0x3f4) != 0) &&
     (iVar1 = func_0x037c58fc(iVar2 + 0x188,0x12,param_3,param_4,param_4), iVar1 != 0)) {
    *(short *)(iVar1 + 0xc) = (short)DAT_022d9148;
    *(undefined2 *)(iVar1 + 0xe) = 1;
    func_0x037c9084(0x1000000);
    *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(iVar2 + 0x3f4);
    *(undefined2 *)(iVar2 + 0x3f4) = 0;
    func_0x037c904c();
    func_0x037c5de8(*DAT_022d9144 + 0x188,iVar1);
  }
  return;
}

