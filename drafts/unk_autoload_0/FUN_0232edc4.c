// decomp: module=unk_autoload_0 addr=0x0232edc4 name=FUN_0232edc4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x4c (Ghidra's cache says 0x44 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=16  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232edc4 --addr 0x0232edc4 --size 0x4c --module unk_autoload_0 --version 2.0/sp1


void * FUN_0232edc4(int param_1)

{
  void *obj;
  
  obj = (void *)FUN_0232e178(DAT_0232ee08,0);
  if (obj == (void *)0x0) {
    obj = (void *)FUN_0232e178(DAT_0232ee0c,0);
    if (param_1 < (int)(uint)*(byte *)((int)obj + 0x3d)) {
      return (void *)0x0;
    }
    FUN_0232ed94((int)obj);
  }
  FUN_0232e13c(DAT_0232ee08,obj);
  *(char *)((int)obj + 0x3d) = (char)param_1;
  FUN_0232ed58(obj);
  return obj;
}

