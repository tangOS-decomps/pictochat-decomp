// decomp: module=unk_autoload_0 addr=0x023394e4 name=FUN_023394e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1dc (Ghidra's cache says 0x1b8 - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=103
// verify:  python tools/match.py --c <file> --func FUN_023394e4 --addr 0x023394e4 --size 0x1dc --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_023394e4(ushort param_1,ushort param_2,ushort param_3)

{
  undefined2 uVar1;
  bool bVar2;
  ushort uVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_1c;
  int local_18;
  
  bVar2 = false;
  FUN_02339838(*(undefined4 **)(DAT_0233969c + 0x10));
  uVar1 = *DAT_023396a0;
  *DAT_023396a0 = 0;
  uVar5 = FUN_02332080();
  uVar6 = FUN_023307f8(DAT_023396a4);
  uVar3 = FUN_02331c5c();
  if (uVar3 == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = 8;
  }
  FUN_023307b4(uVar11 | 0x40000);
  FUN_02332094(uVar5);
  *DAT_023396a0 = 1;
  if (((param_1 & 8) != 0) && (uVar3 = FUN_02332120(), ((uint)uVar3 + DAT_023396a8 & 0xffff) < 2)) {
    param_1 = param_1 & 0xfff7;
  }
  if (((param_1 & 0x10) != 0) && (iVar7 = FUN_023327dc(), iVar7 == 0)) {
    param_1 = param_1 & 0xffef;
  }
  uVar11 = _DAT_04000000;
  uVar8 = *DAT_023396ac;
  iVar7 = FUN_02339794();
  do {
    iVar9 = FUN_02339410(&local_18,&local_1c);
  } while (iVar9 != 0);
  do {
    iVar9 = FUN_02339374(2,0);
  } while (iVar9 != 0);
  do {
  } while (*DAT_023396b0 == *DAT_023396b0);
  iVar9 = *DAT_023396b0;
  _DAT_04000000 = DAT_023396b4 & _DAT_04000000;
  *DAT_023396ac = DAT_023396b8 & *DAT_023396ac;
  do {
  } while (iVar9 == *DAT_023396b0);
  do {
  } while (*DAT_023396b0 == *DAT_023396b0);
  FUN_0233946c();
  uVar3 = 0;
  *(undefined4 *)(DAT_0233969c + 0xc) = 0;
  if (local_1c != 0) {
    uVar3 = 0x80;
  }
  if (local_18 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x40;
  }
  FUN_023391f4(uVar4 | param_1 | uVar3,param_3 | param_2);
  iVar9 = DAT_0233969c;
  iVar10 = *(int *)(DAT_0233969c + 0xc);
  while (iVar10 == 0) {
    FUN_0233229c();
    iVar10 = *(int *)(iVar9 + 0xc);
  }
  if (((param_1 & 8) != 0) && ((*DAT_023396bc & 0x100000) != 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    if (iVar7 == 1) {
      do {
        iVar7 = FUN_023396c0(1,1,1,1);
      } while (iVar7 != 1);
    }
    else {
      do {
        iVar7 = FUN_023392f8(1);
      } while (iVar7 != 0);
    }
    _DAT_04000000 = uVar11;
    *DAT_023396ac = uVar8;
  }
  FUN_023320fc(0x360000);
  FUN_02332080();
  FUN_023307b4(uVar6);
  FUN_02332094(uVar5);
  *DAT_023396a0 = uVar1;
  if (bVar2) {
    FUN_023393e0();
  }
  FUN_02339838(*(undefined4 **)(DAT_0233969c + 0x18));
  return;
}

