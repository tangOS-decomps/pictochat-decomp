// decomp: module=unk_autoload_0 addr=0x023223f0 name=FUN_023223f0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_023223f0 --addr 0x023223f0 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


void FUN_023223f0(int param_1,int param_2)

{
  param_2 = param_2 * 0x54;
  if ((param_1 != *(int *)(PTR_DAT_02322414 + param_2)) ||
     (*(int *)(PTR_DAT_02322418 + param_2) != -1)) {
    *(int *)(PTR_DAT_02322418 + param_2) = param_1;
    *(undefined4 *)(PTR_DAT_0232241c + param_2) = 1;
  }
  return;
}

