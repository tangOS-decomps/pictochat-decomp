// decomp: module=unk_autoload_0 addr=0x02322be8 name=FUN_02322be8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02322be8 --addr 0x02322be8 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322be8(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_02322ba8();
  uVar1 = DAT_02322bfc[1];
  puVar2 = DAT_02322bfc + 2;
  *param_1 = *DAT_02322bfc;
  param_1[1] = uVar1;
  param_1[2] = *puVar2;
  return;
}

