// decomp: module=unk_autoload_0 addr=0x02325b00 name=FUN_02325b00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74, thumb
// triage: noise=4 statements=29
// verify:  python tools/match.py --c <file> --func FUN_02325b00 --addr 0x02325b00 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325b00(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = FUN_02321c60();
  iVar3 = FUN_0232de60(piVar2,param_2);
  param_3 = param_3 - iVar3 / 2;
  iVar3 = param_3 + -1;
  iVar4 = param_4 + -8;
  if ((((iVar3 < 0x18) || (0xed < iVar3)) || (iVar4 < 0x12)) || (0x53 < iVar4)) {
    bVar1 = false;
  }
  else if ((iVar4 < 0x22) && (iVar4 = FUN_02327990(), iVar3 < iVar4 + 0x18)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_023257b4(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x24),
                 *(undefined4 *)(param_1 + 0x44));
    FUN_02325910(param_1,param_3 + -0x19,param_4 + -0x18);
    FUN_0232598c(param_1,param_2);
    FUN_02320978(0x19);
  }
  return;
}

