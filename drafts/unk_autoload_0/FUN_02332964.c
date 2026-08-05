// decomp: module=unk_autoload_0 addr=0x02332964 name=FUN_02332964
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x68 (Ghidra's cache says 0x64 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=31
// verify:  python tools/match.py --c <file> --func FUN_02332964 --addr 0x02332964 --size 0x68 --module unk_autoload_0 --version 2.0/sp1


void FUN_02332964(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_02332080();
  *DAT_023329c8 = param_1;
  iVar2 = FUN_0233276c();
  if (iVar2 != 0) {
    if (param_1 == 0) {
      iVar2 = 5;
    }
    else {
      iVar2 = 1;
    }
    FUN_02331804(0xf000,iVar2 << 0xc);
    if (param_1 == 0) {
      FUN_023317c4(8);
      FUN_023317e4(8);
      FUN_02331818(8);
    }
    else {
      FUN_02331498();
      FUN_02331528();
      FUN_023317d4(8);
      FUN_023317f4(8);
      FUN_02331828(8);
    }
  }
  FUN_02332094(uVar1);
  return;
}

