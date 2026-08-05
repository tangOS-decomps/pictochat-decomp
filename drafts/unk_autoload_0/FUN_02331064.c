// decomp: module=unk_autoload_0 addr=0x02331064 name=FUN_02331064
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02331064 --addr 0x02331064 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02331064(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_02332080();
  uVar1 = *(undefined4 *)(DAT_0233107c + 0x28);
  *(undefined4 *)(DAT_0233107c + 0x28) = param_1;
  FUN_02332094();
  return uVar1;
}

