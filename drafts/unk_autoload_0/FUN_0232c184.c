// decomp: module=unk_autoload_0 addr=0x0232c184 name=FUN_0232c184
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x4e - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=19
// verify:  python tools/match.py --c <file> --func FUN_0232c184 --addr 0x0232c184 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232c184(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  iVar1 = FUN_0232b834(DAT_0232c1d4);
  if (iVar1 == 0) {
    FUN_023374f0(&local_14,0,0x10);
    FUN_0232b7ec(DAT_0232c1d4,&local_14,0x10);
    iVar1 = FUN_0232cf84(DAT_0232c1d8,local_10,local_14,local_8,local_6,local_a,2);
    if ((iVar1 == 2) || (iVar1 == 7)) {
      *DAT_0232c1dc = 1;
    }
  }
  return;
}

