// decomp: module=arm7 addr=0x022c4b10 name=FUN_022c4b10
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x48 - it excludes this function's trailing literal pool), arm
// triage: noise=3 statements=12
// verify:  python tools/match.py --c <file> --func FUN_022c4b10 --addr 0x022c4b10 --size 0x50 --module arm7 --version 2.0/sp1


void FUN_022c4b10(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_022c4b5c;
  uVar1 = DAT_022c4b58;
  while (iVar3 = FUN_022c4a9c(param_1,uVar1,uVar2,1), 0 < iVar3) {
    thunk_EXT_FUN_037fb7b8(0x400);
  }
  return;
}

