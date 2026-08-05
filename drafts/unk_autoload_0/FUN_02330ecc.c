// decomp: module=unk_autoload_0 addr=0x02330ecc name=FUN_02330ecc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=12
// verify:  python tools/match.py --c <file> --func FUN_02330ecc --addr 0x02330ecc --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330ecc(void)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(**(int **)(DAT_02330ef0 + 8) + 0xb4);
  if (pcVar1 != (code *)0x0) {
    *(undefined4 *)(**(int **)(DAT_02330ef0 + 8) + 0xb4) = 0;
    (*pcVar1)();
    FUN_02332080();
  }
  FUN_02330ef4();
  return;
}

