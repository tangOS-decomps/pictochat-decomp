// decomp: module=unk_autoload_0 addr=0x023227e0 name=FUN_023227e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=11
// verify:  python tools/match.py --c <file> --func FUN_023227e0 --addr 0x023227e0 --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined2 * FUN_023227e0(undefined2 *param_1,int param_2)

{
  undefined2 *puVar1;
  
  if (param_2 < 10) {
    *param_1 = *(undefined2 *)(DAT_023227fc + param_2 * 2);
    param_1[1] = 0;
    return param_1 + 1;
  }
  puVar1 = (undefined2 *)FUN_023227a8();
  return puVar1;
}

