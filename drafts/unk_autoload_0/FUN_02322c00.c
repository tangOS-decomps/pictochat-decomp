// decomp: module=unk_autoload_0 addr=0x02322c00 name=FUN_02322c00
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x14 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=16
// verify:  python tools/match.py --c <file> --func FUN_02322c00 --addr 0x02322c00 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322c00(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_02322ba8();
  puVar1 = DAT_02322c14;
  uVar2 = DAT_02322c14[1];
  puVar3 = DAT_02322c14 + 2;
  *param_1 = *DAT_02322c14;
  param_1[1] = uVar2;
  uVar2 = puVar1[3];
  param_1[2] = *puVar3;
  param_1[3] = uVar2;
  return;
}

