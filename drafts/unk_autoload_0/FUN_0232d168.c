// decomp: module=unk_autoload_0 addr=0x0232d168 name=FUN_0232d168
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0xcc (Ghidra's cache says 0xae - it excludes this function's trailing literal pool), thumb
// triage: noise=7 statements=42
// verify:  python tools/match.py --c <file> --func FUN_0232d168 --addr 0x0232d168 --size 0xcc --module unk_autoload_0 --version 2.0/sp1


undefined4 FUN_0232d168(void)

{
  undefined4 uVar1;
  
  FUN_0232d398();
  switch(*(undefined4 *)(DAT_0232d228 + 0x20)) {
  case 2:
    FUN_0232d32c();
    FUN_0232d36c();
    FUN_0232d260(0x20000000);
    *(undefined4 *)(DAT_0232d228 + 0x20) = 3;
    break;
  case 3:
    *(undefined4 *)(DAT_0232d228 + 0x20) = 8;
    break;
  case 6:
    if ((*(uint *)(DAT_0232d228 + 0x30) & 0x1000) != 0) {
      FUN_0232d260(0x400);
      FUN_0233746c(0,0x2000000,0x300000);
      FUN_0233146c();
      FUN_0232d388(8);
      *(undefined4 *)(DAT_0232d228 + 0x20) = 8;
    }
    break;
  case 8:
    if ((*(uint *)(DAT_0232d228 + 0x30) & 0x8000000) != 0) {
      uVar1 = 2;
      if ((*(uint *)(DAT_0232d228 + 0x30) & 0x80) == 0) {
        FUN_02336310(0);
      }
      else {
        (**(code **)*DAT_0232d22c)();
        uVar1 = 3;
      }
      FUN_0232d388(9);
      *DAT_0232d230 = 3;
      FUN_0232d488();
      FUN_0232d294(DAT_0232d234);
      return uVar1;
    }
  }
  return 0;
}

