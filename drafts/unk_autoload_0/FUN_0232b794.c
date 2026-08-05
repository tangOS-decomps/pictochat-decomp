// decomp: module=unk_autoload_0 addr=0x0232b794 name=FUN_0232b794
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, thumb
// triage: noise=4 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232b794 --addr 0x0232b794 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232b794(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ushort uVar2;
  
  uVar1 = FUN_02332080();
  uVar2 = (short)param_1[3] - 1U & *(short *)((int)param_1 + 10) + 1U;
  if (uVar2 == *(ushort *)(param_1 + 2)) {
    FUN_02332094();
    return 0;
  }
  FUN_02337584(param_2,*param_1 + param_1[1] * (uint)*(ushort *)((int)param_1 + 10),param_3);
  FUN_023314e8(*param_1 + param_1[1] * (uint)*(ushort *)((int)param_1 + 10),param_3);
  *(ushort *)((int)param_1 + 10) = uVar2;
  FUN_02332094(uVar1);
  return 1;
}

