// decomp: module=unk_autoload_0 addr=0x02322d70 name=FUN_02322d70
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x18 (Ghidra's cache says 0x12 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02322d70 --addr 0x02322d70 --size 0x18 --module unk_autoload_0 --version 2.0/sp1


void FUN_02322d70(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_02322d84;
  *(undefined4 *)(DAT_02322d84 + 4) = 0;
  *(uint *)(iVar1 + 0xc) = param_1 + 8U & 0xf;
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}

