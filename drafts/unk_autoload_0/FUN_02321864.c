// decomp: module=unk_autoload_0 addr=0x02321864 name=FUN_02321864
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x5e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=29
// verify:  python tools/match.py --c <file> --func FUN_02321864 --addr 0x02321864 --size 0x68 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02321864(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int)(param_1 + -1 + ((uint)(param_1 + -1 >> 2) >> 0x1d)) >> 3) + 1;
  iVar1 = ((int)(param_2 + -1 + ((uint)(param_2 + -1 >> 2) >> 0x1d)) >> 3) + 1;
  if (iVar2 < 3) {
    if (iVar1 < 3) {
      return 0x40000000;
    }
    return 0x80000000;
  }
  if (iVar2 < 5) {
    if (iVar1 < 3) {
      return DAT_023218c4;
    }
    if (iVar1 < 5) {
      return 0x80000000;
    }
    return 0xc0000000;
  }
  if (iVar1 < 3) {
    return DAT_023218c4;
  }
  if (iVar1 < 5) {
    return DAT_023218c8;
  }
  return 0xc0000000;
}

