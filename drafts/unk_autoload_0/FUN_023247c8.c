// decomp: module=unk_autoload_0 addr=0x023247c8 name=FUN_023247c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x190 (Ghidra's cache says 0x17a - it excludes this function's trailing literal pool), thumb
// triage: noise=11 statements=67
// verify:  python tools/match.py --c <file> --func FUN_023247c8 --addr 0x023247c8 --size 0x190 --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_023247c8(void)

{
  int iVar1;
  uint *puVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_r3;
  
  if (*(int *)(DAT_02324944 + 0x14) < 0x10) {
    *(int *)(DAT_02324944 + 0x14) = *(int *)(DAT_02324944 + 0x14) + 1;
  }
  iVar1 = DAT_02324944;
  iVar5 = ((*(int *)(DAT_02324944 + 0x14) + 6) * 3) / 2 + -0x18;
  if (0 < iVar5) {
    iVar5 = 0;
  }
  *(int *)(DAT_02324944 + 0x18) = iVar5;
  puVar2 = DAT_0232494c;
  iVar5 = *(int *)(iVar1 + 0xc);
  if (iVar5 < 0x10) {
    *(int *)(iVar1 + 0xc) = iVar5 + 1;
    puVar2 = DAT_0232494c;
    if (iVar5 + 1 < 8) {
      _DAT_04000000 = _DAT_04000000 & DAT_02324948 | 0xf00;
      uVar6 = DAT_02324948 & *DAT_0232494c;
      *DAT_0232494c = uVar6 | 0x900;
      uVar4 = FUN_02322894(*(undefined4 *)(iVar1 + 0xc),8,uVar6,puVar2,in_r3);
      uVar3 = FUN_02322884(*(int *)(DAT_02324944 + 0xc));
      FUN_02336428(DAT_02324950,0xe,1,uVar3,uVar4);
      uVar4 = FUN_02322894(*(undefined4 *)(DAT_02324944 + 0xc),8);
      uVar3 = FUN_02322884(*(int *)(DAT_02324944 + 0xc));
      FUN_02336428(DAT_02324954,8,1,uVar3,uVar4);
    }
    else {
      uVar6 = _DAT_04000000 & DAT_02324948;
      _DAT_04000000 = uVar6 | 0x1f00;
      iVar5 = iVar5 + -7;
      *DAT_0232494c = DAT_02324948 & *DAT_0232494c | 0x1900;
      uVar4 = FUN_02322894(iVar5,8,puVar2,uVar6,in_r3);
      uVar3 = FUN_02322884(iVar5);
      FUN_02336428(DAT_02324950,0x10,0xe,uVar3,uVar4);
      uVar4 = FUN_02322894(iVar5,8);
      uVar3 = FUN_02322884(iVar5);
      FUN_02336428(DAT_02324954,0x10,8,uVar3,uVar4);
    }
    if (*(int *)(DAT_02324944 + 0xc) == 0x10) {
      FUN_023209c4();
    }
  }
  else {
    _DAT_04000000 = _DAT_04000000 & DAT_02324948 | 0x1f00;
    uVar6 = DAT_02324948 & *DAT_0232494c;
    *DAT_0232494c = uVar6 | 0x1800;
    uVar4 = FUN_02322894(*(undefined4 *)(iVar1 + 0x14),0x10,uVar6,puVar2,in_r3);
    uVar3 = FUN_02322884(*(int *)(DAT_02324944 + 0x14));
    FUN_02336428(DAT_02324954,0x10,0xf,uVar3,uVar4);
  }
  FUN_0232234c();
  FUN_02322004();
  FUN_02325040();
  if ((*(int *)(DAT_02324944 + 0xc) == 0x10) && (*(int *)(DAT_02324944 + 0x14) == 0x10)) {
    return 1;
  }
  return 0;
}

