// decomp: module=unk_autoload_0 addr=0x02330c20 name=FUN_02330c20
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02330c20 --addr 0x02330c20 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02330c20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(DAT_02330c48 + 0x24);
  iVar3 = 0;
  while ((iVar2 = iVar1, iVar2 != 0 && (iVar2 != param_1))) {
    iVar3 = iVar2;
    iVar1 = *(int *)(iVar2 + 0x68);
  }
  if (iVar3 == 0) {
    *(undefined4 *)(DAT_02330c48 + 0x24) = *(undefined4 *)(param_1 + 0x68);
    return;
  }
  *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(param_1 + 0x68);
  return;
}

