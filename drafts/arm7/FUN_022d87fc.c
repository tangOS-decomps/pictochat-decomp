// decomp: module=arm7 addr=0x022d87fc name=FUN_022d87fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x188 (Ghidra's cache says 0x17c - it excludes this function's trailing literal pool), arm
// triage: noise=7 statements=63
// verify:  python tools/match.py --c <file> --func FUN_022d87fc --addr 0x022d87fc --size 0x188 --module arm7 --version 2.0/sp1


void FUN_022d87fc(void)

{
  int iVar1;
  int iVar2;
  uint extraout_r1;
  uint uVar3;
  undefined4 in_r3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  
  iVar1 = DAT_022d897c;
  iVar2 = *DAT_022d8978;
  uVar5 = 0;
  local_28 = 0;
  local_20 = in_r3;
  do {
    FUN_022e2e4c(uVar5 * 2 + 0x44,2,&local_28);
    iVar4 = uVar5 * 2;
    uVar5 = uVar5 + 1;
    *(short *)(&DAT_04808000 + *(ushort *)(iVar1 + iVar4)) = (short)local_28;
  } while (uVar5 < 0x10);
  iVar4 = 0xce;
  local_24 = *(ushort *)(iVar2 + 0x5fa) & 0x7f | (uint)(*(ushort *)(iVar2 + 0x5fa) >> 7) << 8;
  *DAT_022d8980 = (short)local_24;
  uVar5 = (uint)*(ushort *)(iVar2 + 0x5fc);
  iVar1 = (int)((*(ushort *)(iVar2 + 0x5fa) & 0x7f) + 7) >> 3;
  if (*(ushort *)(iVar2 + 0x5f8) == 3) {
    FUN_022e2e4c(uVar5 + 0xce,1,iVar2 + 0x600);
    for (uVar6 = 0; uVar6 < uVar5; uVar6 = uVar6 + 1) {
      local_24 = 0;
      FUN_022e2e4c(iVar4,1,&local_24);
      local_24 = local_24 | uVar6 * 0x100 + 0x50000;
      FUN_022d865c();
      iVar4 = iVar4 + 1;
    }
  }
  else {
    local_24 = 0;
    while (uVar5 != 0) {
      FUN_022e2e4c(iVar4,iVar1,&local_24);
      FUN_022d865c(local_24);
      uVar6 = (uint)*(ushort *)(iVar2 + 0x5f8);
      uVar5 = uVar5 - 1;
      bVar7 = uVar6 == 2;
      uVar3 = extraout_r1;
      if (bVar7) {
        uVar3 = local_24;
      }
      iVar4 = iVar4 + iVar1;
      if (bVar7) {
        uVar6 = uVar3 >> 0x12;
      }
      if (bVar7 && uVar6 == 9) {
        *(uint *)(iVar2 + 0x604) = uVar3 & 0xffff83ff;
      }
    }
  }
  return;
}

