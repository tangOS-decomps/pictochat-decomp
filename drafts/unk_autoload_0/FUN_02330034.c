// decomp: module=unk_autoload_0 addr=0x02330034 name=FUN_02330034
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x6c (Ghidra's cache says 0x5e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_02330034 --addr 0x02330034 --size 0x6c --module unk_autoload_0 --version 2.0/sp1


void FUN_02330034(int param_1)

{
  FUN_02331374(DAT_02330094);
  if (*(int *)(DAT_02330098 + 4) != 0) {
    FUN_02331374(*(int *)(DAT_02330098 + 4) + DAT_0233009c);
  }
  if (*(int *)(param_1 + 0x118) << 0x1e < 0) {
    FUN_0232ef28(param_1);
  }
  if (*(int *)(param_1 + 0x118) << 0x1f < 0) {
    (**(code **)(param_1 + 0x178))(param_1);
  }
  FUN_023300a0(param_1);
  FUN_023313c8(DAT_02330094);
  if (*(int *)(DAT_02330098 + 4) != 0) {
    FUN_023313c8(*(int *)(DAT_02330098 + 4) + DAT_0233009c);
  }
  return;
}

