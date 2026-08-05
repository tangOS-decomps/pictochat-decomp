// decomp: module=arm7 addr=0x022cfcfc name=FUN_022cfcfc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa4 (Ghidra's cache says 0x98 - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=28
// verify:  python tools/match.py --c <file> --func FUN_022cfcfc --addr 0x022cfcfc --size 0xa4 --module arm7 --version 2.0/sp1


void FUN_022cfcfc(void)

{
  int iVar1;
  int iVar2;
  ushort *in_r3;
  int iVar3;
  uint uVar4;
  ushort *local_28;
  
  iVar2 = DAT_022cfd9c;
  iVar1 = DAT_022cfd98;
  iVar3 = *(int *)(DAT_022cfd94 + 0x550);
  local_28 = in_r3;
  while (func_0x037c9f1c(iVar1 + 0x88,&local_28,1), local_28 != (ushort *)0x0) {
    uVar4 = (uint)*local_28;
    if ((*local_28 & 0x8000) != 0) {
      uVar4 = uVar4 & 0xffff7fff;
    }
    if (uVar4 < 0x2e) {
      *(undefined4 *)(iVar3 + 4) = 1;
      *(ushort *)(iVar3 + 2) = (ushort)uVar4;
      (**(code **)(iVar2 + uVar4 * 4))(local_28);
      *(undefined4 *)(iVar3 + 4) = 0;
    }
    *local_28 = (ushort)uVar4 | 0x8000;
  }
  func_0x037c9920();
  return;
}

