// decomp: module=unk_autoload_0 addr=0x0232ed58 name=FUN_0232ed58
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x36 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=11  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232ed58 --addr 0x0232ed58 --size 0x3c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232ed58(int param_1)

{
  int *a;
  int b;
  
  b = FUN_0232e178(DAT_0232ed90,0);
  a = DAT_0232ed90;
  for (; (b != 0 && (*(byte *)(b + 0x3d) <= *(byte *)(param_1 + 0x3d))); b = FUN_0232e178(a,b)) {
  }
  FUN_0232e104(DAT_0232ed90,b,param_1);
  return;
}

