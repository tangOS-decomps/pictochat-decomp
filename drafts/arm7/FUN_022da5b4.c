// decomp: module=arm7 addr=0x022da5b4 name=FUN_022da5b4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe4 (Ghidra's cache says 0xdc - it excludes this function's trailing literal pool), arm
// triage: noise=6 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022da5b4 --addr 0x022da5b4 --size 0xe4 --module arm7 --version 2.0/sp1


void FUN_022da5b4(uint param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *DAT_022da690;
  iVar2 = *(int *)(iVar3 + 0x31c);
  iVar4 = iVar2 + param_1 * 0x1c;
  if (*(short *)(iVar2 + param_1 * 0x1c) == 0) {
    *(short *)(iVar3 + 0x52c) = *(short *)(iVar3 + 0x52c) + 1;
  }
  func_0x037cb774(0,iVar4,0x1a,iVar2,param_4);
  *(ushort *)(*DAT_022da690 + 0x534) =
       *(ushort *)(*DAT_022da690 + 0x534) & ~(ushort)(1 << (param_1 & 0xff));
  FUN_022d9d68(param_1 & 0xffff,0);
  *(ushort *)(*DAT_022da690 + 0x530) =
       *(ushort *)(*DAT_022da690 + 0x530) | (ushort)(1 << (param_1 & 0xff));
  FUN_022d811c((ushort *)(iVar4 + 4),param_2);
  piVar1 = DAT_022da690;
  *(short *)(iVar4 + 0x14) = (short)DAT_022da694;
  *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(*piVar1 + 0x3a6);
  *(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)(iVar4 + 0x1a);
  FUN_022d9c60(param_1 & 0xffff,0x20);
  return;
}

