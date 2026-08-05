// decomp: module=unk_autoload_0 addr=0x02321568 name=FUN_02321568
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x60 (Ghidra's cache says 0x4a - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02321568 --addr 0x02321568 --size 0x60 --module unk_autoload_0 --version 2.0/sp1


void FUN_02321568(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  switch(param_1) {
  case 1:
    FUN_023369fc(DAT_023215c4,0,0x600);
    return;
  case 2:
    FUN_02336a84(DAT_023215c4,0,0x600);
    return;
  case 4:
    FUN_02336b0c(DAT_023215c4,0,0x600);
    return;
  case 8:
    FUN_02336b94(DAT_023215c4,0,0x600,param_4,param_4);
  }
  return;
}

