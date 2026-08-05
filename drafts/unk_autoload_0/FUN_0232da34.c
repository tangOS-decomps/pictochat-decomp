// decomp: module=unk_autoload_0 addr=0x0232da34 name=FUN_0232da34
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232da34 --addr 0x0232da34 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


undefined8 FUN_0232da34(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3;
  FUN_02337424(DAT_0232da78,param_3,0x24);
  FUN_02337424(param_1,param_3 + 0x24,0x9c);
  FUN_02332d4e(param_3,param_2,param_2 + 0x40,DAT_0232da7c,param_1,param_2,iVar1);
  *param_2 = DAT_0232da80;
  FUN_0232da88(param_2,param_3);
  FUN_02332d42(param_3,param_2,DAT_0232da84);
  return CONCAT44(param_2,param_1);
}

