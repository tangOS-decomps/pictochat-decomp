// decomp: module=unk_autoload_0 addr=0x0232a428 name=FUN_0232a428
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x58 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=25
// verify:  python tools/match.py --c <file> --func FUN_0232a428 --addr 0x0232a428 --size 0x58 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a428(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_02332080();
  *(undefined4 *)(DAT_0232a478 + 0x14) = 0;
  FUN_02331ef0(DAT_0232a47c);
  FUN_02329d0c(0);
  iVar2 = FUN_0232996c();
  iVar3 = DAT_0232a478;
  if (iVar2 == 7) {
    *(undefined4 *)(DAT_0232a478 + 0x30) = 1;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
  }
  else {
    iVar3 = FUN_0232996c();
    if ((iVar3 != 0) && (iVar3 = FUN_0232996c(), iVar3 != 1)) {
      FUN_02329734();
    }
  }
  FUN_02332094(uVar1);
  FUN_023298d8(0);
  return;
}

