// decomp: module=unk_autoload_0 addr=0x02323040 name=FUN_02323040
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02323040 --addr 0x02323040 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void FUN_02323040(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = DAT_02323088 + param_1 * 0x30;
  sVar1 = *(short *)(iVar3 + 0x2a);
  if ((*(byte *)(iVar3 + 8) & 2) == 0) {
    *(short *)(iVar3 + 0x28) = sVar1;
    return;
  }
  if ((int)((uint)*(byte *)(iVar3 + 0x2c) * -0x80000000) < 0) {
    sVar2 = FUN_02335e0c(sVar1,3,0,param_4,param_4);
    *(short *)(iVar3 + 0x28) = sVar1 + sVar2;
    return;
  }
  sVar2 = FUN_02335e0c(sVar1,3,0,param_4,param_4);
  *(short *)(iVar3 + 0x28) = sVar1 - sVar2;
  return;
}

