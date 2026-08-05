// decomp: module=unk_autoload_0 addr=0x02339800 name=FUN_02339800
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x36, thumb
// triage: noise=0 statements=26  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_02339800 --addr 0x02339800 --size 0x36 --module unk_autoload_0 --version 2.0/sp1


void FUN_02339800(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    FUN_02332080();
    iVar3 = *param_1;
    iVar2 = *param_1;
    while (iVar1 = iVar3, iVar1 != 0) {
      if (iVar1 == param_2) {
        if (iVar1 == iVar2) {
          *param_1 = *(int *)(iVar1 + 0xc);
        }
        else {
          *(int *)(iVar2 + 0xc) = *(int *)(iVar1 + 0xc);
        }
        break;
      }
      iVar2 = iVar1;
      iVar3 = *(int *)(iVar1 + 0xc);
    }
    FUN_02332094();
  }
  return;
}

