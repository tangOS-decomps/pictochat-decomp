// decomp: module=unk_autoload_0 addr=0x02339250 name=FUN_02339250
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x3c - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02339250 --addr 0x02339250 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


undefined4
FUN_02339250(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_02339034();
  iVar1 = DAT_0233928c;
  if (iVar2 == 0) {
    return 1;
  }
  *(undefined4 *)(DAT_0233928c + 0x30) = param_4;
  *(undefined4 *)(iVar1 + 0x34) = param_5;
  *(undefined4 *)(iVar1 + 0x38) = param_3;
  FUN_02339454(DAT_02339290 | param_1 & 0xff);
  FUN_02339454(DAT_02339294 | param_2 & 0xffff);
  return 0;
}

