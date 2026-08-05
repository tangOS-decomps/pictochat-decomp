// decomp: module=unk_autoload_0 addr=0x02327bfc name=FUN_02327bfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58, thumb
// triage: noise=5 statements=24
// verify:  python tools/match.py --c <file> --func FUN_02327bfc --addr 0x02327bfc --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_02327bfc(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_18;
  
  local_18 = param_4;
  iVar1 = FUN_02325b74(*(undefined4 *)(param_1 + 0x3c),&local_18,1);
  iVar2 = FUN_02329228();
  if ((iVar2 != 0) && (iVar1 != 0)) {
    iVar2 = local_18 * 0x800;
    uVar3 = FUN_02322870();
    uVar4 = FUN_02322820();
    FUN_0232679c(iVar1,iVar2,uVar3,uVar4);
    FUN_02327390();
    FUN_02329144(iVar1,iVar2);
    FUN_0232571c(param_1);
    FUN_02320978(3);
    return;
  }
  FUN_02320978(0xf);
  return;
}

