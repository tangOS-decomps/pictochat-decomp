// decomp: module=unk_autoload_0 addr=0x023278ac name=FUN_023278ac
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x34 (Ghidra's cache says 0x2c - it excludes this function's trailing literal pool), thumb
// triage: noise=3 statements=14
// verify:  python tools/match.py --c <file> --func FUN_023278ac --addr 0x023278ac --size 0x34 --module unk_autoload_0 --version 2.0/sp1


void FUN_023278ac(int param_1)

{
  *(undefined4 *)(PTR_DAT_023278d8 + 4) = 0;
  FUN_0232fdec(PTR_DAT_023278dc,0,param_1);
  if (param_1 == 0xd) {
    *(undefined4 *)(PTR_DAT_023278d8 + 8) = 2;
    return;
  }
  if (param_1 != 0xe) {
    return;
  }
  *(undefined4 *)(PTR_DAT_023278d8 + 8) = 10;
  return;
}

