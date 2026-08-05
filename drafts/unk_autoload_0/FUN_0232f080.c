// decomp: module=unk_autoload_0 addr=0x0232f080 name=FUN_0232f080
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x50 (Ghidra's cache says 0x4c - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=22  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_0232f080 --addr 0x0232f080 --size 0x50 --module unk_autoload_0 --version 2.0/sp1


void FUN_0232f080(void)

{
  int *piVar1;
  int iVar2;
  int *a;
  
  piVar1 = DAT_0232f0cc;
  if ((*DAT_0232f0cc != 0) && (DAT_0232f0cc[1] == 0)) {
    a = DAT_0232f0cc + 0xf;
    FUN_023305c8(a);
    if ((piVar1[0x13] != 0) && (iVar2 = FUN_023305d8(a), iVar2 != 0)) {
      FUN_0232f304();
      return;
    }
    iVar2 = FUN_023305a8(a);
    iVar2 = iVar2 >> 8;
    if (iVar2 != piVar1[0x14]) {
      FUN_02337848(piVar1[9],iVar2,0);
      piVar1[0x14] = iVar2;
    }
  }
  return;
}

