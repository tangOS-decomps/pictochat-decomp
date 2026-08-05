// decomp: module=unk_autoload_0 addr=0x0232d530 name=FUN_0232d530
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xa8 (Ghidra's cache says 0x92 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=34
// verify:  python tools/match.py --c <file> --func FUN_0232d530 --addr 0x0232d530 --size 0xa8 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232d530(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = DAT_0232d5c8;
  uVar6 = 0;
  FUN_023382ac(4,DAT_0232d5c4);
  piVar3 = DAT_0232d5cc;
  do {
    iVar5 = FUN_0232d6f8(1,*piVar3,0x80,iVar2,param_1,uVar6,param_4);
    piVar4 = DAT_0232d5cc;
  } while (iVar5 == 0);
  do {
    iVar5 = FUN_0232d6f8(1,*piVar4 + 0x100,0x80,iVar2 + 0x80,param_1,uVar6,param_4);
  } while (iVar5 == 0);
  FUN_023314cc(iVar2,0x100);
  iVar5 = FUN_0232d64c(iVar2);
  if (iVar5 == 0) {
    uVar1 = *DAT_0232d5d4;
    *(ushort *)(DAT_0232d5d0 + 2) = *(short *)(iVar2 + (uint)uVar1 * 0x80 + 0x70) + 1U & 0x7f;
    if (param_1 != 0) {
      FUN_02332d2e(iVar2 + (uint)uVar1 * 0x80,param_1,0x38);
    }
  }
  else {
    uVar6 = 1;
    *(undefined2 *)(DAT_0232d5d0 + 2) = 1;
  }
  return uVar6;
}

