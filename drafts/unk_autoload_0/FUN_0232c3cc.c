// decomp: module=unk_autoload_0 addr=0x0232c3cc name=FUN_0232c3cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x3c (Ghidra's cache says 0x38 - it excludes this function's trailing literal pool), thumb
// triage: noise=2 statements=17
// verify:  python tools/match.py --c <file> --func FUN_0232c3cc --addr 0x0232c3cc --size 0x3c --module unk_autoload_0 --version 2.0/sp1


ushort * FUN_0232c3cc(void)

{
  int iVar1;
  ushort *in_r3;
  ushort *local_8 [2];
  
  local_8[0] = in_r3;
  iVar1 = FUN_023312a0(DAT_0232c404,local_8,0);
  if (iVar1 == 0) {
    return (ushort *)0x0;
  }
  FUN_023314cc(local_8[0],2);
  if ((*local_8[0] & 0x8000) == 0) {
    FUN_02331308(DAT_0232c404,local_8[0],1);
    return (ushort *)0x0;
  }
  return local_8[0];
}

