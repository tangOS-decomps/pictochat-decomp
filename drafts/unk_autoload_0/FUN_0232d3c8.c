// decomp: module=unk_autoload_0 addr=0x0232d3c8 name=FUN_0232d3c8
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=14  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232d3c8 --addr 0x0232d3c8 --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232d3c8(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0232d3f8;
  uVar2 = *DAT_0232d3f8;
  while ((uVar2 & 0x4000) == 0) {
    FUN_02332d10(0x1000);
    uVar2 = *puVar1;
  }
  FUN_0232d2cc();
  FUN_0232d260(0x8000);
  return;
}

