// decomp: module=unk_autoload_0 addr=0x0232d3fc name=FUN_0232d3fc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x8c (Ghidra's cache says 0x78 - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=25
// verify:  python tools/match.py --c <file> --func FUN_0232d3fc --addr 0x0232d3fc --size 0x8c --module unk_autoload_0 --version 2.0/sp1


undefined2 FUN_0232d3fc(void)

{
  int iVar1;
  void *a0;
  
  iVar1 = FUN_0232d4b4();
  if (iVar1 == 0) {
    return 0;
  }
  if (*DAT_0232d474 == 0) {
    a0 = (void *)(uint)*(ushort *)(DAT_0232d474 + 2);
    FUN_02330a68(a0);
    if (a0 == (void *)0x0) {
      FUN_0232d4cc();
      *DAT_0232d474 = 1;
    }
  }
  else if ((*DAT_0232d474 == 1) && ((*DAT_0232d478 & 0x800000) != 0)) {
    if ((*DAT_0232d47c != *DAT_0232d480) && ((*DAT_0232d484 & 2) != 0)) {
      *(undefined2 *)((int)DAT_0232d474 + 10) = 1;
    }
    FUN_02330a54((void *)(uint)*(ushort *)(DAT_0232d474 + 2));
    *DAT_0232d474 = 0;
  }
  return *(undefined2 *)((int)DAT_0232d474 + 10);
}

