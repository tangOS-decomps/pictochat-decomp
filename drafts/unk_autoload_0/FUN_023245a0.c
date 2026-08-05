// decomp: module=unk_autoload_0 addr=0x023245a0 name=FUN_023245a0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x58 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=23
// verify:  python tools/match.py --c <file> --func FUN_023245a0 --addr 0x023245a0 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


bool FUN_023245a0(void)

{
  int iVar1;
  int *piVar2;
  int c;
  undefined1 auStack_108 [256];
  
  FUN_02322004();
  FUN_02321e70();
  FUN_02328ea8();
  FUN_02327e80();
  FUN_02326c9c();
  iVar1 = FUN_0232797c();
  if (iVar1 != 0) {
    piVar2 = FUN_023260bc();
    c = FUN_02322820();
    FUN_02329634((int)auStack_108,*piVar2,c);
    FUN_02326488(auStack_108,0x11);
    FUN_02328e74(1);
    *DAT_023245f8 = 0;
    FUN_02320978(0x28);
  }
  return iVar1 != 0;
}

