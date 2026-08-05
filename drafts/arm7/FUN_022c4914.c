// decomp: module=arm7 addr=0x022c4914 name=FUN_022c4914
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=10
// verify:  python tools/match.py --c <file> --func FUN_022c4914 --addr 0x022c4914 --size 0x34 --module arm7 --version 2.0/sp1


void FUN_022c4914(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7f00) == 0x1000) {
    *DAT_022c4944 = 1;
  }
  else {
    FUN_022c6e94();
  }
  return;
}

