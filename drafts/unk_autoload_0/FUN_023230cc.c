// decomp: module=unk_autoload_0 addr=0x023230cc name=FUN_023230cc
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x14 (Ghidra's cache says 0xc - it excludes this function's trailing literal pool), thumb
// triage: noise=4 statements=7
// verify:  python tools/match.py --c <file> --func FUN_023230cc --addr 0x023230cc --size 0x14 --module unk_autoload_0 --version 2.0/sp1


void FUN_023230cc(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x023230d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_023230dc)(*(undefined4 *)(DAT_023230d8 + 4),param_1,4);
  return;
}

