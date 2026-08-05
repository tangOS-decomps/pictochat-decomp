// decomp: module=unk_autoload_0 addr=0x023292e4 name=FUN_023292e4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x54 (Ghidra's cache says 0x50 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=23
// verify:  python tools/match.py --c <file> --func FUN_023292e4 --addr 0x023292e4 --size 0x54 --module unk_autoload_0 --version 2.0/sp1


void FUN_023292e4(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int b;
  undefined1 auStack_118 [4];
  uint local_114;
  uint local_110;
  undefined1 auStack_108 [256];
  
  puVar1 = FUN_023260bc();
  uVar2 = FUN_02322820();
  FUN_02329628(auStack_108,*puVar1,uVar2);
  FUN_02326488(auStack_108,0x10);
  FUN_02322c00(auStack_118);
  if (local_114 == *DAT_02329334) {
    if (local_110 == DAT_02329334[1]) {
      b = FUN_02322820();
      FUN_02329640((int)auStack_108,b);
      FUN_02326488(auStack_108,0x12);
    }
  }
  return;
}

