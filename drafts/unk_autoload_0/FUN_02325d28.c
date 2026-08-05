// decomp: module=unk_autoload_0 addr=0x02325d28 name=FUN_02325d28
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x28 (Ghidra's cache says 0x24 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02325d28 --addr 0x02325d28 --size 0x28 --module unk_autoload_0 --version 2.0/sp1


void FUN_02325d28(void)

{
  void *pvVar1;
  int extraout_r1;
  undefined1 auStack_10 [16];
  
  FUN_02322be8(auStack_10);
  pvVar1 = FUN_0232254c();
  FUN_02336018(*(undefined4 *)((int)pvVar1 + 4),0x14);
  if (extraout_r1 == 0) {
    *(undefined4 *)(DAT_02325d4c + 8) = 1;
  }
  return;
}

