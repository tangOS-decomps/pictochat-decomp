// decomp: module=unk_autoload_0 addr=0x0232e1f4 name=FUN_0232e1f4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232e1f4 --addr 0x0232e1f4 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232e1f4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[6] = param_3;
  iVar1 = DAT_0232e244;
  param_1[7] = param_4;
  param_1[8] = 0;
  param_1[8] = *(ushort *)(&stack0x00000008 + iVar1) & 0xff;
  FUN_0232e084(param_1 + 3,4);
  if (*DAT_0232e248 == 0) {
    FUN_0232e084(DAT_0232e24c,4);
    *DAT_0232e248 = 1;
  }
  uVar2 = FUN_0232e1d8(param_1);
  FUN_0232e0ac(uVar2,param_1);
  return;
}

