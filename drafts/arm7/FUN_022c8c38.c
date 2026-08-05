// decomp: module=arm7 addr=0x022c8c38 name=FUN_022c8c38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xae, thumb
// triage: noise=13 statements=44
// verify:  python tools/match.py --c <file> --func FUN_022c8c38 --addr 0x022c8c38 --size 0xae --module arm7 --version 2.0/sp1


uint FUN_022c8c38(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  short *psVar5;
  int iVar6;
  uint unaff_r4;
  int iVar7;
  
  switch(param_3) {
  case 0:
    unaff_r4 = FUN_022c88bc();
    break;
  case 1:
    uVar3 = FUN_022c88bc();
    iVar6 = FUN_022c88bc(param_1);
    unaff_r4 = (iVar6 << 8 | uVar3) & 0xffff;
    break;
  case 2:
    unaff_r4 = 0;
    do {
      uVar3 = FUN_022c88bc(param_1);
      unaff_r4 = unaff_r4 * 0x80 | uVar3 & 0x7f;
    } while ((uVar3 & 0x80) != 0);
    break;
  case 3:
    uVar1 = FUN_022c88bc();
    sVar2 = FUN_022c88bc(param_1);
    iVar7 = (int)(short)(sVar2 << 8 | uVar1);
    uVar1 = FUN_022c88bc(param_1);
    sVar2 = FUN_022c88bc(param_1);
    iVar6 = FUN_022c7af4();
    unaff_r4 = (iVar6 * (((short)(sVar2 << 8 | uVar1) - iVar7) + 1) >> 0x10) + iVar7;
    break;
  case 4:
    uVar4 = FUN_022c88bc();
    psVar5 = (short *)FUN_022c9764(param_2,uVar4);
    if (psVar5 != (short *)0x0) {
      unaff_r4 = (uint)*psVar5;
    }
  }
  return unaff_r4;
}

