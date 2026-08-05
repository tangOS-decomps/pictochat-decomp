// decomp: module=unk_autoload_0 addr=0x023328e0 name=FUN_023328e0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_023328e0 --addr 0x023328e0 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_023328e0(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = DAT_02332918;
  while( true ) {
    uVar2 = FUN_02332080();
    param_2[1] = uVar2;
    uVar2 = FUN_02330aa0(uVar1);
    *param_2 = uVar2 & 0x40;
    if (((uVar2 & 0x40) != 0) || (iVar3 = FUN_02330a1c(param_1), iVar3 == 0)) break;
    FUN_02332094(param_2[1]);
    FUN_02332d10(1);
  }
  return;
}

