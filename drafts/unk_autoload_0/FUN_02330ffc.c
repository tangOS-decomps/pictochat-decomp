// decomp: module=unk_autoload_0 addr=0x02330ffc name=FUN_02330ffc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x60 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=31
// verify:  python tools/match.py --c <file> --func FUN_02330ffc --addr 0x02330ffc --size 0x68 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02330ffc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(DAT_0233105c + 0x24);
  uVar1 = FUN_02332080();
  iVar4 = 0;
  while ((iVar3 = iVar2, iVar3 != 0 && (iVar3 != param_1))) {
    iVar4 = iVar3;
    iVar2 = *(int *)(iVar3 + 0x68);
  }
  if ((iVar3 != 0) && (iVar3 != DAT_02331060)) {
    if (*(int *)(iVar3 + 0x70) != param_2) {
      if (iVar4 == 0) {
        *(undefined4 *)(DAT_0233105c + 0x24) = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(param_1 + 0x68);
      }
      *(int *)(param_1 + 0x70) = param_2;
      FUN_02330be8(param_1);
      FUN_02330c4c();
    }
    FUN_02332094(uVar1);
    return 1;
  }
  FUN_02332094(uVar1);
  return 0;
}

