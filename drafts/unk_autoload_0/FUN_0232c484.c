// decomp: module=unk_autoload_0 addr=0x0232c484 name=FUN_0232c484
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x46 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232c484 --addr 0x0232c484 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232c484(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0232c3cc();
  if (iVar1 == 0) {
    return 8;
  }
  FUN_02337584(param_1,iVar1,param_2);
  FUN_023314e8(iVar1,param_2);
  iVar2 = FUN_0233831c(10,iVar1,0);
  FUN_02331244(DAT_0232c4cc,iVar1,1);
  if (iVar2 < 0) {
    return 8;
  }
  return 2;
}

