// decomp: module=unk_autoload_0 addr=0x0232ee64 name=FUN_0232ee64
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=12
// verify:  python tools/match.py --c <file> --func FUN_0232ee64 --addr 0x0232ee64 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ee64(void *param_1)

{
  if (*(int ***)((int)param_1 + 8) != (int **)0x0) {
    FUN_0232f7cc(*(int ***)((int)param_1 + 8));
    if (*(int *)((int)param_1 + 0xc) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0xc) + 8) = 0;
      return;
    }
    FUN_0232e13c((undefined4 *)(DAT_0232ee94 + *(int *)((int)param_1 + 0x10) * 0x24 + 0xc),param_1);
  }
  return;
}

