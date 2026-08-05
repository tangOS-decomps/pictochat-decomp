// decomp: module=unk_autoload_0 addr=0x02338020 name=FUN_02338020
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54, thumb
// triage: noise=4 statements=36
// verify:  python tools/match.py --c <file> --func FUN_02338020 --addr 0x02338020 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_02338020(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_02337980();
  iVar4 = 0;
  iVar3 = param_1 + 0x18;
  do {
    iVar2 = *(int *)(param_1 + 0x18);
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x18);
      if (iVar3 == *(int *)(iVar2 + 0x18)) {
        *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
        FUN_023314e8(iVar2,0x3c);
      }
      else {
        do {
          iVar2 = iVar1;
          if (iVar2 == 0) break;
          iVar1 = *(int *)(iVar2 + 4);
        } while (iVar3 != *(int *)(iVar2 + 4));
        *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 0x1c);
        FUN_023314e8(iVar2,8);
      }
    }
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 8;
    iVar3 = iVar3 + 8;
    if (3 < iVar4) {
      FUN_02337990();
      return;
    }
  } while( true );
}

