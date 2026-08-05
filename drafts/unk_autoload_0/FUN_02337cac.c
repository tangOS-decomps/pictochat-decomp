// decomp: module=unk_autoload_0 addr=0x02337cac name=FUN_02337cac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02337cac --addr 0x02337cac --size 0x20 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02337cac(void)

{
  undefined4 uVar1;
  
  FUN_02332080();
  if (*(int *)(DAT_02337cc8 + 8) == 0) {
    uVar1 = *(undefined4 *)(DAT_02337cc8 + 4);
  }
  else {
    uVar1 = *(undefined4 *)(DAT_02337cc8 + 0x20);
  }
  FUN_02332094();
  return uVar1;
}

