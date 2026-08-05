// decomp: module=unk_autoload_0 addr=0x02329228 name=FUN_02329228
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x48, thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02329228 --addr 0x02329228 --size 0x48 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329228(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 == 6) || (iVar1 = FUN_0232996c(), iVar1 == 7)) {
    uVar2 = FUN_0232b95c();
    return uVar2;
  }
  iVar1 = FUN_0232996c();
  if (((iVar1 != 3) &&
      (((iVar1 = FUN_0232996c(), iVar1 != 4 && (iVar1 = FUN_0232996c(), iVar1 != 5)) &&
       (iVar1 = FUN_0232996c(), iVar1 != 8)))) && (iVar1 = FUN_0232996c(), iVar1 != 2)) {
    return 0;
  }
  return 1;
}

