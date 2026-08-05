// decomp: module=arm7 addr=0x022d9c60 name=FUN_022d9c60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xe8 (Ghidra's cache says 0xe4 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=26
// verify:  python tools/match.py --c <file> --func FUN_022d9c60 --addr 0x022d9c60 --size 0xe8 --module arm7 --version 2.0/sp1


void FUN_022d9c60(uint param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = func_0x037c9084(0x1000000);
  piVar1 = DAT_022d9d44;
  if (param_2 < 0x40) {
    *(ushort *)(*DAT_022d9d44 + 0x530) =
         *(ushort *)(*DAT_022d9d44 + 0x530) | (ushort)(1 << (param_1 & 0xff));
    *(ushort *)(*piVar1 + 0x532) = *(ushort *)(*piVar1 + 0x532) | (ushort)(1 << (param_1 & 0xff));
    if ((*(short *)(*piVar1 + 0x350) == 1) && (iVar3 = FUN_022da0e8(param_1), iVar3 != 0)) {
      FUN_022d9f7c(param_1);
    }
  }
  else {
    *(ushort *)(*DAT_022d9d44 + 0x532) =
         *(ushort *)(*DAT_022d9d44 + 0x532) & ~(ushort)(1 << (param_1 & 0xff));
    if (((int)(uint)*(ushort *)(*piVar1 + 0x52e) >> (param_1 & 0xff) & 1U) != 0) {
      FUN_022d9dc4(param_1);
    }
  }
  *(short *)(*(int *)(*DAT_022d9d44 + 0x31c) + param_1 * 0x1c) = (short)param_2;
  func_0x037c904c(uVar2);
  return;
}

