// decomp: module=unk_autoload_0 addr=0x023299ac name=FUN_023299ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x52, thumb
// triage: noise=2 statements=26
// verify:  python tools/match.py --c <file> --func FUN_023299ac --addr 0x023299ac --size 0x52 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_023299ac(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0232996c();
  if ((iVar1 == 0) || (iVar1 = FUN_0232996c(), 0xb < iVar1)) {
    return 5;
  }
  iVar1 = FUN_0232996c();
  if ((iVar1 != 7) && (iVar1 = FUN_0232996c(), iVar1 != 6)) {
    return 4;
  }
  uVar2 = FUN_0232ca3c();
  switch(uVar2) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  default:
    return 5;
  }
}

