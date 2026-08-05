// decomp: module=unk_autoload_0 addr=0x02325804 name=FUN_02325804
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2e, thumb
// triage: noise=2 statements=14
// verify:  python tools/match.py --c <file> --func FUN_02325804 --addr 0x02325804 --size 0x2e --module unk_autoload_0 --version 2.0/sp1


void FUN_02325804(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_02325cb4();
  iVar2 = FUN_02323834();
  if ((iVar2 == 1) && (iVar1 != 0)) {
    FUN_02325834(param_1,0);
    uVar3 = FUN_02323f00(iVar1);
    FUN_0232598c(param_1,uVar3);
  }
  return;
}

