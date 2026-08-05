// decomp: module=unk_autoload_0 addr=0x02339298 name=FUN_02339298
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x1e - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=11
// verify:  python tools/match.py --c <file> --func FUN_02339298 --addr 0x02339298 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


int FUN_02339298(void)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_02339250();
  if (iVar1 == 0) {
    (*(code *)*DAT_023392bc)();
    iVar1 = local_c;
  }
  return iVar1;
}

