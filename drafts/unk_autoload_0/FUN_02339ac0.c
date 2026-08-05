// decomp: module=unk_autoload_0 addr=0x02339ac0 name=FUN_02339ac0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x24 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02339ac0 --addr 0x02339ac0 --size 0x24 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02339ac0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_02339a48(param_1,param_2,DAT_02339adc,0,param_4);
  *(int *)(DAT_02339ae0 + 0x24) = iVar1;
  if (iVar1 == 0) {
    FUN_02339e54();
  }
  return *(undefined4 *)(DAT_02339ae0 + 0x24);
}

