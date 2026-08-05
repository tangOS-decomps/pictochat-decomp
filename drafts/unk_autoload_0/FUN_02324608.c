// decomp: module=unk_autoload_0 addr=0x02324608 name=FUN_02324608
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1ac (Ghidra's cache says 0x162 - it excludes this function's trailing literal pool), thumb
// triage: noise=33 statements=84
// verify:  python tools/match.py --c <file> --func FUN_02324608 --addr 0x02324608 --size 0x1ac --module unk_autoload_0 --version 2.0/sp1


void FUN_02324608(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 local_58 [4];
  undefined4 local_48 [4];
  undefined4 local_38 [4];
  undefined4 local_28 [4];
  undefined4 uStack_18;
  
  *(undefined4 *)(PTR_DAT_0232476c + 8) = 0;
  uStack_18 = param_4;
  FUN_02336880(PTR_DAT_02324770,0,(int)PTR_DAT_02324774 - (int)PTR_DAT_02324770);
  FUN_02336880(PTR_DAT_0232477c + (*DAT_02324778 & 0xf) * 0x20,0x1e0,0x20);
  FUN_02321df4();
  if (param_1 == 0) {
    FUN_023221d4(0x1a,0x23,6);
  }
  else {
    FUN_023221d4(0x1f,0x22,6);
  }
  FUN_023224a4();
  FUN_02320c7c();
  FUN_02320ac8();
  uVar2 = FUN_02320c7c();
  FUN_02320afc(uVar2,PTR_DAT_02324780);
  pvVar3 = FUN_023215e4();
  iVar4 = FUN_02320c7c();
  FUN_02321600(pvVar3,*(undefined4 *)(iVar4 + DAT_02324784));
  FUN_023215e4();
  FUN_02322244();
  FUN_023215e4();
  FUN_02321e24();
  pvVar3 = FUN_023215e4();
  FUN_02321634(pvVar3,PTR_DAT_02324788,PTR_s_JNLL__0232478c,0xc);
  local_28[0] = *(undefined4 *)PTR_DAT_02324790;
  local_28[1] = *(undefined4 *)(PTR_DAT_02324790 + 4);
  local_28[2] = *(undefined4 *)(PTR_DAT_02324790 + 8);
  local_28[3] = *(undefined4 *)(PTR_DAT_02324790 + 0xc);
  local_38[0] = *(undefined4 *)PTR_DAT_02324794;
  local_38[1] = *(undefined4 *)(PTR_DAT_02324794 + 4);
  local_38[2] = *(undefined4 *)(PTR_DAT_02324794 + 8);
  local_38[3] = *(undefined4 *)(PTR_DAT_02324794 + 0xc);
  local_48[0] = *(undefined4 *)PTR_DAT_02324798;
  local_48[1] = *(undefined4 *)(PTR_DAT_02324798 + 4);
  local_48[2] = *(undefined4 *)(PTR_DAT_02324798 + 8);
  local_48[3] = *(undefined4 *)(PTR_DAT_02324798 + 0xc);
  local_58[0] = *(undefined4 *)PTR_DAT_0232479c;
  local_58[1] = *(undefined4 *)(PTR_DAT_0232479c + 4);
  local_58[2] = *(undefined4 *)(PTR_DAT_0232479c + 8);
  local_58[3] = *(undefined4 *)(PTR_DAT_0232479c + 0xc);
  FUN_023374f0(PTR_DAT_023247a0,0,0x230,PTR_DAT_0232479c + 0x10);
  puVar1 = PTR_DAT_023247a0;
  iVar4 = 0;
  do {
    iVar6 = iVar4 * 0x8c;
    pvVar3 = FUN_023215e4();
    FUN_02321634(pvVar3,puVar1 + iVar6,PTR_s_JNLL__0232478c,local_28[iVar4]);
    pvVar3 = FUN_023215e4();
    FUN_02321664(pvVar3,puVar1 + iVar6 + 0x40,PTR_s_JNLL__0232478c,local_38[iVar4]);
    FUN_023216e0(puVar1 + iVar6 + 0x40,PTR_u_0_16_023247a4);
    *(undefined4 *)(puVar1 + iVar6 + 0x80) = local_48[iVar4];
    *(undefined4 *)(puVar1 + iVar6 + 0x84) = local_58[iVar4];
    iVar4 = iVar4 + 1;
    *(undefined4 *)(puVar1 + iVar6 + 0x88) = 0;
  } while (iVar4 < 4);
  FUN_023374f0(PTR_DAT_023247a8,0,0x30);
  FUN_023374f0(PTR_DAT_023247ac,0,8);
  piVar5 = FUN_023260bc();
  puVar1 = PTR_DAT_0232476c;
  iVar4 = *piVar5;
  *(int *)(PTR_DAT_0232476c + 0x20) = iVar4;
  iVar4 = iVar4 << 0x11;
  *(int *)(puVar1 + 0x30) = iVar4;
  *(int *)(puVar1 + 0x34) = iVar4;
  FUN_0232131c((int *)PTR_DAT_023247b0);
  puVar1 = PTR_DAT_0232476c;
  *(undefined4 *)(PTR_DAT_0232476c + 0x2c) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  return;
}

