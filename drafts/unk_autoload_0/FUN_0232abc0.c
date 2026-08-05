// decomp: module=unk_autoload_0 addr=0x0232abc0 name=FUN_0232abc0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x5c (Ghidra's cache says 0x54 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=23
// verify:  python tools/match.py --c <file> --func FUN_0232abc0 --addr 0x0232abc0 --size 0x5c --module unk_autoload_0 --version 2.0/sp1


void FUN_0232abc0(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0232ac14;
  *(short *)(DAT_0232ac14 + 6) = *(short *)(DAT_0232ac14 + 6) + 1;
  *(undefined4 *)(iVar1 + 0x38) = 1;
  iVar1 = FUN_0232996c();
  if (iVar1 == 4) {
    FUN_0232aabc();
    FUN_02329bd8(8);
    iVar1 = DAT_0232ac14;
    *(undefined2 *)(DAT_0232ac14 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    FUN_0232c0c4();
    FUN_0232aa0c();
    iVar1 = DAT_0232ac14;
    *(undefined4 *)(DAT_0232ac14 + 0x1c) = 1;
    FUN_0232a51c(DAT_0232ac18,*(ushort *)(iVar1 + 6) & 0xff);
    FUN_0232b064();
  }
  FUN_0232a648(*(undefined2 *)(param_1 + 0x10),param_1 + 10);
  return;
}

