// decomp: module=unk_autoload_0 addr=0x023379a0 name=FUN_023379a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x88 (Ghidra's cache says 0x6e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=34
// verify:  python tools/match.py --c <file> --func FUN_023379a0 --addr 0x023379a0 --size 0x88 --module unk_autoload_0 --version 2.0/sp1


void FUN_023379a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_02337d84();
  iVar2 = DAT_02337a10;
  *DAT_02337a14 = DAT_02337a10;
  iVar3 = 0;
  while (iVar3 < 0xff) {
    *(int *)(iVar2 + iVar3 * 0x18) = iVar2 + (iVar3 + 1) * 0x18;
    iVar3 = iVar3 + 1;
  }
  *(undefined4 *)(DAT_02337a18 + 0x48) = 0;
  piVar1 = DAT_02337a14;
  DAT_02337a14[4] = DAT_02337a1c;
  piVar1[2] = 0;
  piVar1[3] = 0;
  piVar1[7] = 0;
  piVar1[5] = 0;
  piVar1[6] = 0;
  piVar1[8] = 1;
  piVar1[1] = 0;
  *DAT_02337a24 = DAT_02337a20;
  FUN_02337f04();
  iVar2 = FUN_02337ad0(1);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 4) = 0x1d;
    *(undefined4 *)(iVar2 + 8) = *DAT_02337a24;
    FUN_02337b2c();
    FUN_02337b54(1);
  }
  return;
}

