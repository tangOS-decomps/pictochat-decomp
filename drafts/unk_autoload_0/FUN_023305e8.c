// decomp: module=unk_autoload_0 addr=0x023305e8 name=FUN_023305e8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x74 (Ghidra's cache says 0x6c - it excludes this function's trailing literal pool), arm
// triage: noise=1 statements=19
// verify:  python tools/match.py --c <file> --func FUN_023305e8 --addr 0x023305e8 --size 0x74 --module unk_autoload_0 --version 2.0/sp1


void FUN_023305e8(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  
  FUN_02332080();
  if (param_1 != 0) {
    *(uint *)(DAT_02330654 + 0x3ff8) = *(uint *)(DAT_02330654 + 0x3ff8) & ~param_2;
  }
  FUN_02332094();
  uVar1 = DAT_02330658;
  if ((param_2 & *(uint *)(DAT_02330654 + 0x3ff8)) != 0) {
    return;
  }
  puVar2 = (uint *)(DAT_02330654 + 0x3ff8);
  do {
    FUN_02330f38(uVar1);
  } while ((param_2 & *puVar2) == 0);
  return;
}

