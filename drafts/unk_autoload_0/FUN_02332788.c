// decomp: module=unk_autoload_0 addr=0x02332788 name=FUN_02332788
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1a - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02332788 --addr 0x02332788 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332788(void)

{
  undefined2 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = 0;
  FUN_02332d2e(local_8,DAT_023327a4,DAT_023327a8);
  uVar1 = FUN_02330aa4();
  *(undefined2 *)(DAT_023327ac + 6) = uVar1;
  return;
}

