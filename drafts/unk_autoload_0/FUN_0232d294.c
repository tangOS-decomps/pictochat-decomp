// decomp: module=unk_autoload_0 addr=0x0232d294 name=FUN_0232d294
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232d294 --addr 0x0232d294 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232d294(uint param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = DAT_0232d2c8;
  uVar1 = *DAT_0232d2c4;
  *DAT_0232d2c4 = 0;
  FUN_02330938(0x6e,iVar3,0);
  iVar3 = DAT_0232d2c8;
  *(uint *)(DAT_0232d2c8 + 8) = ~param_1 & *(uint *)(DAT_0232d2c8 + 8);
  FUN_02330998(0x6e,iVar3,0);
  uVar2 = *DAT_0232d2c4;
  *DAT_0232d2c4 = uVar1;
  return uVar2;
}

