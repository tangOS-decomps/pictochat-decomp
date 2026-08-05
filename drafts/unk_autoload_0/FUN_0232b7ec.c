// decomp: module=unk_autoload_0 addr=0x0232b7ec name=FUN_0232b7ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x46, thumb
// triage: noise=4 statements=13
// verify:  python tools/match.py --c <file> --func FUN_0232b7ec --addr 0x0232b7ec --size 0x46 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232b7ec(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_02332080();
  if (*(short *)((int)param_1 + 10) == (short)param_1[2]) {
    FUN_02332094();
    return 0;
  }
  FUN_02337584(*param_1 + param_1[1] * (uint)*(ushort *)(param_1 + 2),param_2,param_3);
  *(ushort *)(param_1 + 2) = (short)param_1[3] - 1U & (short)param_1[2] + 1U;
  FUN_02332094(uVar1);
  return 1;
}

