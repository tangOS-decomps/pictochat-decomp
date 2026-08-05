// decomp: module=unk_autoload_0 addr=0x02331ffc name=FUN_02331ffc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48 (Ghidra's cache says 0x42 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=23
// verify:  python tools/match.py --c <file> --func FUN_02331ffc --addr 0x02331ffc --size 0x48 --module unk_autoload_0 --version 2.0/sp1


void FUN_02331ffc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    uVar1 = FUN_02332080();
    iVar2 = *(int *)(DAT_02332040 + 4);
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0x18);
      while( true ) {
        if (*(int *)(iVar2 + 8) == param_1) {
          FUN_02331ef0();
        }
        if (iVar3 == 0) break;
        iVar2 = iVar3;
        iVar3 = *(int *)(iVar3 + 0x18);
      }
    }
    FUN_02332094(uVar1);
  }
  return;
}

