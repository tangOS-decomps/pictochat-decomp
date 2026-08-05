// decomp: module=unk_autoload_0 addr=0x02337e38 name=FUN_02337e38
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x16 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=15
// verify:  python tools/match.py --c <file> --func FUN_02337e38 --addr 0x02337e38 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02337e38(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = DAT_02337e50;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined1 *)(puVar2 + 2) = 0;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 3;
  } while (iVar1 < 8);
  return;
}

