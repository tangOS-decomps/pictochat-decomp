// decomp: module=unk_autoload_0 addr=0x02322db4 name=FUN_02322db4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x30 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_02322db4 --addr 0x02322db4 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_02322db4(void)

{
  undefined *puVar1;
  uint uVar2;
  int *p;
  
  puVar1 = PTR_DAT_02322dec;
  uVar2 = 0;
  *(undefined **)PTR_DAT_02322de8 = PTR_DAT_02322de4;
  do {
    p = (int *)(puVar1 + uVar2 * 0x30);
    FUN_0232e980(p);
    p[8] = 0;
    FUN_02322df0(p + 1,0x10);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return;
}

