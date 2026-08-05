// decomp: module=unk_autoload_0 addr=0x0232a480 name=FUN_0232a480
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232a480 --addr 0x0232a480 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232a480(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0232996c();
  if (iVar1 == 7) {
    uVar2 = FUN_02332080();
    *(undefined4 *)(DAT_0232a4c0 + 0x14) = 0;
    FUN_02331ef0(DAT_0232a4c4);
    FUN_02329d0c(0);
    iVar1 = DAT_0232a4c0;
    *(undefined4 *)(DAT_0232a4c0 + 0x30) = 1;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    FUN_02332094(uVar2);
    *(undefined4 *)(DAT_0232a4c0 + 0x40) = 1;
    FUN_0232b1c0();
  }
  return;
}

