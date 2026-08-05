// decomp: module=unk_autoload_0 addr=0x0232a028 name=FUN_0232a028
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=6 statements=15
// verify:  python tools/match.py --c <file> --func FUN_0232a028 --addr 0x0232a028 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232a028(undefined4 param_1,int param_2)

{
  uchar uVar1;
  undefined4 uVar2;
  
  if (((*(int *)(*(int *)(DAT_0232a060 + 0x24) + 0x44) == 0) &&
      (uVar1 = FUN_02329dac(), *(uchar *)(param_2 + 4) == uVar1)) && (*(short *)(param_2 + 6) == 4))
  {
    if (*(code **)(DAT_0232a060 + 0x20) != (code *)0x0) {
      uVar2 = (**(code **)(DAT_0232a060 + 0x20))(param_1);
      return uVar2;
    }
    return 1;
  }
  return 0;
}

