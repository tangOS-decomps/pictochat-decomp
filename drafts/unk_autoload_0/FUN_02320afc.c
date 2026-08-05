// decomp: module=unk_autoload_0 addr=0x02320afc name=FUN_02320afc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x84 (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), thumb
// triage: noise=8 statements=26
// verify:  python tools/match.py --c <file> --func FUN_02320afc --addr 0x02320afc --size 0x84 --module unk_autoload_0 --version 2.0/sp1


void FUN_02320afc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = DAT_02320b74;
  *(undefined4 *)(param_1 + *(int *)(param_1 + DAT_02320b74) * 8 + DAT_02320b74 + -0x20) = param_2;
  *(undefined4 *)(param_1 + *(int *)(param_1 + iVar1) * 8 + iVar1 + -0x1c) =
       *(undefined4 *)(param_1 + iVar1 + 4);
  if (param_1 == DAT_02320b78) {
    uVar2 = FUN_0232dfe8(param_2);
    uVar3 = FUN_0232dff0(param_2);
    FUN_02336940(uVar2,*(undefined4 *)(param_1 + DAT_02320b7c),uVar3);
  }
  else {
    uVar2 = FUN_0232dfe8(param_2);
    uVar3 = FUN_0232dff0(param_2);
    FUN_0233697c(uVar2,*(undefined4 *)(param_1 + DAT_02320b7c),uVar3);
  }
  iVar4 = FUN_0232dff0(param_2);
  iVar1 = DAT_02320b7c;
  *(int *)(param_1 + DAT_02320b7c) = *(int *)(param_1 + DAT_02320b7c) + iVar4;
  *(int *)(param_1 + iVar1 + -4) = *(int *)(param_1 + iVar1 + -4) + 1;
  return;
}

