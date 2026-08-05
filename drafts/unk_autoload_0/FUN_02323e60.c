// decomp: module=unk_autoload_0 addr=0x02323e60 name=FUN_02323e60
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=20
// verify:  python tools/match.py --c <file> --func FUN_02323e60 --addr 0x02323e60 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


int FUN_02323e60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  if (param_1 != 0x3000) {
    iVar1 = FUN_023346a8(*(undefined4 *)(DAT_02323ea8 + 0x14),param_1,param_3,param_4,param_4);
    if (iVar1 == 0) {
      iVar1 = FUN_023243a0(DAT_02323eac,param_1);
    }
    else {
      iVar2 = FUN_02323de0(param_1);
      iVar1 = FUN_023243a0(DAT_02323eac,iVar2);
      if (iVar1 == iVar2) {
        return param_1;
      }
    }
  }
  return iVar1;
}

