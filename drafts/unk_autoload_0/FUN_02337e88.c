// decomp: module=unk_autoload_0 addr=0x02337e88 name=FUN_02337e88
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x2c (Ghidra's cache says 0x26 - it excludes this function's trailing literal pool), thumb
// triage: noise=5 statements=10
// verify:  python tools/match.py --c <file> --func FUN_02337e88 --addr 0x02337e88 --size 0x2c --module unk_autoload_0 --version 2.0/sp1


void FUN_02337e88(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(DAT_02337eb0 + (param_1 & 0xff) * 0xc);
  if ((((int)param_1 >> 8 & 0xffU) == (uint)*(byte *)(puVar1 + 2)) &&
     ((code *)*puVar1 != (code *)0x0)) {
    (*(code *)*puVar1)(puVar1[1]);
  }
  return;
}

