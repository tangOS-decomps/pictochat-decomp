// decomp: module=arm7 addr=0x022e2eac name=FUN_022e2eac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), arm
// triage: noise=5 statements=8
// verify:  python tools/match.py --c <file> --func FUN_022e2eac --addr 0x022e2eac --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022e2eac(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  thunk_EXT_FUN_03801c44(*(undefined4 *)(*DAT_022e2ef8 + 0x314));
  FUN_022e2df4();
  thunk_EXT_FUN_03802a68(param_1,param_2,param_3);
  thunk_EXT_FUN_03801c8c(*(undefined4 *)(*DAT_022e2ef8 + 0x314));
  return;
}

