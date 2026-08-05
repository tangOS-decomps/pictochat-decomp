// decomp: module=unk_autoload_0 addr=0x02330ef4 name=FUN_02330ef4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x44 (Ghidra's cache says 0x3e - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02330ef4 --addr 0x02330ef4 --size 0x44 --module unk_autoload_0 --version 2.0/sp1


void FUN_02330ef4(void)

{
  int iVar1;
  
  iVar1 = **(int **)(DAT_02330f34 + 8);
  FUN_0233108c();
  FUN_02331400(iVar1);
  if (*(int *)(iVar1 + 0x78) != 0) {
    FUN_02330b8c(*(int *)(iVar1 + 0x78),iVar1);
  }
  FUN_02330c20(iVar1);
  *(undefined4 *)(iVar1 + 100) = 2;
  FUN_02330f6c(iVar1 + 0x9c);
  FUN_023310b0();
  FUN_02330fe8();
  FUN_02332274();
  return;
}

