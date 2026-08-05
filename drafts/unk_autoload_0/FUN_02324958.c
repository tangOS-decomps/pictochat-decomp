// decomp: module=unk_autoload_0 addr=0x02324958 name=FUN_02324958
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x15c (Ghidra's cache says 0x13c - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=59
// verify:  python tools/match.py --c <file> --func FUN_02324958 --addr 0x02324958 --size 0x15c --module unk_autoload_0 --version 2.0/sp1


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_02324958(void)

{
  int iVar1;
  uint *puVar2;
  ushort *puVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = DAT_02324a94;
  if (*(int *)(DAT_02324a94 + 0xc) < 0x10) {
    *(int *)(DAT_02324a94 + 0xc) = *(int *)(DAT_02324a94 + 0xc) + 1;
    puVar2 = DAT_02324a98;
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 4;
    *puVar2 = *puVar2 & DAT_02324a9c | 0x1800;
    uVar4 = FUN_02322884(*(int *)(iVar1 + 0xc));
    uVar5 = FUN_02322894(*(undefined4 *)(DAT_02324a94 + 0xc),0x10);
    FUN_02336428(DAT_02324aa0,0,8,uVar5,uVar4);
    if (*(int *)(DAT_02324a94 + 0xc) == 0x10) {
      *(undefined4 *)(DAT_02324a94 + 0x14) = 0;
      puVar3 = DAT_02324aa4;
      *DAT_02324aa4 = (ushort)DAT_02324aa8 | *DAT_02324aa4 & 0x43;
      *(undefined4 *)(puVar3 + 4) = DAT_02324aac;
      *puVar3 = *puVar3 & 0xfffc | 3;
      FUN_023224b4();
    }
  }
  else {
    iVar6 = *(int *)(DAT_02324a94 + 0x14);
    iVar7 = iVar6 + 1;
    *(int *)(DAT_02324a94 + 0x14) = iVar7;
    if (iVar7 < 0x10) {
      *(int *)(iVar1 + 0x18) = iVar7 * -2;
      _DAT_04000000 = _DAT_04000000 & DAT_02324a9c | 0xd00;
      uVar4 = FUN_02322884(*(int *)(iVar1 + 0x14));
      uVar5 = FUN_02322894(*(undefined4 *)(DAT_02324a94 + 0x14),0x10);
      FUN_02336428(DAT_02324ab0,4,8,uVar5,uVar4);
    }
    else {
      _DAT_04000000 = _DAT_04000000 & DAT_02324a9c | 0x900;
      iVar6 = iVar6 + -0xf;
      *DAT_02324a98 = DAT_02324a9c & *DAT_02324a98 | 0xa00;
      uVar4 = FUN_02322884(iVar6);
      uVar5 = FUN_02322894(iVar6,0x10);
      FUN_02336428(DAT_02324ab0,8,1,uVar5,uVar4);
      uVar4 = FUN_02322884(iVar6);
      uVar5 = FUN_02322894(iVar6,0x10);
      FUN_02336428(DAT_02324aa0,8,2,uVar5,uVar4);
    }
  }
  FUN_0232234c();
  FUN_02322004();
  FUN_02325040();
  if (*(int *)(DAT_02324a94 + 0x14) == 0x20) {
    return 1;
  }
  return 0;
}

