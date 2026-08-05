// decomp: module=unk_autoload_0 addr=0x023272c8 name=FUN_023272c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xc8 (Ghidra's cache says 0xbc - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=41  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023272c8 --addr 0x023272c8 --size 0xc8 --module unk_autoload_0 --version 2.0/sp1


void FUN_023272c8(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  int a;
  
  iVar3 = *(int *)(DAT_02327384 + 0xc);
  iVar4 = *(int *)(DAT_02327384 + 0x10);
  uVar5 = *(uint *)(DAT_02327384 + 0x14) & 7;
  a = (int)*(uint *)(DAT_02327384 + 0x14) >> 3;
  iVar6 = FUN_02326780(a);
  iVar9 = 0;
  do {
    if (iVar6 < 0) {
      pvVar7 = FUN_023366e8();
      FUN_0233746c(0,(void *)((int)pvVar7 + (0x18 - iVar9) * 0x400),0x400);
      iVar8 = FUN_023364f0();
      FUN_0233746c(0,iVar8 + (0x18 - iVar9) * 0x40,0x40);
    }
    else {
      FUN_023314e8(iVar3 + a * 0x400,0x400);
      FUN_02336c1c(iVar3 + a * 0x400,(0x18 - iVar9) * 0x400,0x400);
      FUN_023314e8(iVar4 + a * 0x40,0x40);
      FUN_02336ac8(iVar4 + a * 0x40,(0x18 - iVar9) * 0x40,0x40);
    }
    a = FUN_02326774(a);
    puVar2 = DAT_0232738c;
    uVar1 = DAT_02327388;
    iVar9 = iVar9 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar9 < 0x19);
  *DAT_0232738c = (uVar5 + 4) * 0x10000 & DAT_02327388;
  puVar2[1] = uVar5 << 0x10 & uVar1;
  return;
}

