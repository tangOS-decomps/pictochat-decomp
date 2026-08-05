// decomp: module=unk_autoload_0 addr=0x02336200 name=FUN_02336200
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=9
// verify:  python tools/match.py --c <file> --func FUN_02336200 --addr 0x02336200 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02336200(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = DAT_02336218; (puVar1 != (undefined4 *)0x0 && ((code *)*puVar1 != (code *)0x0));
      puVar1 = puVar1 + 1) {
    (*(code *)*puVar1)();
  }
  return;
}

