// decomp: module=unk_autoload_0 addr=0x02332274 name=FUN_02332274
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x1c (Ghidra's cache says 0x18 - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=13
// verify:  python tools/match.py --c <file> --func FUN_02332274 --addr 0x02332274 --size 0x1c --module unk_autoload_0 --version 2.0/sp1


void FUN_02332274(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  
  puVar1 = DAT_0233228c;
  pcVar2 = (code *)*DAT_0233228c;
  if (pcVar2 != (code *)0x0) {
    *DAT_0233228c = 0;
    (*pcVar2)(puVar1[1]);
  }
  FUN_02332290();
  return;
}

