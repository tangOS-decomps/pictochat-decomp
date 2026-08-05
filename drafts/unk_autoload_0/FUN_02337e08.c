// decomp: module=unk_autoload_0 addr=0x02337e08 name=FUN_02337e08
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x2a - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=18
// verify:  python tools/match.py --c <file> --func FUN_02337e08 --addr 0x02337e08 --size 0x30 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02337e08(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_02331218();
  if (iVar2 == 0) {
    return 1;
  }
  FUN_02332080();
  piVar1 = DAT_02337e34;
  *DAT_02337e34 = 0x10;
  iVar2 = *piVar1;
  FUN_02332094();
  if (iVar2 != 0) {
    return 1;
  }
  return 0;
}

