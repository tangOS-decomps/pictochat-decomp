// decomp: module=unk_autoload_0 addr=0x023226d4 name=FUN_023226d4
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x38 (Ghidra's cache says 0x2e - it excludes this function's trailing literal pool), thumb
// triage: noise=0 statements=7  <- clean draft, start here
// verify:  python tools/match.py --c <file> --func FUN_023226d4 --addr 0x023226d4 --size 0x38 --module unk_autoload_0 --version 2.0/sp1


uint FUN_023226d4(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_02322708 >> 0xc &
          ((uint)(*DAT_02322704 | *DAT_02322708) ^ (uint)DAT_02322708 >> 0xc);
  return uVar1 & 0xffff & ~((uVar1 & 0x40) << 1) & ~((int)(uVar1 & 0x20) >> 1);
}

