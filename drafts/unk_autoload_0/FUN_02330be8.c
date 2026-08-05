// decomp: module=unk_autoload_0 addr=0x02330be8 name=FUN_02330be8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x34 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=22
// verify:  python tools/match.py --c <file> --func FUN_02330be8 --addr 0x02330be8 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330be8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_02330c1c;
  iVar2 = *(int *)(DAT_02330c1c + 0x24);
  iVar4 = 0;
  while ((iVar3 = iVar2, iVar3 != 0 && (*(uint *)(iVar3 + 0x70) < *(uint *)(param_1 + 0x70)))) {
    iVar4 = iVar3;
    iVar2 = *(int *)(iVar3 + 0x68);
  }
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x68) = *(int *)(DAT_02330c1c + 0x24);
    *(int *)(iVar1 + 0x24) = param_1;
    return;
  }
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar4 + 0x68);
  *(int *)(iVar4 + 0x68) = param_1;
  return;
}

