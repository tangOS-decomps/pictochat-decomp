// decomp: module=unk_autoload_0 addr=0x0232e8ec name=FUN_0232e8ec
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x56 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232e8ec --addr 0x0232e8ec --size 0x60 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232e8ec(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0232f84c(param_2,param_3 + 0x14,DAT_0232e944,0,0,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar2 = FUN_0232f780(iVar1 + 0x14,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(iVar1 + 8) = iVar2;
  FUN_0232e0ac(DAT_0232e948 + param_1 * 0x24 + 0xc,iVar1);
  return 1;
}

