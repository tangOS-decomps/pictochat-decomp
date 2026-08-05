// decomp: module=unk_autoload_0 addr=0x0232d260 name=FUN_0232d260
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=16
// verify:  python tools/match.py --c <file> --func FUN_0232d260 --addr 0x0232d260 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232d260(uint param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = DAT_0232d290;
  uVar1 = *DAT_0232d28c;
  *DAT_0232d28c = 0;
  FUN_02330938(0x6e,iVar3,0);
  iVar3 = DAT_0232d290;
  *(uint *)(DAT_0232d290 + 8) = *(uint *)(DAT_0232d290 + 8) | param_1;
  FUN_02330998(0x6e,iVar3,0);
  uVar2 = *DAT_0232d28c;
  *DAT_0232d28c = uVar1;
  return uVar2;
}

