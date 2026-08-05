// decomp: module=unk_autoload_0 addr=0x0232c374 name=FUN_0232c374
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=23
// verify:  python tools/match.py --c <file> --func FUN_0232c374 --addr 0x0232c374 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


int FUN_0232c374(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_02332080();
  iVar3 = FUN_0232c4dc();
  if (iVar3 != 0) {
    FUN_02332094(uVar2);
    return 3;
  }
  iVar3 = FUN_0232c520(1,0);
  if (iVar3 == 0) {
    FUN_0232c820();
    FUN_023382ac(10,0);
    puVar1 = DAT_0232c3b8;
    *(undefined4 *)(DAT_0232c3b8 + 2) = 0;
    *puVar1 = 0;
    FUN_02332094(uVar2);
    iVar3 = 0;
  }
  return iVar3;
}

