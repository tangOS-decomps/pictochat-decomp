// decomp: module=unk_autoload_0 addr=0x02325a54 name=FUN_02325a54
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa0, thumb
// triage: noise=1 statements=42
// verify:  python tools/match.py --c <file> --func FUN_02325a54 --addr 0x02325a54 --size 0xa0 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325a54(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (0 < (int)param_2) {
    switch(param_2) {
    case 7:
      iVar1 = FUN_02325cb4();
      if ((iVar1 != 0) && (iVar2 = FUN_02323de0(), iVar2 != iVar1)) {
        FUN_02325834(param_1,0);
        FUN_0232598c(param_1,iVar2);
        return;
      }
      break;
    case 8:
      FUN_02325834(param_1,1);
      return;
    case 9:
      iVar1 = FUN_02325cb4();
      if ((iVar1 != 0) && (iVar2 = FUN_02323e60(), iVar2 != iVar1)) {
        FUN_02325834(param_1,0);
        FUN_0232598c(param_1,iVar2);
        return;
      }
      break;
    case 10:
      FUN_02325960();
      return;
    case 0xb:
      iVar1 = FUN_02325cb4();
      if ((iVar1 != 0) && (iVar2 = FUN_02323eb0(), iVar2 != iVar1)) {
        FUN_02325834(param_1,0);
        FUN_0232598c(param_1,iVar2);
        return;
      }
      break;
    default:
      FUN_0232598c(param_1,param_2 & 0xffff);
    }
  }
  return;
}

