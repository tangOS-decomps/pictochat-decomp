// decomp: module=unk_autoload_0 addr=0x02329a5c name=FUN_02329a5c
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x30 (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=1 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02329a5c --addr 0x02329a5c --size 0x30 --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_02329a5c(void)

{
  int b;
  ushort *puVar1;
  int a;
  
  puVar1 = DAT_02329a88;
  b = DAT_02329a84;
  do {
    a = *(int *)(puVar1 + 2);
    FUN_0232ca9c(a,b,(uint)*puVar1);
  } while (a == 4);
  if (a != 2) {
    FUN_02329bd8(0);
    return 0;
  }
  return 1;
}

