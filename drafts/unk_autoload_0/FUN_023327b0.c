// decomp: module=unk_autoload_0 addr=0x023327b0 name=FUN_023327b0
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=12  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023327b0 --addr 0x023327b0 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


uint FUN_023327b0(void)

{
  int iVar1;
  
  iVar1 = FUN_0233276c();
  if (iVar1 == 0) {
    return 0;
  }
  if (-1 < (int)((uint)*(byte *)(DAT_023327d8 + 5) << 0x1e)) {
    FUN_023327dc();
  }
  return (*(byte *)(DAT_023327d8 + 5) & 3) >> 1;
}

