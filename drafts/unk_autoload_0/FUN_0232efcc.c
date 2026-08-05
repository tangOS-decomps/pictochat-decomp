// decomp: module=unk_autoload_0 addr=0x0232efcc name=FUN_0232efcc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x20 (Ghidra's cache says 0x1c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232efcc --addr 0x0232efcc --size 0x20 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232efcc(void *param_1)

{
  FUN_0232e8a4(*(int *)((int)param_1 + 0x48));
  FUN_0232e13c(DAT_0232efe8,param_1);
  *(uint *)((int)param_1 + 0x2c) = *(uint *)((int)param_1 + 0x2c) & 0xfffffffe;
  return;
}

